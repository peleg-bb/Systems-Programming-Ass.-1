#include "Agent.h"

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
}


// Rule of 3
Agent::Agent(const Agent &other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy)
{
    // copy ctor
    this->mAgentId = other.mAgentId;
    this->mPartyId = other.mPartyId;
    this->mSelectionPolicy = other.mSelectionPolicy;
}

Agent &Agent::operator=(const Agent &other)
{
    if (this != &other)
    {
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy;
    }
    return *this;
}

Agent::~Agent()
{
    delete[] mSelectionPolicy;
}

// rule of 5
Agent::Agent(Agent &&other) noexcept : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy)
{
    other.mAgentId = 0;
    other.mPartyId = 0;
    other.mSelectionPolicy = nullptr;
}
// move assignment operator
Agent &Agent::operator=(Agent &&other) noexcept
{
    if (this != &other)
    {
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        delete[] mSelectionPolicy;
        mSelectionPolicy = other.mSelectionPolicy;
        // other.mAgentId = 0; // I think it is not needed
        // other.mPartyId = 0;
        other.mSelectionPolicy = nullptr;
    }
    return *this;
}
