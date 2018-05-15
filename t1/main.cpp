#include <iostream>
#include "Sorter.h"

using namespace std;
int main() {
    int mem = 3, files = 5;
    string in = "/home/joao/pod/t1/entrada.txt";
    string out = "/home/joao/pod/t1/saida.txt";
    try {
        Sorter sorter = Sorter(mem, files);

        sorter.classification(in);
        sorter.intercalation(out);
    } catch (exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
    return 0;
}