#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph),  mAgents(agents), mCoalitions({}), mShouldTerminate(false), mTimer(0)
{
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
    // TODO: implement this method
    for (int i=0; i<mGraph.getNumVertices(); i++){
        Party & party = mGraph.GetParty(i);
        party.step(*this);
    }
 
    for (Agent agent : mAgents)
    {
        agent.step(*this);
    }
    // vector size returns long
    if ((int)mAgents.size() == mGraph.getNumVertices()) // If all parties have joined a coalition
    {
        notifyTermination();
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
    for(Coalition* coalition : mCoalitions){
        _coalitionsVector.push_back(coalition->getPartiesJoined());
    }
    return _coalitionsVector;
}

void Simulation::notifyTermination()
{
    mShouldTerminate = true;
}

void Simulation::notifyJoined(int AgentId, int PartyId)
{
    Agent newAgent = mAgents[AgentId];
    newAgent.setPartyId(PartyId);
    newAgent.setAgentId((int)mAgents.size());
    mAgents.push_back(newAgent);
}

Simulation::~Simulation()
{
    // delete all the coalitions
    for (Coalition* coalition : mCoalitions)
    {
        delete coalition;
    }
}

void Simulation::formCoalitions()
{
    for (Agent agent : mAgents){
            agent.createCoalition(mGraph.getMandates(agent.getPartyId()));
            mCoalitions.push_back(&agent.getCoalition());            
        }
}