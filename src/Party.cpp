#include "Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    // You can change the implementation of the constructor, but not the signature!
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
    // TODO: implement this method
    if (getState()==Joined){
        return;
    }
    mTimer++;
    if (mTimer == 4){
        setState(Joined);
        // join
    }
}

void Party::recieveOffer(Offer &offer)
{
    if (mState == Joined){
        throw std::invalid_argument("Party has already joined a coalition");
    }
    if (mState == Waiting){
        mTimer = 1;
        mState = CollectingOffers;
    }
    mOffers.push_back(&offer);
}
