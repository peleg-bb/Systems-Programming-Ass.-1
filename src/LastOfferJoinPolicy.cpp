#include "JoinPolicy.h"

LastOfferJoinPolicy::LastOfferJoinPolicy() {}

LastOfferJoinPolicy::~LastOfferJoinPolicy() {}

Offer * LastOfferJoinPolicy::Join(std::vector<Offer *> &offers) {
    return offers.back();
}