#pragma once
#include <vector>
using std::vector;
class SelectionPolicy {
public:
    virtual int Select(std::vector<std::vector<int>> edges, int myIndex, vector<int> irrelevent) = 0;
    virtual ~SelectionPolicy() = default;
    virtual SelectionPolicy * clone() const = 0;
 };

class MandatesSelectionPolicy: public SelectionPolicy{
public:
    MandatesSelectionPolicy();
    ~MandatesSelectionPolicy();
    MandatesSelectionPolicy* clone() const override;
    int Select(std::vector<std::vector<int>> edges, int myIndex, vector<int> irrelevent) override;
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{
public:
    EdgeWeightSelectionPolicy();
    ~EdgeWeightSelectionPolicy();
    EdgeWeightSelectionPolicy* clone() const override;
    int Select(std::vector<std::vector<int>> edges, int myIndex, vector<int> irrelevent) override;
 };