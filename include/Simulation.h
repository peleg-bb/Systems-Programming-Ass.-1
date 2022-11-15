#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;
    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    // rule of 5
    Simulation(const Simulation &other);
    Simulation &operator=(const Simulation &other);
    ~Simulation();
    Simulation(Simulation &&other) noexcept;
    Simulation &operator=(Simulation &&other) noexcept;
    void notifyTermination();

private:
    Graph mGraph;
    vector<Agent> mAgents;
    bool coalitionFormed;
};
