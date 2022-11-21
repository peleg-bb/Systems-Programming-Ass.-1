#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), mShouldTerminate(false), mTimer(0)
{
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
    // TODO: implement this method
    if(mTimer==0){
        for (Agent agent : mAgents){
            agent.createCoalition(mGraph.getMandates(agent.getPartyId()));            
        }
        mTimer = -1;
    }
    for (Party party : mGraph.getParties())
    {
        party.step(*this);
        // check if all parties have joined a coalition
    }
    for (Agent agent : mAgents)
    {
        agent.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    return mShouldTerminate;
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

Party &Simulation::GetParty(int partyId)
{
    // Note: this method is not const, because it returns a non-const reference to the party
    return mGraph.GetParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    vector<vector<int>> _coalitionsVector;
    for(Coalition coalition : mCoalitions){
        _coalitionsVector.push_back(coalition.getPartiesJoined());
    }
    return _coalitionsVector;
}

void Simulation::notifyTermination()
{
    mShouldTerminate = true;
}
