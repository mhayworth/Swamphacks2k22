//
// Created by Lisa Reichelson on 1/29/2022.
//
#include "Jobs.h"
#include <iostream>
#include <fstream>
using namespace std;

/*Jobs::Jobs(string stateName){
    this->state = stateName;
    initStatesOrder();
}*/
Jobs::Jobs(){
    initStatesOrder();
    //empty
}

void Jobs::setStateName(string stateName){
    this->state = stateName;
}


//access csv file, given state name, return all MajorJobs.
vector<string> Jobs::getMajorJobs(){
    string ident = statesOrder[this->state];
    string line;
    string currIdent = "00";
    ifstream myFile ("../Datasets/statesalaries.csv");
    if(myFile.is_open()){
        //while not at the correct state & more lines exist..
        while (getline (myFile, line) && currIdent != ident) {
            for (int i = 0; i < line.length(); i++) {
                if (line.at(i) == ',') { //first one defines the # state Identifier
                    currIdent = line.substr(0, i);
                    break;
                }
            }
        }
        // Now line should hold the first tuple of the correct state
        //Read until this isn't true anymore.
        vector<string> majors;
        //we have the whole line. we want to store the 9th and 10th indices.
        int currIndex = 0;
        int start = 0;
        vector<string> tempStore;
        for (int i = 0; i < line.length(); i++){
            if(line.at(i) == ','){
                if(currIndex == 9 || currIndex == 10) //stores job title & type for each line
                    tempStore.push_back(line.substr(start, i - start));
                currIndex++;
                start = i + 1;
            }
        }
        start = 0;
        currIndex = 0;
        //check if save this line's data
        if(tempStore.at(1) == "major")
            majors.push_back(tempStore.at(0));
        tempStore.clear();
        while (getline (myFile, line) && currIdent == ident){
            for (int i = 0; i < line.length(); i++){
                if(line.at(i) == ','){
                    if(currIndex == 0){
                        currIdent = line.substr(0, i);
                    }
                    if(currIndex == 9 || currIndex == 10) //stores job title & type for each line
                        tempStore.push_back(line.substr(start, i - start));
                    currIndex++;
                    start = i + 1;
                }
            }
            start = 0;
            currIndex = 0;
            if(tempStore.at(1) == "major") //check if save this line's data
                majors.push_back(tempStore.at(0));
            tempStore.clear();
        }
        return majors;
    }
}

vector<string> Jobs::getSubMajorJobs(string major){
    vector<string> temp;
    return temp;
}


void Jobs::initStatesOrder(){
    this->statesOrder["Alabama"] = "01";
    this->statesOrder["Alaska"] = "02";
    this->statesOrder["Arizona"] = "03";
    this->statesOrder["Arkansas"] = "04";
    this->statesOrder["California"] = "05";
    this->statesOrder["Colorado"] = "06";
    this->statesOrder["Connecticut"] = "07";
    this->statesOrder["Delaware"] = "08";
    this->statesOrder["Florida"] = "09";
    this->statesOrder["Georgia"] = "10";
    this->statesOrder["Hawaii"] = "11";
    this->statesOrder["Idaho"] = "12";
    this->statesOrder["Illinois"] = "13";
    this->statesOrder["Indiana"] = "14";
    this->statesOrder["Iowa"] = "15";
    this->statesOrder["Kansas"] = "16";
    this->statesOrder["Kentucky"] = "17";
    this->statesOrder["Louisiana"] = "18";
    this->statesOrder["Maine"] = "19";
    this->statesOrder["Maryland"] = "20";
    this->statesOrder["Massachusetts"] = "21";
    this->statesOrder["Michigan"] = "22";
    this->statesOrder["Minnesota"] = "23";
    this->statesOrder["Mississippi"] = "24";
    this->statesOrder["Missouri"] = "25";
    this->statesOrder["Montana"] = "26";
    this->statesOrder["Nebraska"] = "27";
    this->statesOrder["Nevada"] = "28";
    this->statesOrder["New Hampshire"] = "29";
    this->statesOrder["New Jersey"] = "30";
    this->statesOrder["New Mexico"] = "31";
    this->statesOrder["New York"] = "32";
    this->statesOrder["North Carolina"] = "33";
    this->statesOrder["North Dakota"] = "34";
    this->statesOrder["Ohio"] = "35";
    this->statesOrder["Oklahoma"] = "36";
    this->statesOrder["Oregon"] = "37";
    this->statesOrder["Pennsylvania"] = "38";
    this->statesOrder["Rhode Island"] = "39";
    this->statesOrder["South Carolina"] = "40";
    this->statesOrder["South Dakota"] = "41";
    this->statesOrder["Tennessee"] = "42";
    this->statesOrder["Texas"] = "43";
    this->statesOrder["Utah"] = "44";
    this->statesOrder["Vermont"] = "45";
    this->statesOrder["Virginia"] = "46";
    this->statesOrder["Washington"] = "47";
    this->statesOrder["West Virginia"] = "48";
    this->statesOrder["Wisconsin"] = "49";
    this->statesOrder["Wyoming"] = "50";
}



