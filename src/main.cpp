#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#include "State.h"

using namespace std;

void helpDialog(string major) {
    /* if (major != "" && major != "help") {
        Jobs a;
        a.setStateName("Florida");
        vector<pair<string, string>> vec = a.getSubMajorJobs(major);
        cout << "sub-jobs for major " << major << endl;
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i].first << endl;
        }
    } */
    cout << "Thank you for using the Comparing Salaries Bot!" << endl;
    cout << "Functionality is as follows:" << endl;
    cout << "1. '!CS compare' is to compare your salary to a local average." << endl;
    cout << "Functionality for take home pay comparison is: !SC <State_Name> <Salary> <Job_Title>" << endl;
    cout << "<Salary> should have no commas and be pre-tax, and more information on <Job_Title> can be found through !SC help" << endl;
    cout << "Example: '!CS compare Florida 75000 Aerospace-Engineers' would be your input if you live in Florida, make $75,000 pre-tax are an aerospace engineer" << endl;
    cout << endl;
    cout << "2. '!CS pay' is to find your take home pay after factoring in cost of living." << endl;
    cout << "Functionality for take home pay is: !SP <State_Name> <Salary> <Lifestyle>" << endl;
    cout << "<Salary> should have no commas and be pre-tax, while <Lifestyle> can be 'frugally', 'normally', 'luxuriously'" << endl;
    cout << "Example: '!CS pay Florida 75000 frugally' would be your input if you live in Florida, make $75,000 pre-tax annually and live frgually" << endl;
    cout << endl;
    cout << "3. '!CS evaluate' is to evaluate a job offer." << endl;
    cout << "Functionality for evaluation is: !CS evaluate <Current_State> <Current_Salary> <New_State> <New_Salary> <Lifestyle>. See 2. for lifestyle info" << endl;
    cout << endl;
    cout << "Job titles are very specific. Major names are" << endl;
    Jobs j;
    j.setStateName("Florida");
    vector<string> v = j.getMajorJobs();
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}

void takeHomeDialog(int argc, char* argv[]) {
    if (argc != 5) {
        return;
    }
    string homeState = argv[2];
    State home = State(homeState);
    string salary = argv[3];
    string lifeStyle = argv[4];

    float lifeStyleMultiplier;
    if (lifeStyle == "frugally") {
        lifeStyleMultiplier = 0.75f;
    }
    else if (lifeStyle == "luxuriously") {
        lifeStyleMultiplier = 2;
    }
    else {
        lifeStyleMultiplier = 1;
    }

    if (home.getLivingCost() == -1) {
        cout << "Error: could not find state " << homeState << endl;
        return;
    }
    int takeHomePay = stoi(salary) - (15000 * home.getLivingCost() / 100 * lifeStyleMultiplier);

    cout << "Your take home pay after considering costs of living and lifestyle is " << takeHomePay << endl;
    return;
}


void compareDialog(int argc, char* argv[]) {
    if (argc != 5) {
        return;
    }
    string homeState = argv[2];
    State home = State(homeState);
    string salary = argv[3];
    string jobTitle = argv[4];
    int avgSalary =-1;
    vector<string> v = home.getJob().getMajorJobs();
    for (int i = 0; i < v.size(); i++) {
        vector<pair<string,string>> vec = home.getJob().getSubMajorJobs(v[i]);
        for (int j = 0; j < vec.size(); j++) {
            if (vec[j].first == jobTitle) {
                string s = vec[j].second;
                s.erase(remove( s.begin(), s.end(), '\"' ),s.end());
               // cout << vec[j].second << endl;
               cout << s << endl;
               avgSalary = stoi(s);
            }
        }
    }
    cout << "Your state's average salary is $" << avgSalary;
    if (avgSalary > stoi(salary)) {
        cout << ", which is higher than your salary. You may want to look for better offers in the area." << endl;
    }
    else {
        cout << ", which is lower than your salary, your job is a keeper!" << endl;
    }
}

void evaluateDialog(int argc, char* argv[]) {
    string homeState = argv[2];
    State home = State(homeState);
    string salary = argv[3];
    string nState = argv[4];
    State newState = State(nState);
    string newSalary = argv[5];
    string lifeStyle = argv[6];
    float lifeStyleMultiplier;
    if (lifeStyle == "frugally") {
        lifeStyleMultiplier = 0.75f;
    }
    else if (lifeStyle == "luxuriously") {
        lifeStyleMultiplier = 2;
    }
    else {
        lifeStyleMultiplier = 1;
    }

    if (home.getLivingCost() == -1) {
        cout << "Error: could not find state " << homeState << endl;
        return;
    }
    if (newState.getLivingCost() == -1) {
        cout << "Error: could not find state " << nState << endl;
    }
    int takeHomePay = stoi(salary) - (15000 * home.getLivingCost() / 100 * lifeStyleMultiplier);
    int newTakeHomePay = stoi(newSalary) - (15000 * newState.getLivingCost() / 100 * lifeStyleMultiplier);
    if (newTakeHomePay > takeHomePay) {
        cout << "Your new offer has a higher take home pay of " << newTakeHomePay << " versus " << takeHomePay << endl;
    }
    else {
        cout << "Your current job has a higher take home pay of " << takeHomePay << " versus " << newTakeHomePay << endl;
    }

}

int main(int argc, char* argv[]) {
    cout << endl;
    if (argc < 2) {
        helpDialog("");
    }
    else if (strcmp(argv[1], "compare") == 0) {
        compareDialog(argc, argv);
    }
    else if (strcmp(argv[1], "pay") == 0) {
        takeHomeDialog(argc, argv);
    }
    else if (strcmp(argv[1], "evaluate") == 0) {
        evaluateDialog(argc, argv);
    }
    else {
        helpDialog(argv[1]);
    }
    return 0;
}