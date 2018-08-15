#pragma once
#include"Tools.h"
#include<stack>
class CPD
{
public:
	CPD();
	int cpd_type;// 0：普通连续 1：动态、高斯、连续 2：beta 3,：静态离散 4：静态高斯连续
	string cpd_name;

	vector<double>beta_p;
	vector<double>beta_v;
	double var;
	struct Operator
	{
		string name;
		double value;
		char op;
		int type;// variable:0 num: 1 operator:2
	};
	vector<Operator>Postfix;
	void set_cpd_info(string);
	void get_cpd_info();
	void getPostfix(string InfixExp, vector<Operator>& post_temp);



	int variable_card;
	int evidence_num;
	vector<vector<double> > values;
	vector<string>evidence;
	vector<int>evidence_card;
	void setValues(vector<double> temp_values);
	vector<double>weights;
private:
	void Pushn(string);
};

