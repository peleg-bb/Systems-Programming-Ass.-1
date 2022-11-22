#pragma once

#include <vector>
#include "Graph.h"
#include "Agent.h"

using std::string;
using std::vector;
class Coalition;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);
    ~Simulation();
    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    Party &GetParty(int partyId); // Note: this method is not const, because it returns a non-const reference to the party
    
    void notifyTermination();
    void notifyJoined(int AgentId, int PartyId);

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition*> mCoalitions;
    bool mShouldTerminate;
    int mTimer;
};
