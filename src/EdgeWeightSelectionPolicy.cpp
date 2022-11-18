#include "SelectionPolicy.h"

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy() {}
EdgeWeightSelectionPolicy::~EdgeWeightSelectionPolicy() {}
int EdgeWeightSelectionPolicy::Select(std::vector<std::vector<int>> edges, int myIndex) {
    int bestWeight = 0;
    int bestIndex = 0;
    for (int i = 0; i < (int)edges.size(); i++) {
        if (edges[myIndex][i] > bestWeight) {
            bestWeight = edges[myIndex][i];
            bestIndex = i;
        }
    }
    return bestIndex;
}