#include "Offer.h"

Offer::Offer(Coalition *coalition) : mCoalition(coalition), mTime(0) {}
// copy constructor
Offer::Offer(const Offer& other) : mCoalition(other.mCoalition), mTime(other.mTime) {}
// copy assignment operator
Offer& Offer::operator=(const Offer& other)
{
    if (this != &other)
    {
        mCoalition = other.mCoalition;
        mTime = other.mTime;
    }
    return *this;
}
// destructor
Offer::~Offer() {
    delete mCoalition;
}
// move constructor
Offer::Offer(Offer&& other) : mCoalition(other.mCoalition), mTime(other.mTime)
{
    other.mCoalition = nullptr;
}
// move assignment operator
Offer& Offer::operator=(Offer&& other)
{
    if (this != &other)
    {
        mCoalition = other.mCoalition;
        mTime = other.mTime;
        other.mCoalition = nullptr;
    }
    return *this;
}

// getters
int Offer::getTime()
{
    return mTime;
}
Coalition& Offer::getCoalition()
{
    return *mCoalition;
}
int Offer::getMandates()
{
    return mMandates;
}