//
// Created by Lisa Reichelson on 1/29/2022.
//
#pragma once
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Jobs{
private:
    string state, majorJob, subJob;
    int salary;
    unordered_map<string, string> statesOrder;
public:
    Jobs(string stateName);
    vector<string> getMajorJobs();
    void initStatesOrder();
};
