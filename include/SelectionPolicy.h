#pragma once
#include <vector>
using std::vector;
class SelectionPolicy {
public:
    virtual int Select(std::vector<std::vector<int>> edges, int myIndex) = 0;
    virtual ~SelectionPolicy() = default;
 };

class MandatesSelectionPolicy: public SelectionPolicy{
public:
    MandatesSelectionPolicy();
    ~MandatesSelectionPolicy();
    int Select(std::vector<std::vector<int>> edges, int myIndex) override;
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{
public:
    EdgeWeightSelectionPolicy();
    ~EdgeWeightSelectionPolicy();
    int Select(std::vector<std::vector<int>> edges, int myIndex) override;
 };