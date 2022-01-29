#pragma once

#include <string>
#include <unordered_map>

#include "Jobs.h"

using namespace std;

class State {
    private:
        string stateName;
        Jobs job = Jobs(stateName);
        float livingCost;

    public:
        State(string name);
        bool read();
        float getLivingCost();
        bool compare(string potentialState, int potentialSalary);
        Jobs getJob();
};
