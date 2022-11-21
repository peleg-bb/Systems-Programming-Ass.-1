#include "Party.h"
#include "JoinPolicy.h"
#include "Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), mTimer(0), mOffers()
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
    if (getState()==Joined||getState()==Waiting){
        return;
    }
    if (getState()==CollectingOffers){
        mTimer++;
    }   
    if (mTimer == 4){
        Offer * chosenOffer = mJoinPolicy->Join(mOffers);
        if (chosenOffer != nullptr){
            Coalition * chosenCoalition = chosenOffer->getCoalition(); // check about the fact that this is a pointer
            chosenCoalition->addParty(mId, mMandates);
            s.notifyJoined(*chosenCoalition, mId);
            if (chosenCoalition->CoalitionFormed()){
                //s.notifyTermination(chosenCoalition);
                s.notifyTermination();
            }
            delete chosenOffer;
            // delete chosenOffer?
            // Most likely yes, I think we created a duplicate
            // If it is a pointer to an object that is in the vector of offers
            // Then the vector will delete it when it is done with it
            // delete chosenCoalition?
            // Most likely not, because it is a pointer to an the actual coalition that is in the simulation
        }
        setState(Joined);
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

// Rule of 5
Party::Party(const Party& other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState), mTimer(other.mTimer)
{
    for (Offer * offer : other.mOffers){
        mOffers.push_back(offer);
    }
}
// copy assignment
Party& Party::operator=(const Party& other)
{
    if (this != &other){
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy;
        mState = other.mState;
        mTimer = other.mTimer;
        for (Offer * offer : other.mOffers){
            mOffers.push_back(offer);
        }
    }
    return *this;
}
// move constructor
Party::Party(Party&& other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState), mTimer(other.mTimer), mOffers(other.mOffers)
{

    other.mId = 0;
    other.mName = "";
    other.mMandates = 0;
    other.mJoinPolicy = nullptr;
    other.mState = Waiting;
    other.mTimer = 0;
    other.mOffers.shrink_to_fit();
}
// move assignment
Party& Party::operator=(Party&& other)
{
    if (this != &other){
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy;
        mState = other.mState;
        mTimer = other.mTimer;
        for (Offer * offer : other.mOffers){
            mOffers.push_back(offer);
        }
        other.mId = 0;
        other.mName = "";
        other.mMandates = 0;
        other.mJoinPolicy = nullptr;
        other.mState = Waiting;
        other.mTimer = 0;
        other.mOffers.shrink_to_fit();
    }
    return *this;
}
// destructor
Party::~Party()
{
    mOffers.shrink_to_fit();
}
