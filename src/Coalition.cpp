#include "Coalition.h"

// create all methods
Coalition::Coalition(int partyId, int mandates) : mPartiesJoined({}), mPartiesOffered({}), mMandates(mandates) {
    mPartiesJoined.push_back(partyId);
    // Use only when instantiating a new coalition for the first time
}
Coalition::Coalition() {
    mPartiesJoined = {};
    mPartiesOffered = {};
    mMandates = 0;
} // Use only for cloning
Coalition::~Coalition() {}
Coalition::Coalition(const Coalition& other) : mPartiesJoined(other.mPartiesJoined), mPartiesOffered(other.mPartiesOffered), mMandates(other.mMandates) {}
Coalition& Coalition::operator=(const Coalition& other)
{
    if (this != &other)
    {
        mPartiesJoined = other.mPartiesJoined;
        mPartiesOffered = other.mPartiesOffered;
        mMandates = other.mMandates;
    }
    return *this;
}
Coalition::Coalition(Coalition&& other) : mPartiesJoined(other.mPartiesJoined), mPartiesOffered(other.mPartiesOffered), mMandates(other.mMandates)
{
    other.mPartiesJoined = {};
    other.mPartiesOffered = {};
    other.mMandates = 0;
}
Coalition& Coalition::operator=(Coalition&& other)
{
    if (this != &other)
    {
        mPartiesJoined = other.mPartiesJoined;
        mPartiesOffered = other.mPartiesOffered;
        mMandates = other.mMandates;
        other.mPartiesJoined = {};
        other.mPartiesOffered = {};
        other.mMandates = 0;
    }
    return *this;
}
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
    return mPartiesOffered; //bugbug?
}
const std::vector<int> &Coalition::getPartiesJoined() const
{
    return mPartiesJoined;
}

// Coalition * Coalition::clone() const
// {
//     Coalition* c = new Coalition();
//     c->setPartiesJoined(mPartiesJoined);
//     c->setPartiesOffered(mPartiesOffered);
//     c->setMandates(mMandates);
//     return c; // memory leak?
// } 
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