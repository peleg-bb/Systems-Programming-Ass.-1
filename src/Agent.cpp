#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
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
    int bestIndex = mSelectionPolicy->Select(sim.getGraph().getEdges(), mPartyId);
    // Party& party = sim.getParty(bestIndex); // Note - this returns a const party, 
    // // it is essential to create another getParty method that returns a non-const party
    // offerParty(party);
    
    
}

void Agent::createCoalition(int mandates)
{
    mCoalition = new Coalition(getPartyId(), mandates);
}

void Agent::offerParty(Party& party)
{
    Offer* offer = new Offer(mCoalition, 0); // It is OK to instantiate an offer with 0 mandates, see Offer.getMandates()
    //Who deletes the offer?
    //The party should delete all the offers it had received when it joins a coalition 
    party.recieveOffer(*offer); 
}
