#include "Coalition.h"

//add party
void Coalition::addParty(const Party &party)
{
    mParties.push_back(party);
    mandates += party.getMandates();
}

// should terminate
bool Coalition::shouldTerminate() const
{
    return mandates >= 61;
}