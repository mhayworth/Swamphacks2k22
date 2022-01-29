//
// Created by Lisa Reichelson on 1/29/2022.
//
#pragma once
#include <vector>
#include <unordered_map>
using namespace std;
class Jobs{
private:
    unordered_map<string, string> statesOrder; // maps each state name to it's alpha order
    string state, majorJob, subJob;
    int salary;
public:
    Jobs(string stateName);
    vector<string> getMajorJobs();
    void initStatesOrder();

};
