// a header file for the Coalition class
#pragma once
#include "Party.h"
#include "Graph.h"
#include <vector>

using std::vector;

class Coalition
{
public:
    Coalition(const Graph &graph, const vector<Party> &parties);
    void step();
    bool shouldTerminate() const;
    const Graph &getGraph() const;
    const vector<Party> &getParties() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
};