#include "Offer.h"

Offer::Offer(Coalition *coalition, int mandates) : mCoalition(coalition), mTime(0), mMandates(mandates) , mAgentId(0) {}
// copy constructor
Offer::Offer(const Offer& other) : mCoalition(other.mCoalition), mTime(other.mTime), mMandates(other.mMandates) , mAgentId(other.mAgentId){}
// copy assignment operator
Offer& Offer::operator=(const Offer& other)
{
    if (this != &other)
    {
        mCoalition = other.mCoalition;
        mTime = other.mTime;
        mMandates = other.mMandates;
    }
    return *this;
}
// destructor
Offer::~Offer() {
   
}
// move constructor
Offer::Offer(Offer&& other) : mCoalition(other.mCoalition), mTime(other.mTime), mMandates(other.mMandates), mAgentId(other.mAgentId)
{
    other.mCoalition = nullptr;
    other.mTime = 0;
    other.mMandates = 0;
}
// move assignment operator
Offer& Offer::operator=(Offer&& other)
{
    if (this != &other)
    {
        mCoalition = other.mCoalition;
        mTime = other.mTime;
        mMandates = other.mMandates;
        other.mCoalition = nullptr;
        other.mTime = 0;
        other.mMandates = 0;
    }
    return *this;
}

// getters
int Offer::getTime()
{
    return mTime;
}
Coalition* Offer::getCoalition()
{
    return mCoalition;
}
int Offer::getMandates()
{
    return mCoalition->getMandates();
    // This used to be a bug returning mMandates instead of mCoalition->getMandates()
    // Do not change back!
}

int Offer::getAgentId()
{
    return mAgentId;
}

void Offer::setAgentId(int agentId)
{
    mAgentId = agentId;
}