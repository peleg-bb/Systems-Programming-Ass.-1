#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!
    coalitionFormed =false;
}

void Simulation::step()
{
    // TODO: implement this method
    // for agent in agents:
    //     agent.step()
}

bool Simulation::shouldTerminate() const
{
    return coalitionFormed;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return vector<vector<int>>();
}

// rule of 5
Simulation::Simulation(const Simulation &other) : mGraph(other.mGraph), mAgents(other.mAgents)
{
    // copy ctor
    this->mGraph = other.mGraph;
    this->mAgents = other.mAgents;
}

Simulation &Simulation::operator=(const Simulation &other)
{
    if (this != &other)
    {
        mGraph = other.mGraph;
        mAgents = other.mAgents;
    }
    return *this;
}


Simulation::~Simulation()
{
    
}

// move constructor
Simulation::Simulation(Simulation &&other) noexcept : mGraph(other.mGraph), mAgents(other.mAgents)
{
    
}
// move assignment operator
Simulation &Simulation::operator=(Simulation &&other) noexcept
{
    if (this != &other)
    {
        mGraph = other.mGraph;
        mAgents = other.mAgents;
    }
    return *this;
}

void Simulation::notifyTermination()
{
    coalitionFormed = true;
}

