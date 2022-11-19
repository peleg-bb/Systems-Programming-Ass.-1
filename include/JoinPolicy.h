#pragma once
#include "Offer.h"
class JoinPolicy {
public:
    virtual Offer * Join(std::vector<Offer *> &offers) = 0;
    virtual ~JoinPolicy() = default;
    
};

class MandatesJoinPolicy : public JoinPolicy 
{
public:
    MandatesJoinPolicy();
    ~MandatesJoinPolicy();
    Offer * Join(std::vector<Offer *> &offers) override;
};

class LastOfferJoinPolicy : public JoinPolicy 
{
public:
    LastOfferJoinPolicy();
    ~LastOfferJoinPolicy();
    Offer * Join(std::vector<Offer *> &offers) override;
};