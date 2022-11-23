#pragma once
#include "Coalition.h"
class Coalition;

class Offer
{
private:
    Coalition* mCoalition;
    int mTime;
    int mMandates;
    int mAgentId;
public:
    Offer(Coalition *coalition, int mandates);
    // rule of 3
    // copy constructor
    Offer(const Offer& other);
    // copy assignment operator
    Offer& operator=(const Offer& other);
    // destructor
    ~Offer();
    // rule of 5
    // move constructor
    Offer(Offer&& other);
    // move assignment operator
    Offer& operator=(Offer&& other);

    // getters
    int getTime();
    Coalition* getCoalition();
    int getMandates();
    int getAgentId();
    void setAgentId(int agentId);
};


