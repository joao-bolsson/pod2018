#include <iostream>
#include "Sorter.h"

using namespace std;
int main(int argc, char **argv) {
    try {
        if (argc == 5) {
            Sorter sorter = Sorter(stoi(argv[1]), stoi(argv[2]));

            sorter.classification(argv[3]);
            sorter.intercalation(argv[4]);
        }
    } catch (exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
    return 0;
}