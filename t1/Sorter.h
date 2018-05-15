/**
 * Defines a Sorter.
 *
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @since 2018, 15 May.
 */

#ifndef T1_SORTER_H
#define T1_SORTER_H

#include <vector>
#include <algorithm>

#include "Node.h"

using namespace std;

/**
 * Max number of opened files. Must be an odd value.
 */
const char MAX_FILES = 5;

struct Comparator {
    bool operator() (const Node &n1, const Node &n2){
        return int(n1.element) < int(n2.element);
    }
};

class Sorter {

private:
    int m; //read memory
    int w; // F/2 ways to the balanced merge of N(F/2) ways
    int p; // partitions by file

    char partitionEnd = '|'; // the end of a partition in the file
    bool alternate; // alternates between input and output files
    vector<Node> minHeap; // represents a minimum heap

    int partition(vector<char> &v, int min, int max);
    void quickSort(vector<char> &v, int min, int max);
    void classificationHelper(vector<char> &part, int &nextFile, bool isEnd);
    void clear(bool all);
    void runParticions(const char* out, bool isEnd);

public:
    /**
     * Default construct.
     * @param memory Read memory.
     * @param numFiles Number of files.
     */
    Sorter(int memory, int numFiles);

    /**
     * Do the intercalation.
     * @param name Referenced name to intercalete.
     */
    void intercalation(string name);

    /**
     * Do the intern classification.
     * @param name Referenced name to classify.
     */
    void classification(string name);
};


#endif //T1_SORTER_H
