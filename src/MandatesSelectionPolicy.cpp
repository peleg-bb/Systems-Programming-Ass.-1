#include "SelectionPolicy.h"

MandatesSelectionPolicy::MandatesSelectionPolicy() {}
MandatesSelectionPolicy::~MandatesSelectionPolicy() {}


int MandatesSelectionPolicy::Select(const Graph & graph, int myIndex, const vector<int> & irrelevent) {
    // vector<int> irrelevent = coalition.getOfferedParties();
    vector<vector<int>> edges = graph.getEdges();
    vector<int> irRelevent = irrelevent;
    for (unsigned int i=0; i<graph.getNumVertices(); i++){
        if (graph.getParty(i).getState()==Joined){
            irRelevent.push_back(i);
        }
    }
    int bestMandates = -1;
    int bestIndex = -1;
    vector<int> relevant{};
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
        if (graph.getMandates(relevant[i]) > bestMandates) {
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