/**
 * Defines a Node.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 15 May.
 */

#ifndef T1_NODE_H
#define T1_NODE_H

#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Node {
private:
    bool read = true;
    string filePath;
    int count = 0, lenght = -1;

public:
    char element = '|';

    /**
     * Default construct.
     * @param filePath File path.
     */
    Node(string filePath);

    /**
     * Open the file in the correct position.
     */
    void getElement();
};


#endif //T1_NODE_H
