#pragma once
#include "Offer.h"
class JoinPolicy {
public:
    virtual Offer * Join(std::vector<Offer *> &offers) = 0;
    virtual ~JoinPolicy() = default;
    virtual JoinPolicy * clone() const = 0;
    
};

class MandatesJoinPolicy : public JoinPolicy 
{
public:
    MandatesJoinPolicy();
    ~MandatesJoinPolicy();
    MandatesJoinPolicy* clone() const override;
    Offer * Join(std::vector<Offer *> &offers) override;
};

class LastOfferJoinPolicy : public JoinPolicy 
{
public:
    LastOfferJoinPolicy();
    ~LastOfferJoinPolicy();
    LastOfferJoinPolicy* clone() const override;
    Offer * Join(std::vector<Offer *> &offers) override;
};