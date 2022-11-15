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
        c->addParty(*this); // check if this the correct way to pass a party object
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
