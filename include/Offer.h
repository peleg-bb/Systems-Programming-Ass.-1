#pragma once
# include "Coalition.h"
class Coalition;

class Offer {
    public:
        Coalition* coalition;
        int timeOffered;
        // constructor
        Offer(const Coalition &coalition);
        // 
        // Coalition* getCoalition();
        // rule of 3
        Offer(const Offer &other);
        Offer &operator=(const Offer &other);
        ~Offer();
        // rule of 5
        Offer(Offer &&other) noexcept;
        Offer &operator=(Offer &&other) noexcept;
};