#pragma once
#include <vector>
#include "Graph.h"
#include "Coalition.h"
#include "Offer.h"
class Coalition;
class SelectionPolicy;
class Simulation;
class Offer;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(int PartyId, SelectionPolicy *selectionPolicy, Coalition *coalition);
    void setAgentId(int agentId);
    void setPartyId(int partyId);
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    void createCoalition(int mandates);
    void offerParty(Party& party);

    //Activate the following parties after implementing the class

    //rule of 5
    Agent(const Agent& other);
    Agent& operator=(const Agent& other);
    Agent(Agent&& other);
    Agent& operator=(Agent&& other);
    ~Agent(); // watch out not to delete the coalition!! I don't remember why though lol, the agent is the one who creates the coalition

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    Coalition* mCoalition;
};
