#pragma once
#include "Tools.h"
#include <stack>
#include <set>
#include <algorithm>
class CPD : public Tools
{
public:
	CPD();

	string cpd_name;
	int cpd_type; // 0：普通连续 1：动态、高斯、连续 2：beta 3,：静态离散 4：静态高斯连续
	vector<double> beta_p;
	vector<double> beta_v;
	double betaExpexted;
	double var; //静态/高斯 方差
	struct Operator
	{
		string name;
		double value;
		char op;
		int type; // variable:0 num: 1 operator:2
	};
	struct Operation
	{
		int begin_t;
		int end_t;
		int func_type; // 0：普通连续 1：动态、高斯、连续
		double var;
		vector<Operator> Postfix;
	};
	vector<Operation> intervention;
	void set_cpd_info(int e_t, int b_t, string, int func_type);
	void get_cpd_info();
	void getPostfix(string InfixExp, vector<Operator> &post_temp);
	//bool comp(const Operation &a, const Operation &b);
	void sort_intervention();
	int variable_card;
	int evidence_num;
	vector<vector<double > > values;
	vector<string> evidence;
	vector<int> evidence_card;
	void setValues(vector<double> temp_values);
	vector<double> weights;
	void getExpectedBeta();
	void setRange(string);
	bool inRange(double);
	double rangeL;
	double rangeR;
	bool haveRange;
	struct parentNode
	{
	    double c;
		  string beta;
		  string name;
		  int type; // 0: c is a number; 1: c is a beta variable; 2: constant number.
	};
	vector<parentNode> pns;
	void getParentNodes(string);
	void setBetaPN();

private:
	void Pushn(string ss, vector<Operator> &post_temp);
};
