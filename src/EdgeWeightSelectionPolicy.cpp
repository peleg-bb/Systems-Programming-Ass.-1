#include "SelectionPolicy.h"

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy() {}
EdgeWeightSelectionPolicy::~EdgeWeightSelectionPolicy() {}
int EdgeWeightSelectionPolicy::Select(const Graph & graph, int myIndex, const vector<int> & irrelevent) {
    // Irrelevant is SHIT!!!!!!!!!!!
    // Containes rubbish
    // vector<int> irrelevent = coalition.getOfferedParties();
    vector<vector<int>> edges = graph.getEdges();
    vector<int> irRelevent = irrelevent;
    for (unsigned int i=0; i<graph.getNumVertices(); i++){
        if (graph.getParty(i).getState()==Joined){
            irRelevent.push_back(i);
        }
    }
    int bestWeight = 0;
    int bestIndex = -1;
    vector<int> relevant;
    // for (unsigned int i=0; i<edges.size(); i++){
    //     for (unsigned int j=0; j<irrelevent.size(); j++){
    //         if (i!=irrelevent[j]){
    //         relevant.push_back(i);
    //         }
    //     }
    // }

    // Insert all parties that are not irrelevent to relevant
    for (unsigned int i=0; i<edges.size(); i++){
        //check if irrelevent contains i
        bool contained = false;
        for (unsigned int j=0; j<irRelevent.size(); j++){
            if (i==irRelevent[j]){
                contained = true;
                break;
            }
        }
        if ((!contained)&&(graph.getEdgeWeight(i, myIndex)!=0)){
            relevant.push_back(i);
        }
        // for (unsigned int j=0; j<irrelevent.size(); j++){
        //     if ((irrelevent.)(i!=irrelevent[j])&&(graph.getEdgeWeight(i, myIndex)!=0)){
        //         relevant.push_back(i);
        //     }
        // }
    }

    for (unsigned int i=0; i<relevant.size(); i++){
        if (edges[myIndex][relevant[i]] > bestWeight) {
            bestWeight = edges[myIndex][relevant[i]];
            bestIndex = relevant[i];
        }
    }
    return bestIndex;

    // int bestWeight = 0;
    // int bestIndex = 0;
    // for (int i = 0; i < (int)edges.size(); i++) {
    //     // check if i is irrelevent (meaning party i has been offered a place in the coalition)
    //     bool isIrrelevent = false;
    //     for (int j = 0; j < (int)irrelevent.size(); j++) {
    //         if (i == irrelevent[j]) {
    //             isIrrelevent = true;
    //             break;
    //         }
    //     }
    //     if (edges[myIndex][i] > bestWeight&&!isIrrelevent) {
    //         bestWeight = edges[myIndex][i];
    //         bestIndex = i;
    //     }
    // }
    // return bestIndex;
}
EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone() const {
    return new EdgeWeightSelectionPolicy();
}