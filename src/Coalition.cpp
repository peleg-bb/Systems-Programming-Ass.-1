#include "Coalition.h"

// create all methods
Coalition::Coalition(int partyId, int mandates) : mPartiesJoined({}), mPartiesOffered({}), mMandates(mandates) {
    mPartiesJoined.push_back(partyId);
    // Use only when instantiating a new coalition for the first time
}
Coalition::Coalition() : mPartiesJoined ({}), mPartiesOffered({}), mMandates(0) {

} // Use only for cloning
Coalition::~Coalition() {}
Coalition::Coalition(const Coalition& other) : mPartiesJoined(other.mPartiesJoined), mPartiesOffered(other.mPartiesOffered), mMandates(other.mMandates) {}

void Coalition::addParty(int partyId, int mandates)
{
    mPartiesJoined.push_back(partyId);
    mMandates += mandates;
}
void Coalition::addOfferedParty(int partyId)
{
    mPartiesOffered.push_back(partyId);
}
bool Coalition::CoalitionFormed()
{
    return mMandates >= 61;
}

int Coalition::getMandates() const
{
    return mMandates;
}
const std::vector<int> &Coalition::getPartiesOffered() const
{
    return mPartiesOffered; 
}
const std::vector<int> &Coalition::getPartiesJoined() const
{
    return mPartiesJoined;
}

// setters
void Coalition::setMandates(int mandates)
{
    mMandates = mandates;
}
void Coalition::setPartiesJoined(std::vector<int> partiesJoined)
{
    mPartiesJoined = partiesJoined;
}
void Coalition::setPartiesOffered(std::vector<int> partiesOffered)
{
    mPartiesOffered = partiesOffered;
}