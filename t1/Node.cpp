/**
 * Implements a Node.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 15 May.
 */

#include "Node.h"

void Node::getElement() {
    if (read) {
        ifstream file {filePath};
        if (lenght < 0) {
            file.seekg(0, file.end);
            lenght = file.tellg();
        }
        file.seekg(count, file.beg);

        if (count < lenght) {
            file >> element;
            count += 2;
        } else {
            element = '|';
            read = false;
        }

        file.close();
    } else {
        element = '|';
    }
}

Node::Node(string filePath) {
    this->filePath = filePath;
    getElement();
}


