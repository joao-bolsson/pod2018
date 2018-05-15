/**
 * Implements a Sorter.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 15 May.
 */

#include "Sorter.h"

Sorter::Sorter(int memory, int numFiles) {
    m = memory;

    if (numFiles < MAX_FILES && numFiles % 2 != 0) {
        throw runtime_error{"Quantidade de arquivos insuficiente"};
    }
    w = numFiles / 2;
}

void Sorter::clear(bool all) {
    string out;
    for (unsigned int i = 0; i < w; i++) {
        out = (alternate ? "output" : "input") + to_string(i) + ".txt";
        remove(out.c_str());

        if (all) {
            out = (alternate ? "input" : "output") + to_string(i) + ".txt";
            remove(out.c_str());
        }
    }
}

void Sorter::runParticions(const char *out, bool isEnd) {
    ofstream output;
    if (minHeap.empty()) {
        clear(false);

        output.open(out);

        string input;
        for (unsigned int i = 0; i < w; i++) {
            input = (alternate ? "input" : "output") + to_string(i) + ".txt";
            Node node = Node(input);
            minHeap.push_back(node);
        }
    } else {
        output.open(out, ios_base::app);

        for (auto &node : minHeap) {
            node.getElement();
        }
    }

    while(true) {
        auto min = min_element(minHeap.begin(), minHeap.end(), Comparator());
        if ((*min).element == partitionEnd) {
            break;
        }
        output << (*min).element << '\n';
        (*min).getElement();
    }
    if (isEnd) {
        output << partitionEnd << '\n';
    }

    output.close();
}

void Sorter::intercalation(string name) {
    alternate = true;
    string out;
    int n = p;

    while(n > 1) {
        for (unsigned int i = 0; i < n; i++) {
            out = (alternate ? "output" : "input") + to_string(i % w) + ".txt";
            runParticions(out.c_str(), true);
        }

        alternate = !alternate;

        minHeap.clear();
        n = ceil((float) n / w);
    }

    runParticions(name.c_str(), false);
    minHeap.clear();
    clear(true);
}

void Sorter::classificationHelper(vector<char> &part, int &nextFile, bool isEnd) {
    string out;
    // nome do arquivo
    out = "input" + to_string(nextFile) + ".txt";

    unsigned int size = part.size();
    // ordena com quicksort
    quickSort(part, 0, size - 1);

    // inicia escrita
    ofstream output(out, ios_base::app);

    for (unsigned int i = 0; i < size; i++) {
        output << part[i] << '\n';
    }

    if (isEnd) {
        output << partitionEnd << '\n';
    }

    output.close();

    if (nextFile == 0) {
        p++;
    }
    nextFile = (nextFile + 1) % w;
}

void Sorter::classification(string name) {
    ifstream input {name};
    if (input.is_open()) {
        vector<char> part;
        char current;
        int nextFile = 0, i = 0;

        bool isToContinue = true;
        p = 0;

        while(input >> current) {
            if (isalpha(current)) {
                isToContinue = true;
                part.push_back(current);
                i++;

                if (i == m) {
                    classificationHelper(part, nextFile, true);

                    i = 0;
                    part.clear();
                    isToContinue = false;
                }
            }
        }

        if (isToContinue) {
            classificationHelper(part, nextFile, false);
        }
    } else {
        throw  runtime_error {"Erro ao abrir arquivo"};
    }
}

int Sorter::partition(vector<char> &v, int min, int max) {
    // pivo sempre o ultimo elemento do particionamento
    char pivo = v[max];

    // posição do menor elemento
    int index = min - 1;

    for (int i = min; i <= max - 1; i++) {
        if (v[i] <= pivo) {
            index++;
            swap(v[index], v[i]);
        }
    }
    swap(v[++index], v[max]);
    return index;
}

void Sorter::quickSort(vector<char> &v, int min, int max) {
    if (min < max) {
        int p = partition(v, min, max);
        quickSort(v, min, p - 1);
        quickSort(v, p + 1, max);
    }
}
