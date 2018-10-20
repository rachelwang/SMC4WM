#include "Tools.h"

Tools::Tools()
{
}
void Tools::creatFolder(string pDir)
{
	int i = 0;
	int iRet;
	int iLen;
	char *pszDir;

	pszDir = strdup(pDir.c_str());
	iLen = strlen(pszDir);

	// 创建中间目录
	for (i = 0; i < iLen; i++)
	{
		if (pszDir[i] == '\\' || pszDir[i] == '/')
		{
			pszDir[i] = '\0';

			//如果不存在,创建
			iRet = access(pszDir, 0);
			if (iRet != 0)
			{
				iRet = mkdir(pszDir, 0755);
			}
			//支持linux,将所有\换成/
			pszDir[i] = '/';
		}
	}

	iRet = mkdir(pszDir, 0755);
	free(pszDir);
}
vector<string> Tools::split(string str, string pattern)
{
	vector<string> ret;
	if (pattern.empty())
		return ret;
	size_t start = 0, index = str.find_first_of(pattern, 0);
	while (index != str.npos)
	{
		if (start != index)
			ret.push_back(str.substr(start, index - start));
		start = index + 1;
		index = str.find_first_of(pattern, start);
	}
	if (!str.substr(start).empty())
		ret.push_back(str.substr(start));
	return ret;
}
void Tools::string_replace(std::string &strBig, const std::string &strsrc, const std::string &strdst)
{
	std::string::size_type pos = 0;
	std::string::size_type srclen = strsrc.size();
	std::string::size_type dstlen = strdst.size();

	while ((pos = strBig.find(strsrc, pos)) != std::string::npos)
	{
		strBig.replace(pos, srclen, strdst);
		pos += dstlen;
	}
}

bool Tools::isVariable(string ss)
{
	char c = ss[0];
	if ((c < '0' || c > '9') && c != '.'&&c != '-')
		return true;
	return false;
}

bool Tools::isOperator(char ch)
{
	int i;
	for (i = 0; i < 7; i++)
	{
		if (ch == ops[i])
			return true;
	}
	return false;
}

bool Tools::Compare(char ch1, char ch2)
{
	int m, n;
	for (int i = 0; i < 4; i++)
	{
		if (ch1 == ops[i])
			m = i;
		if (ch2 == ops[i])
			n = i;
	}
	if (cmp[m][n] == 2)
		return true;
	else
		return false;
}

double Tools::Execute(double a, char op, double b)
{
	double result;
	switch (op)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	}
	return result;
}

int Tools::randomint(int min, int max)
{
	return rand() % (max - min) + min;
}

double Tools::randomfloat(double min, double max)
{
	std::uniform_real_distribution<double> dist(0, 1.0);
	std::mt19937 rng;
	rng.seed(std::random_device{}());
	return (max - min) * dist(rng) + min;
}
double Tools::gaussrand()
{
	static double V1, V2, S;
	static int phase = 0;
	double X;
	if (phase == 0)
	{
		do
		{
			double U1 = randomfloat(0, 1);
			double U2 = randomfloat(0, 1);
			V1 = 2 * U1 - 1;
			V2 = 2 * U2 - 1;
			S = V1 * V1 + V2 * V2;
		} while (S >= 1 || S == 0);
		X = V1 * sqrt(-2 * log(S) / S);
	}
	else
		X = V2 * sqrt(-2 * log(S) / S);
	phase = 1 - phase;
	return X;
}
int Tools::RandomChosse(vector<double> possiblelist)
{
	double sumpossible = 0.0;
	double randomfloatnum = randomfloat(0.0, 1.0);
	for (int i = 0; i < possiblelist.size(); i++)
	{
		sumpossible += possiblelist[i];
	}
	randomfloatnum *= sumpossible;
	for (int i = 0; i < possiblelist.size(); i++)
	{
		randomfloatnum -= possiblelist[i];
		if (randomfloatnum < 0)
			return i;
	}
	return possiblelist.size() - 1;
}
vector<string> Tools::merge_v(vector<string> v1, vector<string> v2)
{
	for (int i = 0; i < v1.size(); i++)
	{
		int flag = 0;
		for (int j = 0; j < v2.size(); j++)
		{
			if (v1[i] == v2[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			v2.push_back(v1[i]);
	}
	return v2;
}
void Tools::insert_v(vector<string> &v1, string t)
{
	int flag = 0;
	for (int j = 0; j < v1.size(); j++)
	{
		if (v1[j] == t)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		v1.push_back(t);
}
map<string, string> Tools::getArgvMap(int argc, char **argv)
{
	if (argc % 2 == 0)
	{
		cout << "input illegal" << endl;
		cout << USAGE << endl;
		exit(EXIT_FAILURE);
	}
	map<string, string> argvMap;
	for (int i = 1; i < argc; i += 2)
	{
		//cout << string(argv[i]) << string(argv[i + 1]) << endl;
		argvMap.insert(pair<string, string>(string(argv[i]), string(argv[i + 1])));
	}
	if (argvMap["-testfile"] == "" || argvMap["-modelfile"] == "" || argvMap["-propfile"] == "")
	{
		cout << USAGE << endl;
		exit(EXIT_FAILURE);
	}
	return argvMap;
}
vector<vector<double > > Tools::rankT(vector<vector<double > > X)
{
	vector<vector<double > > Y;
	for (int i = 0; i < X[0].size(); i++)
	{
		vector<double>temp;
		for (int j = 0; j < X.size(); j++)
		{
			temp.push_back(X[j][i]);
		}
		Y.push_back(temp);
	}
	return Y;
}
double Tools::getVar(vector<double> x)
{
	double mean = 0;
	for(int i=0;i<x.size();i++)
	{
		mean = mean*(double(i)/double(i+1)) + x[i]/double(i+1);
		//cout<<x[i]<< endl;
	}
	double var = 0.0;
	for(int i=0;i<x.size();i++)
	{
		var += (x[i] - mean)*(x[i] - mean) / double(x.size() + 1);
	}
	return var;
}