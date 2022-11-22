#pragma once
#include <string>
#include <vector>
#include <stdexcept>


using std::string;
using std::invalid_argument;

class JoinPolicy;
class Simulation;
class Offer;
class Coalition;
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
    int getTimer() const;

    //Activate the following parties after implementing the class

    // rule of 5
    Party(const Party& other);
    Party& operator=(const Party& other);
    Party(Party&& other);
    Party& operator=(Party&& other);
    ~Party();
    void recieveOffer(Offer &offer);

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    std::vector<Offer *> mOffers; //Probably should be a pointer to a vector of offers and not a vector of pointers to offers
    int mTimer;
};
