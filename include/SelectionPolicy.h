#pragma once
#include <vector>
#include "Graph.h"
//class Graph;
using std::vector;
class SelectionPolicy {
public:
    virtual int Select(const Graph & graph, int myIndex, const vector<int> & irrelevent) = 0;
    virtual ~SelectionPolicy() = default;
    virtual SelectionPolicy * clone() const = 0;
 };

class MandatesSelectionPolicy: public SelectionPolicy{
public:
    MandatesSelectionPolicy();
    ~MandatesSelectionPolicy();
    MandatesSelectionPolicy* clone() const override;
    int Select(const Graph & graph, int myIndex, const vector<int> & irrelevent) override;
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{
public:
    EdgeWeightSelectionPolicy();
    ~EdgeWeightSelectionPolicy();
    EdgeWeightSelectionPolicy* clone() const override;
    int Select(const Graph & graph, int myIndex, const vector<int> & irrelevent) override;
 };