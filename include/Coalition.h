// a header file for the Coalition class
#pragma once
#include <vector>
using std::vector;

class Coalition
{
public:
    Coalition();
    bool shouldTerminate() const;
    const vector<int> &getParties() const;
    int _mandates;
    void addParty(int partyId, int mandates);
private:
    vector<int> mParties;
    //const vector<vector<int>> getPartiesByCoalitions() const;  
};