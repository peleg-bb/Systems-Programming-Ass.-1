#pragma once
# include "Coalition.h"


class Offer {
    public:
        Coalition *coalition;
        int timeOffered;
        // constructor
        Offer(Coalition coalition);
        // // get coalition
        // Coalition* getCoalition();
};