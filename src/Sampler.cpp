#include "Sampler.h"

Sampler::Sampler()
{
}

Sampler::Sampler(string filename, string interfile)
{
	this->NOW = 0;
	this->NEXT = 1;
	this->sample_size = 0;
	sampler_type = judge_file_type(filename);
	if (sampler_type == 1)
	{
		this->net_DBN.load_network(filename);
		this->net_DBN.getIntervention(interfile);
		this->variable_num = this->net_DBN.cpd_list.size();
		for (int i = 0; i < this->variable_num; i++)
		{
			cpd_order.push_back(net_DBN.cpd_list[i].cpd_name);
			if (this->net_DBN.cpd_list[i].cpd_type != 2)
			{
				string::size_type nPos2 = 0;
				nPos2 = this->net_DBN.cpd_list[i].cpd_name.find("'", nPos2);
				if (nPos2 != string::npos)
				{
					this->value[NOW][i] = 1;
				}
				else
					this->value[NOW][i] = 100;
			}
			else
			{
				this->value[NOW][i] = get_beta_value(net_DBN.cpd_list[i].beta_v, net_DBN.cpd_list[i].beta_p);
			}
		}
	}
	else if (sampler_type == 0)
	{

		this->net_BN.readUAI(filename);
		this->variable_num = this->net_BN.cpd_list.size();
		for (int i = 0; i < this->variable_num; i++)
		{
			cpd_order.push_back(net_BN.cpd_list[i].cpd_name);
			if (net_BN.cpd_list[i].cpd_type == 3)
			{
				this->value[NOW][i] = randomint(0, net_BN.cpd_list[i].variable_card);
			}
			else if (net_BN.cpd_list[i].cpd_type == 4)
			{
				this->value[NOW][i] = net_BN.cpd_list[i].weights[0];
			}
			evidence.insert(pair<string, double>(net_BN.cpd_list[i].cpd_name, value[NOW][i]));
		}
	}
}

void Sampler::get_one_sample()
{
	vector<double> one_sample;
	if (sampler_type == 1)
	{
		for (int i = 0; i < variable_num; i++)
			flag[i] = 0;

		for (int i = 0; i < variable_num; i++)
		{
			if (flag[i] == 1)
				continue;
			value[NEXT][i] = Calculate(i);
			one_sample.push_back(value[NEXT][i]);
		}
		int t = NOW;
		NOW = NEXT;
		NEXT = t;
	}
	else if (sampler_type == 0)
	{
		for (int i = 0; i < variable_num; i++)
		{
			value[NOW][i] = Calculate(i);
			one_sample.push_back(value[NOW][i]);
		}
	}
	all_results.push_back(one_sample);
	one_sample.clear();
	sample_size++;
}

double Sampler::Calculate(int cpd_index)
{
	int type;
	if (sampler_type == 0)
		type = net_BN.cpd_list[cpd_index].cpd_type;
	else
		type = net_DBN.cpd_list[cpd_index].cpd_type;
	if (type <= 2)
	{
		if (type == 2)
		{
			flag[cpd_index] = 1;
			return value[NOW][cpd_index];
		}
		stack<double> result;
        int inter_index = -1;
		for (int i = net_DBN.cpd_list[cpd_index].intervention.size() - 1; i >= 0; i--)
		{
			if (net_DBN.cpd_list[cpd_index].intervention[i].begin_t <= sample_size && (net_DBN.cpd_list[cpd_index].intervention[i].end_t > sample_size||net_DBN.cpd_list[cpd_index].intervention[i].end_t<0))
			{
				inter_index = i;
				net_DBN.cpd_list[cpd_index].cpd_type = net_DBN.cpd_list[cpd_index].intervention[i].func_type;
				net_DBN.cpd_list[cpd_index].var = net_DBN.cpd_list[cpd_index].intervention[i].var;
				break;
			}
		}
        //cout<<"inter:"<<inter_index<<endl;
		//net_DBN.cpd_list[cpd_index].get_cpd_info();
		if (inter_index == -1)
		{
			return value[NOW][cpd_index];
		}
		

		for (int i = 0; i < net_DBN.cpd_list[cpd_index].intervention[inter_index].Postfix.size(); i++)
		{
			if (net_DBN.cpd_list[cpd_index].intervention[inter_index].Postfix[i].type == 0)
			{
				string var_name = net_DBN.cpd_list[cpd_index].intervention[inter_index].Postfix[i].name;
				int temp_index;
				string::size_type nPos2 = 0;
				nPos2 = var_name.find("_next", nPos2);

				if (nPos2 == string::npos)
				{
					temp_index = net_DBN.cpd_map[var_name];
					result.push(value[NOW][temp_index]);
				}
				else
				{
					string_replace(var_name, "_next", "");
					temp_index = net_DBN.cpd_map[var_name];
					if (flag[temp_index] == 0)
					{
						result.push(Calculate(temp_index));
					}
					else
					{
						result.push(value[NEXT][temp_index]);
					}
				}
			}
			else if (net_DBN.cpd_list[cpd_index].intervention[inter_index].Postfix[i].type == 1)
			{
				result.push(net_DBN.cpd_list[cpd_index].intervention[inter_index].Postfix[i].value);
			}
			else
			{
				double t_a = result.top();
				result.pop();
				double t_b = result.top();
				result.pop();
				double t_r = Execute(t_a, net_DBN.cpd_list[cpd_index].intervention[inter_index].Postfix[i].op, t_b);
				result.push(t_r);
			}
		}
		value[NEXT][cpd_index] =
			flag[cpd_index] = 1;
		if (type == 0)
		{
			value[NEXT][cpd_index] = result.top();
			return result.top();
		}
		else
		{
			double rand = net_DBN.cpd_list[cpd_index].var * gaussrand();
			value[NEXT][cpd_index] = result.top() + rand;
			//cout << result.top() << " " << rand << endl;
			return result.top() + rand;
		}
	}
	else if (type == 3)
	{
		double most_possible_result;
		vector<double> possible_list;
		for (int i = 0; i < net_BN.cpd_list[cpd_index].variable_card; i++)
		{
			evidence[net_BN.cpd_list[cpd_index].cpd_name] = i;
			possible_list.push_back(net_BN.query_discrete_cpd(net_BN.cpd_list[cpd_index], evidence));
		}
		return double(RandomChosse(possible_list));
	}
	else
	{
		double mean = net_BN.query_continuous_cpd(net_BN.cpd_list[cpd_index], evidence);
		double var = net_BN.cpd_list[cpd_index].var;
		return gaussrand() * var + mean;
	}
}

double Sampler::get_beta_value(vector<double> beta_value, vector<double> possiblelist)
{
	double sumpossible = 0.0;
	double randomfloatnum = randomfloat(0, 1);
	int result;
	for (int i = 0; i < possiblelist.size(); i++)
	{
		sumpossible += possiblelist[i];
	}
	randomfloatnum *= sumpossible;
	for (int i = 0; i < possiblelist.size(); i++)
	{
		randomfloatnum -= possiblelist[i];
		if (randomfloatnum < 0)
		{
			result = i;
			break;
		}
		result = possiblelist.size() - 1;
	}
	double max = beta_value[result];
	double min = beta_value[result - 1];
	return randomfloat(min, max);
}

int Sampler::judge_file_type(string filename)
{
	ifstream fin(filename);
	string ss;
	fin >> ss;
	fin.close();
	//cout << ss << endl;
	if (ss == "BAYES")
		return 0;
	else
		return 1;
}
void Sampler::saveSampleResult(string filename)
{
	ofstream file_out(filename);
	for (int i = 0; i < cpd_order.size(); i++)
	{
		file_out << cpd_order[i];
		if (i < cpd_order.size() - 1)
			file_out << ",";
	}
	file_out << endl;
	for (int i = 0; i < sample_size; i++)
	{
		for (int j = 0; j < cpd_order.size(); j++)
		{
			file_out << all_results[i][j];
			if (j < cpd_order.size() - 1)
				file_out << ",";
		}
		file_out << endl;
	}
	file_out.close();
	all_results.clear();
}
void Sampler::checkSampleResult(string filename)
{
}
