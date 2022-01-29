#include <iostream>
#include <string>

#include "State.h"

using namespace std;

void interact() {
    cout << "Welcome to [BOT_NAME]! Please type the number of your selection:" << endl;
    cout << "1. Compare my job to average local salary" << endl;
    cout << "2. Give me my estimated take home pay after costs of living" << endl;
    cout << "3. Evaluate my job offer" << endl;

    string userInput;
    cin >> userInput;
    while (true) {
        try {
            (stof(userInput));
            break;
        }
        catch (...) {
            cout << "Please enter just the number of your selection!" << endl;
            cin >> userInput;
        }
    }
    
    cout << "Enter your current state's name:" << endl;
    string homeState;
    cin >> homeState;
    State home = State(homeState);

    cout << "Enter your post-tax annual salary as a number - no commas, please!" << endl;
    string salary;
    cin >> salary;

    cout << "Do you live frugally, normally, or luxuriously? (hint: type the word exactly as it appears)" << endl;
    string lifeStyle;
    cin >> lifeStyle;
    float lifeStyleMultiplier;

    if (lifeStyle == "frugally") {
        lifeStyleMultiplier = 0.75f;
    }
    else if (lifeStyle == "luxuriously") {
        lifeStyleMultiplier == 1.5f;
    }
    else {
        lifeStyleMultiplier = 1;
    }

    if (home.getLivingCost() == -1) {
        cout << "Error: could not find state " << homeState << endl;
        return;
    }
    int takeHomePay = stoi(salary) - (15000 * home.getLivingCost() / 100 * lifeStyleMultiplier);

    switch (stoi(userInput)) {
        case 1: {
            vector<string> majorJobs = home.getJob().getMajorJobs();
            cout << "Select a major job field" << endl;
            for (int i = 0; i < majorJobs.size(); i++) {
                cout << i << ". " << majorJobs[i] << endl;
            }
            // add more
            break;
        }
        case 2: {
            cout << "Your take home pay after considering costs of living and lifestyle is " << takeHomePay << endl;
            break;
        }
        case 3: {
            cout << "Your current take home pay is " << takeHomePay << endl;
            break;
        }
    }
    return;
}

void helpDialog() {
    cout << "Thank you for using the Comparing Salaries Bot!" << endl;
    cout << "Functionality is as follows:" << endl;
    cout << "1. !SC is to compare your salary to a local average." << endl;
    cout << "2. !SP is to find your take home pay after factoring in cost of living." << endl;
    cout << "3. !SE is to evaluate a job offer." << endl;
    cout << "For help with any of these commands, try !<name> help - ex. '!SC help'" << endl;
}

void takeHomeDialog(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Functionality for take home pay is: !SP <State_Name> <Salary> <Lifestyle>" << endl;
        cout << "<Salary> should have no commas and be post-tax, while <Lifestyle> can be 'frugally', 'normally', 'luxuriously'" << endl;
        cout << "Example: '!SP Florida 75000 frugally' would be your input if you live in Florida, make $75,000 post-tax annually and live frgually" << endl;
        return;
    }
    string homeState = argv[1];
    State home = State(homeState);
    string salary = argv[2];
    string lifeStyle = argv[3];

    float lifeStyleMultiplier;
    if (lifeStyle == "frugally") {
        lifeStyleMultiplier = 0.75f;
    }
    else if (lifeStyle == "luxuriously") {
        lifeStyleMultiplier == 1.5f;
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

void SChelp() {
    cout << "Job titles can be split into major and minor jobs. Major jobs are:" << endl;
    State home = State("Florida");
    vector<string> majorJobs = home.getJob().getMajorJobs();
}

void compareDialog(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Functionality for take pay comparison is: !SC <State_Name> <Salary> <Job_Title>" << endl;
        cout << "<Salary> should have no commas and be post-tax, and more information on <Job_Title> can be found through !SC help" << endl;
        cout << "Example: '!SC Florida 75000 Aerospace-Engineers' would be your input if you live in Florida, make $75,000 post-tax are an aerospace engineer" << endl;
        return;
    }
    if (argv[1] == "help") {
        SChelp();
        return;
    }
    string homeState = argv[1];
    State home = State(homeState);
    string salary = argv[2];
    string jobTitle = argv[3];
    int avgSalary = 0;//home.getJob().getSalary();
    cout << "Your states average salary is $" << avgSalary;
    if (avgSalary > stoi(salary)) {
        cout << ", which is higher than your salary. You may want to look for better offers in the area." << endl;
    }
    else {
        cout << ", which is lower than your salary, your job is a keeper!" << endl;
    }
}

void evaluateDialog() {
    return;
}

int main(int argc, char* argv[]) {
   /* //Testing Jobs functions
    Jobs jobtest;
    cout << "testing..." << endl;
    jobtest.setStateName("Alabama");
    vector<string> test = jobtest.getMajorJobs();
    for(int x = 0; x < test.size(); x++){
        cout << test.at(x) << endl;
    }
*/


    if (argc == 0) {
        helpDialog();
    }
    else if (argv[0] == "!SC") {
        compareDialog(argc, argv);
    }
    else if (argv[0] == "!SP") {
        takeHomeDialog(argc, argv);
    }
    else if (argv[0] == "!SE") {
        evaluateDialog();
    }
    else {
        helpDialog();
    }
    return 0;
}