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
