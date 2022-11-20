#include "SelectionPolicy.h"

MandatesSelectionPolicy::MandatesSelectionPolicy() {}
MandatesSelectionPolicy::~MandatesSelectionPolicy() {}
int MandatesSelectionPolicy::Select(std::vector<std::vector<int>> edges, int myIndex, vector<int> irrelevent) {
    int bestMandates = 0;
    int bestIndex = 0;
    for (int i = 0; i < (int)edges.size(); i++) {
        // check if i is irrelevent (meaning party i has been offered a place in the coalition)
        bool isIrrelevent = false;
        for (int j = 0; j < (int)irrelevent.size(); j++) {
            if (i == irrelevent[j]) {
                isIrrelevent = true;
                break;
            }
        }
        if (edges[myIndex][i] > bestMandates&&!isIrrelevent) {
            bestMandates = edges[myIndex][i];
            bestIndex = i;
        }
    }
    return bestIndex;
}
MandatesSelectionPolicy* MandatesSelectionPolicy::clone() const {
    return new MandatesSelectionPolicy();
}