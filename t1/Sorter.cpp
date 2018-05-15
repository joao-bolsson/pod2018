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
