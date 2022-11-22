#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalition(new Coalition())
{
    // You can change the implementation of the constructor, but not the signature!
}


int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    // TODO: implement this method
    //vector<int> _partiesOffered = mCoalition->getPartiesOffered();

    const Graph & graph = sim.getGraph();
    // vector<vector<int>> adjacencyMatrix = sim.getGraph().getEdges();
    int bestIndex = mSelectionPolicy->Select(graph, mPartyId, mCoalition->getPartiesOffered());
    if (bestIndex == -1)
    {
        return; // In some occasions we have no one to offer to, in those cases we should just return
    }
    
    Party& party = sim.GetParty(bestIndex); // Returns a non-const reference to the party, should be deleted in sim I believe
    offerParty(party);
    mCoalition->addOfferedParty(bestIndex);
}

void Agent::createCoalition(int mandates)
{
    // This method is seperated from the constructor, because only in some occasions we want to create a new coalition
    mCoalition->addParty(mPartyId, mandates);
    mCoalition->addOfferedParty(getPartyId());
}

void Agent::offerParty(Party& party)
{
    Offer* offer = new Offer(mCoalition, 0); 
    offer->setAgentId(mAgentId);
    // It is OK to instantiate an offer with 0 mandates, see Offer.getMandates()
    //Who deletes the offer?
    //The party should delete all the offers it had received when it joins a coalition 
    party.recieveOffer(*offer); 
}

// rule of 5
// copy constructor
Agent::Agent(const Agent& other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy->clone()), mCoalition(other.mCoalition)
{
}
// copy assignment
Agent& Agent::operator=(const Agent& other)
{
    if (this != &other)
    {
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy->clone();
        mCoalition = other.mCoalition->clone();
    }
    return *this;
}
// move constructor
Agent::Agent(Agent&& other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy), mCoalition(other.mCoalition)
{
    other.mAgentId = 0;
    other.mPartyId = 0;
    other.mSelectionPolicy = nullptr;
    other.mCoalition = nullptr;
}
// move assignment
Agent& Agent::operator=(Agent&& other)
{
    if (this != &other)
    {
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy;
        mCoalition = other.mCoalition;
        other.mAgentId = 0;
        other.mPartyId = 0;
        other.mSelectionPolicy = nullptr;
        other.mCoalition = nullptr;
    }
    return *this;
}
// destructor
Agent::~Agent()
{
    //delete mCoalition; 
    delete mSelectionPolicy;
     // I am deleting the coalition here, but I am not sure if it is the right place
}

Agent::Agent(int PartyId, SelectionPolicy *selectionPolicy, Coalition *coalition) : mAgentId(0), mPartyId(PartyId), mSelectionPolicy(selectionPolicy), mCoalition(coalition)
{
    // Dangerous!! Several agents hold a pointer to the same coalition, and when one of them deletes it, the others will have a dangling pointer
}

void Agent::setAgentId(int agentId)
{
    mAgentId = agentId;
}

void Agent::setPartyId(int partyId)
{
    mPartyId = partyId;
}

const Coalition& Agent::getCoalition() const
{
    return *mCoalition;
}