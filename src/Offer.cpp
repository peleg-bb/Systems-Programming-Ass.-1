#include "Offer.h"
// constructor
Offer::Offer(const Coalition &coalition) : coalition(new Coalition(coalition)), timeOffered(0) {}
// rule of 3
Offer::Offer(const Offer &other) : coalition(new Coalition(*other.coalition)), timeOffered(other.timeOffered) {}
Offer &Offer::operator=(const Offer &other)
{
    if (this != &other)
    {
        delete coalition;
        coalition = new Coalition(*other.coalition);
        timeOffered = other.timeOffered;
    }
    return *this;
}
Offer::~Offer()
{
    delete coalition;
}
// rule of 5
Offer::Offer(Offer &&other) noexcept : coalition(other.coalition), timeOffered(other.timeOffered)
{
    other.coalition = nullptr;
    other.timeOffered = 0;
}
Offer &Offer::operator=(Offer &&other) noexcept
{
    if (this != &other)
    {
        delete coalition;
        coalition = other.coalition;
        timeOffered = other.timeOffered;
        other.coalition = nullptr;
        other.timeOffered = 0;
    }
    return *this;
}
