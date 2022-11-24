#include "SelectionPolicy.h"

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy() {}
EdgeWeightSelectionPolicy::~EdgeWeightSelectionPolicy() {}
int EdgeWeightSelectionPolicy::Select(const Graph & graph, int myIndex, const vector<int> & irrelevent) {
 
    // vector<int> irrelevent = coalition.getOfferedParties();
    vector<vector<int>> edges = graph.getEdges();
    vector<int> irRelevent = irrelevent;
    for ( int i=0; i<graph.getNumVertices(); i++){
        if (graph.getParty(i).getState()==Joined){
            irRelevent.push_back(i);
        }
    }
    int bestWeight = 0;
    int bestIndex = -1;
    vector<int> relevant;


    // Insert all parties that are not irrelevent to relevant
    for (unsigned int i=0; i<edges.size(); i++){
        //check if irrelevent contains i
        bool contained = false;
        for (unsigned int j=0; j<irRelevent.size(); j++){
            if (i==(unsigned int)irRelevent[j]){
                contained = true;
                break;
            }
        }
        if ((!contained)&&(graph.getEdgeWeight(i, myIndex)!=0)){
            relevant.push_back(i);
        }

    }

    for (unsigned int i=0; i<relevant.size(); i++){
        if (edges[myIndex][relevant[i]] > bestWeight) {
            bestWeight = edges[myIndex][relevant[i]];
            bestIndex = relevant[i];
        }
    }
    return bestIndex;


}
EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy::clone() const {
    return new EdgeWeightSelectionPolicy();
}