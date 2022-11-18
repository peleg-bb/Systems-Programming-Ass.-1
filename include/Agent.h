#pragma once

#include <vector>
#include "Graph.h"
#include "Coalition.h"
class Coalition;
class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    void createCoalition(int mandates);

    //Activate the following parties after implementing the class

    // rule of 5
//     Agent(const Agent& other);
//     Agent& operator=(const Agent& other);
//     Agent(Agent&& other);
//     Agent& operator=(Agent&& other);
//     ~Agent(); // watch out not to delete the coalition!!

// private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    Coalition* mCoalition;
};
