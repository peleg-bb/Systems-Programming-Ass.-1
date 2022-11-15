// a header file for the Coalition class
#pragma once
#include "Party.h"
#include <vector>

using std::vector;

class Coalition
{
public:
    Coalition(const vector<Party> &parties);
    bool shouldTerminate() const;
    const vector<Party> &getParties() const;
    int mandates;
    void addParty(const Party &party);
private:
    vector<Party> mParties;

    //const vector<vector<int>> getPartiesByCoalitions() const;
    
};