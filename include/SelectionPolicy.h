#pragma once

class SelectionPolicy {
    public:
        SelectionPolicy();
        virtual ~SelectionPolicy();
        virtual int select() = 0;
 };

class MandatesSelectionPolicy: public SelectionPolicy{ 
    int select() override;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    int select() override;
 };