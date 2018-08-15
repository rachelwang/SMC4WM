#include "DBN.h"
DBN::DBN()
{
}
void DBN::get_network_info()
{
	for (int i = 0; i < cpd_list.size(); i++)
	{
		cpd_list[i].get_cpd_info();
	}
}
DBN::DBN(string filename)
{
	load_network(filename);
}
void DBN::getIntervention(string filename)
{
	ifstream fin(filename);
	string s;
	string::size_type nPos1 = 0;
	string::size_type nPos2 = 0;
	int begin_time;
	int end_time;
	while (fin >> s)
	{
		cout<<s<<endl;
		int function_type = 0;
		string function_str = "";
		if (s == "From")
		{
			string s2;

			int num_d = 0;
			for (int i = 0; i < 8; i++)
			{
				fin >> s;
				string s_temp = s;
				string_replace(s_temp, ":", "");
				string_replace(s_temp, "=", "");
				string_replace(s_temp, "t", "");
				if (isVariable(s_temp) == false && s_temp != "")
				{
					num_d += 1;
					if (num_d == 1)
						begin_time = atoi(s_temp.c_str());
					else
						end_time = atoi(s_temp.c_str());
				}
				nPos1 = 0;
				nPos1 = s.find(":", nPos1);
				if (nPos1 != string::npos)
				{
					break;
				}
			}
			while (fin >> s2)
			{
				nPos1 = 0;
				nPos1 = s2.find(";", nPos1);
				nPos2 = 0;
				nPos2 = s2.find("Normal", nPos2);
				if (nPos2 != string::npos)
				{
					string temp = "Normal(";
					string_replace(s2, temp, " ");
					function_type = 1;
					function_str += s2;
				}
				else if (nPos1 != string::npos)
				{
					if (function_type == 1)
						string_replace(s2, ");", "");
					else
						string_replace(s2, ";", "");
					function_str += s2;
					break;
				}
				else
				{
					function_str += s2;
					string_replace(s2, ",", "");
				}
			}
		}
		else
		{
			string s_temp = s;
			function_str+=s;
			string s2;
			while (fin >> s2)
			{
				nPos1 = 0;
				nPos1 = s2.find(";", nPos1);
				function_str+=s2;
				if (nPos1 != string::npos)
				    break;
			}
			cout<<function_str<<endl;
			if(function_str[0]=='G')
			{

			}
			else
			{

			}
			function_str +=s;
		}
		cout << begin_time << " " << end_time << " " <<function_str << endl;
	}
}
void DBN::load_network(string filename)
{

	ifstream fin(filename);
	string s;
	string::size_type nPos1 = 0;
	string::size_type nPos2 = 0;
	while (fin >> s)
	{
		if (s == "random")
		{
			fin >> s;
			CPD cpd_temp;
			cpd_temp.cpd_name = s;
			nPos1 = 0;
			nPos1 = s.find("beta", nPos1);
			if (nPos1 == string::npos)
				cpd_temp.cpd_type = 0;
			else
				cpd_temp.cpd_type = 2;
			cpd_list.push_back(cpd_temp);
			cpd_map.insert(pair<string, int>(s, cpd_list.size() - 1));
		}
		else if (s == "for")
		{
			string function_str = "";
			string s2;
			int function_type = 0;
			for (int i = 0; i < 5; i++)
				fin >> s;
			while (fin >> s2)
			{
				nPos1 = 0;
				nPos1 = s2.find(";", nPos1);
				nPos2 = 0;
				nPos2 = s2.find("Normal", nPos2);
				if (nPos2 != string::npos)
				{
					string temp = "Normal(";
					string_replace(s2, temp, " ");
					function_type = 1;
					function_str += s2;
				}
				else if (nPos1 != string::npos)
				{
					if (function_type == 1)
						string_replace(s2, ");", "");
					else
						string_replace(s2, ";", "");
					function_str += s2;
					break;
				}
				else
				{
					function_str += s2;
					string_replace(s2, ",", "");
				}
			}
			nPos1 = 0;
			nPos1 = function_str.find("(t)", nPos1);
			nPos2 = 0;
			nPos2 = function_str.find("=", nPos2);
			//cout << nPos1 <<" "<<nPos2<< endl;
			if (nPos1 != string::npos && nPos2 != string::npos && nPos1 < nPos2)
			{
				string_replace(function_str, "(t)", "_next");
			}
			else
			{
				string_replace(function_str, "(t+1)", "_next");
				string_replace(function_str, "(t)", "");
			}
			string_replace(function_str, " ", "");

			vector<string> str_temp = split(function_str, "=");
			string_replace(str_temp[0], "_next", "");
			int cpd_index = cpd_map[str_temp[0]];
			cpd_list[cpd_index].cpd_type = function_type;
			cpd_list[cpd_index].set_cpd_info(function_str);
		}
		else if (s == "if")
		{
			string str_beta[5];
			for (int i = 0; i < 5; i++)
			{
				fin >> str_beta[i];
			}
			for (int i = 0; i < cpd_list.size(); i++)
			{
				if (str_beta[0] == cpd_list[i].cpd_name)
				{
					cpd_list[i].beta_p.push_back(atof(str_beta[4].c_str()));
					cpd_list[i].beta_v.push_back(atof(str_beta[2].c_str()));
					break;
				}
			}
		}
	}
}
