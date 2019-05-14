#pragma once
#include"DBN.h"
#include"BN.h"
#include"CPD.h"
#include"linearEquation.h"
#include<fstream>
class Sampler :private Tools
{
public:
	Sampler();
	Sampler(string filename, string interfile);
	int NOW;
	int NEXT;

	DBN net_DBN;
	BN net_BN;
	int sampler_type; //0:BN  1:DBN
	double value[2][1000];
	int variable_num;
	void get_one_sample();
	int sample_size;
	vector<string>cpd_order;
	void saveSampleResult(string);
	void getInital(string initfile);
	double getResult(string v, int n);
	int getVariableX(string v);
	vector<double> getLikehood(vector<double>);
	vector<vector<double> >all_results;
	void getBackwardSample();
	void getForwardSample();
	void resetBeta();
	void setMatrix();
private:
	int flag[1000];
	double Calculate(int cpd_index);
    double get_beta_value(vector<double>, vector<double>);
	int judge_file_type(string);
	map<string, double>evidence;
	void checkSampleResult(string);
    string getNamefromInit(string);
	vector<vector<double> > CM;
	vector<double>var;
    linearEquation LE;
	int flagLR[1000];
};

