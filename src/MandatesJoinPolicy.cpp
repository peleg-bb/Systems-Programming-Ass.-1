#include "JoinPolicy.h"

MandatesJoinPolicy::MandatesJoinPolicy() {}
Offer * MandatesJoinPolicy::Join(std::vector<Offer *> &offers) {
    Offer * bestOffer = nullptr;
    int bestMandates = 0;
    for (Offer * offer : offers) {
        if (offer->getMandates() > bestMandates) {
            bestOffer = offer;
            bestMandates = offer->getMandates();
        }
    }
    return bestOffer;
}
MandatesJoinPolicy::~MandatesJoinPolicy() {}