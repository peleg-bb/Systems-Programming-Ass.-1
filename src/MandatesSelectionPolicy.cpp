#include "SelectionPolicy.h"

MandatesSelectionPolicy::MandatesSelectionPolicy() {}
MandatesSelectionPolicy::~MandatesSelectionPolicy() {}
int MandatesSelectionPolicy::Select(std::vector<std::vector<int>> edges, int myIndex) {
    int bestMandates = 0;
    int bestIndex = 0;
    for (int i = 0; i < (int)edges.size(); i++) {
        if (edges[myIndex][i] > bestMandates) {
            bestMandates = edges[myIndex][i];
            bestIndex = i;
        }
    }
    return bestIndex;
}