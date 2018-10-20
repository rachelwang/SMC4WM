#include "CPD.h"
bool comp(const CPD::Operation &a, const CPD::Operation &b){
     return a.begin_t < b.begin_t;
}
void CPD::sort_intervention()
{
	sort(intervention.begin(), intervention.end(), comp);
}
CPD::CPD()
{
	this->variable_card = 0;
	this->evidence_num = 0;
}
void CPD::set_cpd_info(int b_t, int e_t, string function_str,int func_type)
{
	Tools strT;
	Operation temp_o;
	vector<string> temp;
	temp_o.var = 0;
	if (func_type == 1)
	{
		temp = strT.split(function_str, ",");
		temp_o.var = atof(temp[1].c_str());
		function_str = temp[0];
		temp.clear();
	}
	temp = strT.split(function_str, "=");
	function_str = temp[1] + "#";
	
	temp_o.begin_t = b_t;
	temp_o.end_t = e_t;
	temp_o.func_type = func_type;
	getPostfix(function_str, temp_o.Postfix);
	intervention.push_back(temp_o);
}
void CPD::get_cpd_info()
{
	cout << cpd_name << endl;
	cout << cpd_type << endl;
	if (cpd_type <= 2)
	{
		for (int k = 0; k < intervention.size(); k++)
		{
			cout << intervention[k].begin_t << " " << intervention[k].end_t << endl;
			for (int i = 0; i < intervention[k].Postfix.size(); i++)
			{
				if (intervention[k].Postfix[i].type == 0)
					cout << intervention[k].Postfix[i].name << " ";
				else if (intervention[k].Postfix[i].type == 1)
					cout << intervention[k].Postfix[i].value << " ";
				else if (intervention[k].Postfix[i].type == 2)
					cout << intervention[k].Postfix[i].op << " ";
			}
			cout << endl;
		}
	}
	else if (cpd_type == 3)
	{
		cout << "variable: " << cpd_name << endl;
		cout << "variable_card: " << variable_card << endl;

		cout << "values: " << endl;
		for (int i = 0; i < values.size(); i++)
		{
			for (int j = 0; j < values[i].size(); j++)
			{
				cout << values[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "evidence_num: " << evidence_num << endl;
		for (int i = 0; i < evidence_num; i++)
		{
			cout << "evidence:" << evidence[i] << "   evidence_card:" << evidence_card[i] << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "weights:";
		for (int i = 0; i < weights.size(); i++)
		{
			cout << weights[i] << " ";
		}
		cout << "\n";
		cout << "var:" << var << endl;
		cout << endl;
	}
}
void CPD::Pushn(string ss, vector<Operator> &post_temp)
{
	Operator temp_num;
	if (isVariable(ss))
	{
		temp_num.name = ss;
		temp_num.type = 0;
	}
	else
	{
		temp_num.value = atof(ss.c_str());
		temp_num.type = 1;
	}
	post_temp.push_back(temp_num);
}
void CPD::getPostfix(string InfixExp, vector<Operator> &post_temp)
{
	//cout << InfixExp << endl;
	Tools strT;
	stack<char> mystack;
	int len = InfixExp.length();
	int i = 0;
	char ch;
	string var_temp = "";
	while (i < len)
	{
		ch = InfixExp[i];
		i++;
		if (!strT.isOperator(ch)||(ch=='-'&&(i==0||strT.isOperator(InfixExp[i]))))
		{
			var_temp += ch;
		}
		else
		{
			if (var_temp != "")
			{
				Pushn(var_temp, post_temp);
				var_temp = "";
			}
			if (ch == '#')
				break;
			if (mystack.empty() || mystack.top() == '(' || ch == '(')
				mystack.push(ch);
			else if (ch != ')')
			{
				if (strT.Compare(mystack.top(), ch))
				{
					while ((!mystack.empty()) && (strT.Compare(mystack.top(), ch)))
					{
						Operator op_temp;
						op_temp.op = mystack.top();
						op_temp.type = 2;
						post_temp.push_back(op_temp);
						mystack.pop();
					}
					mystack.push(ch);
				}
				else
					mystack.push(ch);
			}

			else if (ch == ')')
			{
				while ((!mystack.empty()) && (mystack.top() != '('))
				{
					Operator op_temp;
					op_temp.op = mystack.top();
					op_temp.type = 2;
					post_temp.push_back(op_temp);
					mystack.pop();
				}
				if ((!mystack.empty()) && (mystack.top() == '('))
					mystack.pop();
			}
			else
			{
				mystack.push(ch);
			}
		}
	}
	while (!mystack.empty())
	{
		Operator op_temp;
		op_temp.op = mystack.top();
		op_temp.type = 2;
		post_temp.push_back(op_temp);
		mystack.pop();
	}
}
void CPD::setValues(vector<double> temp_values)
{
	int matrix_columns_num = 1;
	for (int i = 0; i < evidence_num; i++)
	{
		matrix_columns_num *= evidence_card[i];
	}
	for (int i = 0; i < variable_card; i++)
	{
		vector<double> vec_temp;
		for (int j = 0; j < matrix_columns_num; j++)
		{
			int temp_num = j * variable_card + i;
			vec_temp.push_back(temp_values[temp_num]);
		}
		this->values.push_back(vec_temp);
		vector<double>().swap(vec_temp);
	}
}
