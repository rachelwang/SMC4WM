#include "BN.h"
#include<string.h>


BN::BN()
{
}

void BN::get_cpd_info()
{
	for (int i = 0; i < cpd_list.size(); i++)
	{
		cout << "cpd:" << cpd_list[i].cpd_name << "\nfathers:";
		/**/
		cout<< cpd_list[i].evidence_num<<endl;
		for (int j = 0; j < cpd_list[i].evidence.size(); j++)
		{
			cout << cpd_list[i].evidence[j] << " ";
		}
		cout << "\n";
	}
}

void BN::add_cpds(int cpd_num, vector<CPD>temp_cpd)
{
	int cpd_loc;
	for (int i = 0; i < cpd_num; i++)
	{
		cpd_loc = cpd_map[temp_cpd[i].cpd_name];
		cpd_list[cpd_loc] = temp_cpd[i];
	}
	//delete []temp_list;
}

double BN::query_joint(map<string, int> evidence)
{
	if (model_checked == false)
	{
		cout << "Please check the bayesianmodel!" << "\n";
		return 0;
	}
	int cpd_num = cpd_list.size();
	int flag_sufficient_evidence = 0;
	double result = 0;
	map<string, int>temp_evidence;
	temp_evidence = evidence;
	for (int i = 0; i < cpd_num; i++)
	{
		if (evidence.find(cpd_list[i].cpd_name) == evidence.end())
		{
			for (int j = 0; j < cpd_list[i].variable_card; j++)
			{

				if (j == 0)
					temp_evidence.insert(pair<string, int>(cpd_list[i].cpd_name, j));
				else temp_evidence[cpd_list[i].cpd_name] = j;
				result += query_joint(temp_evidence);
			}
			map<string, int>().swap(temp_evidence);
			//evidence.swap(map<string, int>());
			return result;
		}
	}
	map<string, int>().swap(temp_evidence);
	//evidence.swap(map<string, int>());
	return query_all_cpd(evidence);
}

bool BN::check_model()
{
	int error_checked = 0;
	int cpd_num = cpd_list.size();
	if (cpd_num == 0)
	{
		cout << "Please add CPDs first!" << "\n";
		return 0;
	}
	//cout<<"Checking the model" << "\n";
	//
	/*
	for (int i = 0; i < cpd_num; i++)
	{
	if (error_checked > 0)break;
	for (int j = 0; j < cpd_list[i].father_name.size(); j++)
	{
	if (find(cpd_list[i].evidence.begin(), cpd_list[i].evidence.end(), cpd_list[i].father_name[j]) == cpd_list[i].evidence.end())
	{
	error_checked = 1;
	break;
	}
	}
	for (int j = 0; j < cpd_list[i].evidence.size(); j++)
	{
	if (find(cpd_list[i].father_name.begin(), cpd_list[i].father_name.end(), cpd_list[i].evidence[j]) == cpd_list[i].father_name.end())
	{
	error_checked = 1;
	break;
	}
	}
	}
	*/
	//
	if (error_checked == 0)
	{
		bool *flag = new bool[cpd_num];
		for (int i = 0; i < cpd_num; i++)
		{
			flag[i] = 0;
		}
		for (int i = 0; i < cpd_num; i++)
		{
			memset(flag_loop, 0, sizeof(flag_loop));
			if (check_loop(i) == 1)
				error_checked = 2;
		}
	}
	//
	double sum_possible;
	int situation_num;
	for (int i = 0; i < cpd_num; i++)
	{
		if (error_checked > 0)break;
		situation_num = 1;
		if (cpd_list[i].cpd_type == 3)
		{
			for (int j = 0; j < cpd_list[i].evidence_num; j++)
			{
				if (cpd_list[cpd_map[cpd_list[i].evidence[j]]].cpd_type == 4)
				{
					error_checked = 4;
					break;
				}
			}
			if (cpd_list[i].values.size() == 0)
			{
				for (int j = 0; j < cpd_list[i].variable_card; j++)
				{
					vector<double>temp;
					temp.push_back(1 / double(cpd_list[i].variable_card));
					cpd_list[i].values.push_back(temp);
				}
			}
			for (int j = 0; j < cpd_list[i].evidence_num; j++)
			{
				situation_num *= cpd_list[i].evidence_card[j];
			}
			for (int j = 0; j < situation_num; j++)
			{
				sum_possible = 0;
				for (int k = 0; k < cpd_list[i].variable_card; k++)
				{
					sum_possible += cpd_list[i].values[k][j];
				}
				if (sum_possible > 1.0 + 0.0000001 || sum_possible < 1.0 - 0.0000001)
				{
					error_checked = 3;
					break;
				}
			}
		}
	}

	switch (error_checked)
	{
	case 1:
		cout << "error:Graph structure and CPD information do not match" << "\n";
		break;
	case 2:
		cout << "error:There is a loop in the graph structure" << "\n";
		break;
	case 3:
		cout << "error:Illegal input of values" << "\n";
		break;
	case 4:
		cout << "error:continuous CPDs can not have discrete child" << "\n";
		break;
	default:
		//cout << "Model Checkeed" << "\n";
		model_checked = true;
		break;
	}
	if (error_checked > 0)return 1;
	else return 0;
}

void BN::add_edge(CPD cpd_fa, CPD cpd_son)
{

	if (this->cpd_map.find(cpd_fa.cpd_name) == this->cpd_map.end())
	{
		this->cpd_list.push_back(cpd_fa);
		this->cpd_map.insert(pair<string, int>(cpd_fa.cpd_name, cpd_list.size() - 1));
	}
	if (this->cpd_map.find(cpd_son.cpd_name) == this->cpd_map.end())
	{
		this->cpd_list.push_back(cpd_son);
		this->cpd_map.insert(pair<string, int>(cpd_son.cpd_name, cpd_list.size() - 1));
	}
	cpd_list[cpd_map[cpd_fa.cpd_name]].variable_card = cpd_fa.variable_card;
	cpd_list[cpd_map[cpd_son.cpd_name]].evidence_num += 1;
	cpd_list[cpd_map[cpd_son.cpd_name]].evidence.push_back(cpd_fa.cpd_name);
	cpd_list[cpd_map[cpd_son.cpd_name]].evidence_card.push_back(cpd_fa.variable_card);
}

double BN::query_discrete_cpd(CPD cpd_temp, map<string, double> evidence)
{
	int values_num = 1;
	int values_loc = 0;
	int father_num = cpd_temp.evidence_num;
	for (int i = 0; i < father_num; i++)
	{
		values_num *= cpd_temp.evidence_card[i];
	}
	for (int i = 0; i < father_num; i++)
	{
		string f_name = cpd_temp.evidence[i];
		values_num /= cpd_temp.evidence_card[i];
		values_loc += int(evidence[f_name]) * values_num;
	}
	return cpd_temp.values[int(evidence[cpd_temp.cpd_name])][values_loc];/**/
}
double BN::query_continuous_cpd(CPD cpd_temp, map<string, double>evidence)
{
	int father_num = cpd_temp.evidence_num;
	double mean = cpd_temp.weights[0];
	for (int i = 0; i < father_num; i++)
	{
		string f_name = cpd_temp.evidence[i];
		mean += cpd_temp.weights[i + 1] * evidence[f_name];
	}
	return mean;
}

double BN::query_all_cpd(map<string, int> evidence)
{
	double possibility = 1;
	for (int i = 0; i < cpd_list.size(); i++)
	{
		CPD cpd_temp = cpd_list[i];
		map<string, double>evidence_temp;
		evidence_temp.insert(pair<string, double>(cpd_temp.cpd_name, evidence[cpd_temp.cpd_name]));
		for (int j = 0; j < cpd_list[i].evidence_num; j++)
		{
			evidence_temp.insert(pair<string, double>(cpd_list[i].evidence[j], evidence[cpd_list[i].evidence[j]]));
		}
		possibility *= query_discrete_cpd(cpd_temp, evidence_temp);
		cout << query_discrete_cpd(cpd_temp, evidence_temp) << endl;
		map<string, double>().swap(evidence_temp);
		//cout << cpd_temp.variable << " " << query_discrete_cpd(cpd_temp, evidence_temp) <<" "<< possibility<< "\n";
	}
	map<string, int>().swap(evidence);
	return possibility;
}

bool BN::check_loop(int beg)
{
	int result = 0;
	if (flag_loop[beg] == 1)
		return 1;
	else
	{
		for (int i = 0; i < cpd_list[beg].evidence_num; i++)
		{
			int next = cpd_map[cpd_list[beg].evidence[i]];
			flag_loop[beg] = 1;
			result = check_loop(next);
			flag_loop[next] = 0;
			if (result == 1)
				break;
		}
		return result;
	}
}
void BN::readUAI(string filename)
{
	string type;
	ifstream infile(filename);
	//if (!infile) cout << "error" << endl;
	int num_variables;
	string tmp_string;
	infile >> tmp_string;
	//cout << tmp_string << endl;
	if (tmp_string.compare("BAYES") == 0)
	{
		type = "BAYES";
	}
	else if (tmp_string.compare("MARKOV") == 0)
	{
		type = "MARKOV";
	}
	if (type.compare("BAYES") == 0)
	{
		//cout << "Reading Bayesian Network\n";
		infile >> num_variables;

		vector<CPD>cpds;
		vector<int> func_order;
		for (int i = 0; i < num_variables; i++)
		{
			CPD temp_cpd;
			int variable_card;
			infile >> variable_card;
			temp_cpd.variable_card = variable_card;
			temp_cpd.cpd_name = to_string(i);
			if (variable_card != 0)
			{
				temp_cpd.cpd_type = 3;
			}
			else temp_cpd.cpd_type = 4;
			cpds.push_back(temp_cpd);

		}
		int num_functions;
		infile >> num_functions;

		for (int i = 0; i < num_functions; i++)
		{
			int num_cpds;
			infile >> num_cpds;
			vector<int>cpd_var;
			for (int j = 0; j < num_cpds; j++)
			{
				int temp;
				infile >> temp;
				cpd_var.push_back(temp);
			}
			num_cpds--;
			func_order.push_back(cpd_var[num_cpds]);
			for (int j = 0; j < num_cpds; j++)
			{
				this->add_edge(cpds[cpd_var[j]], cpds[cpd_var[num_cpds]]);
				//<<cpd_var[j]<<" "<< cpd_var[num_cpds]<<endl;
			}

		}
		//get_cpd_info();
		for (int i = 0; i < num_variables; i++)
		{
			int var1 = i;
			int num_probabilities;
			double temp_double;
			infile >> num_probabilities;
			if (this->cpd_list[i].variable_card > 0)
			{
				vector<double>values(num_probabilities);
				for (int j = 0; j < num_probabilities; j++)
				{
					infile >> values[j];
				}
				this->cpd_list[i].setValues(values);
			}
			else
			{
				for (int j = 0; j < num_probabilities - 1; j++)
				{

					infile >> temp_double;
					this->cpd_list[i].weights.push_back(temp_double);
				}
				infile >> temp_double;
				this->cpd_list[i].var = temp_double;
			}
		}
		this->check_model();
		infile.close();
	}
}
