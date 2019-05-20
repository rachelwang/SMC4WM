#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Tools.h"
#include <string>
using namespace std;
class BooleanNet :private Tools
{
private:
    void getData(string);
    int getVarInd(string);
    int setVar(string);
    vector<vector <int> >getOneTrace(vector<vector <string> >);
public:
    BooleanNet(string);
    BooleanNet();
    string getVar(int );
    void showTraces();
    void addVarder(string );
    int sampleNum;
    int varriableNum;
    int sampleLength;
    vector<vector<vector<int> > > traces;
    vector<string> varriableList;
    ~BooleanNet();
};

