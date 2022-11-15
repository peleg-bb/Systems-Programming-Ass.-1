#pragma once
# include <vector>

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
    private:
        Offer lastOffer;

    public:
        // returns the last offer
        Offer* join(std::vector<Offer> offers);
};