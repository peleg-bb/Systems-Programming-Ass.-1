#include "Party.h"
#include "JoinPolicy.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    // You can change the implementation of the constructor, but not the signature!
    mTimer=0;
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
    if (getState()==Joined||getState()==Waiting){
        return;
    }
    if (getState()==CollectingOffers){
        mTimer++;
    }
        
    if (mTimer == 4){
        setState(Joined);
        Offer * chosenOffer = mJoinPolicy->Join(mOffers);
        if (chosenOffer != nullptr){
            Coalition * chosenCoalition = chosenOffer->getCoalition(); // check about the fact that this is a pointer
            chosenCoalition->addParty(mId, mMandates);
            // delete chosenOffer?
            // Most likely yes, I think we created a duplicate
            // If it is a pointer to an object that is in the vector of offers
            // Then the vector will delete it when it is done with it

            // delete chosenCoalition?
            // Most likely not, because it is a pointer to an the actual coalition that is in the simulation

        }
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
