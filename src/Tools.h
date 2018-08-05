#pragma once
#include<string>
#include<iostream>
#include<vector>
#include <random>
#include <ctime>
#include<cmath>

#include <stdlib.h>
#include <string.h>

#include <stdarg.h>
#include <sys/stat.h>
#include <unistd.h>


using namespace std;
class Tools
{
public:
	Tools();

	vector<string> split(string str, string pattern);
	void string_replace(std::string &strBig, const std::string &strsrc, const std::string &strdst);
	bool isVariable(string);
	bool isOperator(char);
	bool Compare(char, char);
	double Execute(double, char, double);
	int RandomChosse(vector<double> );
	int randomint(int min, int max);

	double gaussrand();
        void creatFolder(char *);
	double randomfloat(double min, double max);
	char ops[7] = { '+','-','*','/' ,'#','(',')'};
	int  cmp[4][4] = { { 2,2,1,1 },
	                   { 2,2,1,1 },
	                   { 2,2,2,2 },
	                   { 2,2,2,2 },
	                    };
};

