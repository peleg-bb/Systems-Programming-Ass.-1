#include "Coalition.h"

// create all methods
Coalition::Coalition(int partyId, int mandates) : mPartiesJoined(new std::vector<int>), mPartiesOffered(new std::vector<int>), mMandates(new int(0)) {
    mPartiesJoined->push_back(partyId);
}
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
    // needs to be fixed to delete pointers
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
    mPartiesJoined->push_back(partyId);
    *mMandates += mandates;
}
void Coalition::addOfferedParty(int partyId)
{
    mPartiesOffered->push_back(partyId);
}
bool Coalition::CoalitionFormed()
{
    return *mMandates >= 61;
}

int Coalition::getMandates() const
{
    return *mMandates;
}
const std::vector<int> &Coalition::getPartiesOffered() const
{
    if (mPartiesOffered == nullptr)
    {
        return {};
    }
    return *mPartiesOffered;
}
const std::vector<int> &Coalition::getPartiesJoined() const
{
    if (mPartiesJoined == nullptr)
    {
        return {};
    }
    return *mPartiesJoined;
}