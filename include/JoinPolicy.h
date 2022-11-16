#pragma once
# include <vector>
# include "Offer.h"
class Offer;

class JoinPolicy {
    public:
        virtual Offer *join(std::vector<Offer> offers) = 0;
        JoinPolicy();
        
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        // returns the offer with the most mandates
        Offer* join(std::vector<Offer> offers);
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        // returns the last offer
        Offer* join(std::vector<Offer> offers);
        // constructor
        LastOfferJoinPolicy();

};