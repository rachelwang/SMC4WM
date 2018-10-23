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
void DBN::add_intervention(int b_t, int e_t, string inter_str, int func_type)
{

	vector<string> s_temp_v = split(inter_str, "=");
	int nPos1 = 0;
	nPos1 = s_temp_v[0].find("(t)", nPos1);
	if (nPos1 != string::npos)
	{
		string_replace(s_temp_v[0], "(t)", "(t+1)");
		string_replace(s_temp_v[1], "(t)", "(t+1)");
	}
	string_replace(s_temp_v[0], "(t+1)", "");
	string_replace(s_temp_v[1], "(t+1)", "_next");
	string_replace(s_temp_v[1], "(t)", "");

	int cpd_ind = cpd_map[s_temp_v[0]];
	s_temp_v[1] = s_temp_v[0]+"_next="+s_temp_v[1];
	//cout << b_t << " " << e_t << " " << s_temp_v[1] << " " << func_type << endl;
	
	cpd_list[cpd_ind].set_cpd_info(b_t, e_t, s_temp_v[1], func_type);
}
void DBN::getIntervention(string filename)
{
	ifstream fin(filename);
	if(!fin)return;
	string s;
	int t_last = 0;
	string::size_type nPos1 = 0;
	string::size_type nPos2 = 0;
	int begin_time;
	int end_time;
	while (fin >> s)
	{

		int function_type = 0;
		string function_str = "";
		if (s == "for")
		{
			string s2;

			int num_d = 0;
			for (int i = 0; i < 8; i++)
			{
				fin >> s;
				string s_temp = s;
				string_replace(s_temp, ":", "");
				
				nPos1 = 0;
				nPos1 = s.find("..", nPos1);
				if (nPos1 != string::npos)
				{
					vector<string> vsTemp;
					vsTemp = split(s_temp,"..");
					begin_time = atoi(vsTemp[0].c_str());
					if(vsTemp[1]=="max")end_time = -1;
					else end_time = atoi(vsTemp[1].c_str());
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
			t_last = 0;
			vector<string> s_temp_v1;
			vector<string> s_temp_v2;
			function_str = "";
			function_str += s;
			string s2;
			while (fin >> s2)
			{
				nPos1 = 0;
				nPos1 = s2.find(";", nPos1);
				function_str += s2;
				if (nPos1 != string::npos)
					break;
			}
			string_replace(function_str, ";", "");
			if (function_str[0] == 'G')
			{
				if (function_str[1] != '[')
				{
					t_last = -1;
					string_replace(function_str, "G", "");
					string_replace(function_str, " ", "");
					s_temp = function_str;
				}
				else
				{
					s_temp_v1 = split(function_str, "]");
					s_temp_v2 = split(s_temp_v1[0], "[");
					t_last = atoi(s_temp_v2[1].c_str());
					s_temp = s_temp_v1[1];
				}

				function_str = "";
				s_temp_v2.clear();
				s_temp_v2 = split(s_temp, "(");
				//cout<<s_temp_v2.size()<<endl;
				function_str += s_temp_v2[0];
				s_temp = "";
				for (int k = 1; k < s_temp_v2.size(); k++)
					s_temp += s_temp_v2[k];
				s_temp_v2.clear(); //cout<<s_temp<<endl;
				s_temp_v2 = split(s_temp, ")");
				begin_time = atoi(s_temp_v2[0].c_str());
				function_str += "(t+1)" + s_temp_v2[1];
				//begin_time = 0;
			}
			else
			{
				s_temp_v1.clear();
				s_temp_v1 = split(function_str, "(");
				function_str = s_temp_v1[0];
				s_temp_v2.clear();
				s_temp_v2 = split(s_temp_v1[1], ")");
				begin_time = atoi(s_temp_v2[0].c_str());
				function_str += "(t+1)" + s_temp_v2[1];
				t_last = 1;
			}
			if (t_last == -1)
				end_time = -1;
			else
				end_time = begin_time + t_last;
		}

		//cout << t_last << endl;
		//cout << function_str << endl;
		//cout << begin_time << " " << end_time << " " << function_type << " " << function_str << endl;
		
		add_intervention(begin_time,end_time,function_str,function_type);
		for(int i=0;i<cpd_list.size();i++)
		{
			cpd_list[i].sort_intervention();
		}

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
			cpd_list[cpd_index].set_cpd_info(0, -1, function_str, function_type);
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
