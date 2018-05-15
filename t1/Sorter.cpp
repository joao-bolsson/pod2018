/**
 * Implements a Sorter.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 15 May.
 */

#include "Sorter.h"

Sorter::Sorter(int memory, int numFiles) {
    m = memory;

    if (numFiles < MAX_FILES) {
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
