#pragma once
#include <string>
#include <vector>
#include "Offer.h"

using std::string;

class JoinPolicy;
class Simulation;
class Offer;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    void acceptOffer(Offer &offer);


private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy * mJoinPolicy;
    State mState;
    // vector of offers
    std::vector<Offer> mOffers;


    // need to implement a timer
    int _timer;
};
