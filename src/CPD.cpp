#include "CPD.h"

CPD::CPD()
{
this->variable_card = 0;
	this->evidence_num = 0;
}
void CPD::set_cpd_info(string function_str)
{
	Tools strT;
	vector<string>temp;
	if (cpd_type == 1)
	{
		temp = strT.split(function_str, ",");
		var = atof(temp[1].c_str());
		function_str = temp[0];
		temp.clear();
	}
	temp = strT.split(function_str, "=");
	function_str = temp[1] + "#";
	getPostfix(function_str);
}
void CPD::get_cpd_info()
{
	cout << cpd_name << endl;
	cout << cpd_type << endl;
	if (cpd_type <= 2)
	{
		for (int i = 0; i < Postfix.size(); i++)
		{
			if (Postfix[i].type == 0)
				cout << Postfix[i].name << " ";
			else if (Postfix[i].type == 1)
				cout << Postfix[i].value << " ";
			else if (Postfix[i].type == 2)
				cout << Postfix[i].op << " ";
		}
		cout << endl;
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
		cout << "var:" << var << endl; cout << endl;
	}
}
void CPD::Pushn(string ss)
{
	Tools strT;
	Operator temp_num;
	if (strT.isVariable(ss))
	{
		temp_num.name = ss;
		temp_num.type = 0;
	}
	else
	{
		temp_num.value = atof(ss.c_str());
		temp_num.type = 1;
	}
	Postfix.push_back(temp_num);
}
void CPD::getPostfix(string InfixExp)
{
	//cout << InfixExp << endl;
	Tools strT;
	stack<char>mystack;
	int len = InfixExp.length();
	int i = 0;
	char ch;
	string var_temp = "";
	while (i < len)
	{
		ch = InfixExp[i];
		i++;
		if (!strT.isOperator(ch))
		{
			var_temp += ch;
		}
		else
		{
			if (var_temp != "")
			{
				Pushn(var_temp);
				var_temp = "";
			}
			if (ch == '#')break;
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
						Postfix.push_back(op_temp);
						mystack.pop();
					}
					mystack.push(ch);
				}
				else mystack.push(ch);
			}
			else if(ch == ')')
			{
				while ((!mystack.empty()) && (mystack.top() != '('))
				{
					Operator op_temp;
					op_temp.op = mystack.top();
					op_temp.type = 2;
					Postfix.push_back(op_temp);
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
		Postfix.push_back(op_temp);
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
		vector<double>vec_temp;
		for (int j = 0; j < matrix_columns_num; j++)
		{
			int temp_num = j * variable_card + i;
			vec_temp.push_back(temp_values[temp_num]);
		}
		this->values.push_back(vec_temp);
		vector<double>().swap(vec_temp);
	}
}
