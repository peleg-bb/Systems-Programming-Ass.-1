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
    int bestIndex = mSelectionPolicy->Select(sim.getGraph().getEdges(), mPartyId, mCoalition->getPartiesOffered());
    Party& party = sim.GetParty(bestIndex); // Returns a non-const reference to the party, should be deleted in sim I believe
    offerParty(party);
    mCoalition->addOfferedParty(bestIndex);
}

void Agent::createCoalition(int mandates)
{
    mCoalition = new Coalition(getPartyId(), mandates);
    mCoalition->addOfferedParty(getPartyId());
}

void Agent::offerParty(Party& party)
{
    Offer* offer = new Offer(mCoalition, 0); // It is OK to instantiate an offer with 0 mandates, see Offer.getMandates()
    //Who deletes the offer?
    //The party should delete all the offers it had received when it joins a coalition 
    party.recieveOffer(*offer); 
}
