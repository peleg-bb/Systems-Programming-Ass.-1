#pragma once

#include <vector>
#include "Graph.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    // Rule of 3
    Agent(const Agent &other);
    Agent &operator=(const Agent &other);
    ~Agent();
    // rule of 5
    Agent(Agent &&other) noexcept;
    Agent &operator=(Agent &&other) noexcept;
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
};
