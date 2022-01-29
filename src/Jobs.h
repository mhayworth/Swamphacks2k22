//
// Created by Lisa Reichelson on 1/29/2022.
//
#pragma once
#include <vector>
using namespace std;
class Jobs{
private:
    string state, majorJob, subJob;
    int salary;
public:
    Jobs(string stateName);
    vector<string> getMajorJobs();

};
