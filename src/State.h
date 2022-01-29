#pragma once

#include <string>
#include <unordered_map>

using namespace std;

class State {
    private:
        string stateName;
        Job job;
        float livingCost;

    public:
        State(string name);
        bool read();
        float getLivingCost();
}
