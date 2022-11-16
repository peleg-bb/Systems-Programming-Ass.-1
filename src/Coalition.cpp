#include "Coalition.h"

//add party
void Coalition::addParty(int partyId, int mandates) {
    mParties.push_back(partyId);
    this->_mandates += mandates;
}

// should terminate
bool Coalition::shouldTerminate() const
{
    return _mandates >= 61;
}

//ctor
Coalition::Coalition()
{
    _mandates = 0;
    mParties = {};
}