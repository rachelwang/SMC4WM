#pragma once
#include"CPD.h"
#include<map>
#include<fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
class DBN : public Tools
{
public:
	vector<char>operators;
	vector<CPD>cpd_list;
	map<string, int>cpd_map;
	DBN();
	DBN(string);
	void load_network(string);
	void getIntervention(string);
	void get_network_info();
};


