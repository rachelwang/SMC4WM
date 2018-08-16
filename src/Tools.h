#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>

#include <stdlib.h>
#include <string.h>
#include <map>
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
	int RandomChosse(vector<double>);
	int randomint(int min, int max);
	vector<string> merge_v(vector<string> v1, vector<string> v2);
	void insert_v(vector<string> &v1, string t);
	double gaussrand();
	void creatFolder(string);
	double randomfloat(double min, double max);
	map<string, string> getArgvMap(int argc, char **argv);
	char ops[7] = {'+', '-', '*', '/', '#', '(', ')'};
	int cmp[4][4] = {
		{2, 2, 1, 1},
		{2, 2, 1, 1},
		{2, 2, 2, 2},
		{2, 2, 2, 2},
	};
	string USAGE =

		"\nUsage: SMC_wm -testfile <testfile> -modelfile <modelfile> -propfile <propertyfile> -interfile <interventionfile> -getstruct <getstruct>\n\n"
		"where:\n"
		"      <testfile> is a text file containing a sequence of test specifications, give the path to it;\n"
		"      <modelfile> is the file name and path of the WM model under analysis;\n"
		"      <propertyfile> is the file name and path of properties to be checked.\n"
		"      <interventionfile> is the file name and path of interventions. This is optional"
		"      <getstruct> whether to use tetrat to get the structure of DBN. 'true' or 'false. This is optional"
		"Available test specifications: \n\n"
		"Hypothesis test:\n"
		" Lai's test: Lai <theta> <cost per sample>\n"
		" Bayes Factor test: BFT <theta> <threshold T> <alpha> <beta>\n"
		" Sequential Probability Ratio Test: SPRT <theta> <threshold T> <indifference region delta>\n"
		" Bayes Factor test with indifference region: BFTI <theta> <threshold T> <alpha> <beta> <indifference region delta>\n"
		"\n"
		"Estimation methods:\n"
		" Chernoff-Hoeffding bound: CHB <delta> <coverage probability>\n"
		" Bayesian estimation: BEST <delta> <coverage probability> <alpha> <beta>\n"
		"\n"
		"Sampling method:\n"
		" Naive sampling: NSAM <#samples> \n\n"
		"Empty lines and lines beginning with '#' are ignored.\n"
		"";
};
