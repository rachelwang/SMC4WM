#pragma once
#include"CPD.h"
#include<map>
#include<fstream>
using namespace std;
class BN
{
public:
	BN();
	void get_cpd_info();
	void add_cpds(int cpd_num, vector<CPD>temp_cpd);
	vector<CPD> cpd_list;
	map<string, int >cpd_map;

	double query_joint(map<string, int>evidence);
	bool model_checked;
	bool check_model();
	void add_edge(CPD cpd_fa, CPD cpd_son);
	double query_discrete_cpd(CPD cpd_temp, map<string, double>evidence);
	double query_continuous_cpd(CPD cpd_temp, map<string, double>evidence);

	void readUAI(string filename);
private:

	double query_all_cpd(map<string, int>evidence);
	bool check_loop(int beg);
	bool flag_loop[100000];
};

