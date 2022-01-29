#include <fstream>
#include <vector>

#include "State.h"

State::State(string name) {
    stateName = name;
    job = Job(stateName);
    if (!read()) {
        livingCost = -1;
    }
}

bool State::read() {
    string line;
    ifstream myfile ("../Datasets/Costsofliving.csv");
    vector<string> vInput;
    if myfile.is_open() {
        while (getline (myfile, line)) {
            vInput.clear();
            int start = 0;
            //converts input string into a vector of strings, split by the ',' char
            for (int i = 0; i < line.length(); i++) {
                if (line.at(i) == ',') {
                    vInput.push_back(line.substr(start, i - start));
                    start = i + 1;
                }
            }
            if (vInput.at(0) == stateName) {
                livingCost = stof(vInput.at(1));
            }
            return true;
        }
        return false;
    }
}

float State::getLivingCost() {
    return livingCost;
}

Job State::getJob() {
    return Job;
}