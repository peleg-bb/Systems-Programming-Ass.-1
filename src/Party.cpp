#include "Party.h"
#include "Simulation.h"
#include "JoinPolicy.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    // You can change the implementation of the constructor, but not the signature!
    // need to implement a timer
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    if(mState==Waiting || mState == Joined){
        return;
    }
    if (mState == CollectingOffers)
    {
       _timer++;
    }
    if (_timer == 4)
    {
        // decide on offer JoinPolicy
        Offer * offer = (*mJoinPolicy).join(mOffers);
        mState = Joined;
        // coalition adds party
        Coalition* c = offer->coalition;
        c->addParty(mId, mMandates); // check if this the correct way to pass a party object - Yuval says yes
        if (c->shouldTerminate()){
            s.notifyTermination();
        }
        // check if coalition has enough mandates through shouldTerminate()
        // if yes, notify simulation using s.notifyTermination();
    }
    
}

void Party::acceptOffer(Offer &offer)
{
    if (mState == Joined){
        return;
    }
    if (mState == Waiting)
    {
        _timer = 1;
        mState = CollectingOffers;
    }
    offer.timeOffered = _timer;
    mOffers.push_back(offer);
}





// rule of 3
Party::Party(const Party &other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState), mOffers(other.mOffers), _timer(other._timer)
{}
// copy assignment operator
Party &Party::operator=(const Party &other)
{
    if (this != &other)
    {
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy;
        mState = other.mState;
        mOffers = other.mOffers;
        _timer = other._timer;
    }
    return *this;
}
// destructor
Party::~Party()
{
    delete mJoinPolicy;
}
// rule of 5
Party::Party(Party &&other) noexcept : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState), mOffers(other.mOffers), _timer(other._timer)
{
    other.mId = 0;
    other.mName = "";
    other.mMandates = 0;
    other.mJoinPolicy = nullptr;
    other.mState = Waiting;
    other.mOffers = {};
    other._timer = 0;
}
// move assignment operator
Party &Party::operator=(Party &&other) noexcept
{
    if (this != &other)
    {
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy;
        mState = other.mState;
        mOffers = other.mOffers;
        _timer = other._timer;
        other.mId = 0;
        other.mName = "";
        other.mMandates = 0;
        other.mJoinPolicy = nullptr;
        other.mState = Waiting;
        other.mOffers = {};
        other._timer = 0;
    }
    return *this;
}