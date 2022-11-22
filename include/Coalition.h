#pragma once
#include <vector>

class Coalition
{
private:
    std::vector<int>  mPartiesJoined;
    std::vector<int>  mPartiesOffered;
    int mMandates;
public:
    Coalition(int partyId, int mandates);
    Coalition();
    ~Coalition();
    Coalition(const Coalition& other);
    Coalition& operator=(const Coalition& other);
    Coalition(Coalition&& other);
    Coalition& operator=(Coalition&& other);
    void addParty(int partyId, int mandates);
    void addOfferedParty(int partyId);
    bool CoalitionFormed();
    int getMandates() const;
    const std::vector<int> &getPartiesOffered() const;
    const std::vector<int> &getPartiesJoined() const; // Perhaps I should pass by value instead of reference?
    //Coalition * clone() const;

    // setters
    void setMandates(int mandates);
    void setPartiesJoined(std::vector<int> partiesJoined);
    void setPartiesOffered(std::vector<int> partiesOffered);
};
