#include "SelectionPolicy.h"

MandatesSelectionPolicy::MandatesSelectionPolicy() {}
MandatesSelectionPolicy::~MandatesSelectionPolicy() {}


int MandatesSelectionPolicy::Select(const Graph & graph, int myIndex, vector<int> irrelevent) {
    vector<vector<int>> edges = graph.getEdges();
    int bestMandates = 0;
    int bestIndex = -1;
    vector<int> relevant;
    for (unsigned int i=0; i<edges.size(); i++){
        for (unsigned int j=0; j<irrelevent.size(); j++){
            if (i!=irrelevent[j]){
            relevant.push_back(i);
            }
        }
    }

    for (unsigned int i=0; i<relevant.size(); i++){
        if (edges[myIndex][relevant[i]] > bestMandates) {
            bestMandates = graph.getMandates(relevant[i]);
            bestIndex = relevant[i];
        }
    }
    return bestIndex;
    // for (unsigned int i = 0; i < edges.size(); i++) {
    //     // check if i is irrelevent (meaning party i has been offered a place in the coalition)
    //     //bool isIrrelevent = false;
    //     for (unsigned int j = 0; j < irrelevent.size(); j++) {
    //         if (i == irrelevent[j]) {
    //             // isIrrelevent = true;
    //             i++;
    //         }
    //     }


    //     if (edges[myIndex][i] > bestMandates&&!isIrrelevent) {
    //         bestMandates = edges[myIndex][i];
    //         bestIndex = i;
    //     }
    // }
    // return bestIndex;
}
MandatesSelectionPolicy* MandatesSelectionPolicy::clone() const {
    return new MandatesSelectionPolicy();
}