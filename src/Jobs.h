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
    string state;
    vector<string> majorJobs;
    vector<pair<string, string>> minorJobs;
    unordered_map<string, string> minorJobSalaries;
    unordered_map<string, string> statesOrder;
public:
    Jobs();
    vector<string> calcMajorJobs();
    void setStateName(string stateName);
    vector<string> getMajorJobs();
    int getSalary(string jobTitle);
    vector<pair<string, string>> getSubMajorJobs(string major);
    void initStatesOrder();
};
