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
	if ((c < '0' || c > '9') && c != '.' && c != '-')
		return true;
	return false;
}

bool Tools::isOperator(char ch)
{
	int i;
	for (i = 0; i < 8; i++)
	{
		if (ch == ops[i])
			return true;
	}
	return false;
}

bool Tools::Compare(char ch1, char ch2)
{
	int m, n;
	for (int i = 0; i < 5; i++)
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

double Tools::Execute(double b, char op, double a)
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
	case '^':
		result = pow(a, b);

		break;
	}
	return result;
}

int Tools::randomint(int min, int max)
{
	srand((unsigned)time(NULL)); 
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
	//cout<<randomfloatnum<<endl;
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
	if (argvMap.count("-testfile") == 0)
	{
		argvMap.insert(pair<string, string>("-testfile", "../testcase/test"));
	}
	if (argvMap.count("-modelfile") == 0)
	{
		argvMap.insert(pair<string, string>("-modelfile", "../testcase/cra_cag_praise_2019-02-03_01-14-16_histogram.dat"));
	}
	if (argvMap.count("-propfile") == 0 && argvMap.count("-getDistribution") == 0)
	{
		argvMap.insert(pair<string, string>("-propfile", "../testcase/prop"));
	}
	return argvMap;
}
vector<vector<double > > Tools::rankT(vector<vector<double > > X)
{
	vector<vector<double > > Y;
	for (int i = 0; i < X[0].size(); i++)
	{
		vector<double> temp;
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
	for (int i = 0; i < x.size(); i++)
	{
		mean = mean * (double(i) / double(i + 1)) + x[i] / double(i + 1);
		//cout<<x[i]<< endl;
	}
	double var = 0.0;
	for (int i = 0; i < x.size(); i++)
	{
		var += (x[i] - mean) * (x[i] - mean) / double(x.size() + 1);
	}
	return var;
}
int Tools::str2int(string a)
{
	if (isInt(a))
		return atoi(a.c_str());
	else
	{
		cout << "Error: Not a int number" << endl;
		exit(EXIT_FAILURE);
		return 0;
	}
}
string Tools::int2str(int a)
{
	return to_string(a);
}
bool Tools::isInt(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if(i==0&&s[i]=='-')
		    continue;
		if (s[i] < '0' || s[i] > '9')
			return false;
	}
	return true;
}

bool Tools::isDouble(string s)
{
	istringstream sin(s);
	double t;
	char p;
	if (!(sin >> t))
		/*解释：
            sin>>t表示把sin转换成double的变量（其实对于int和float型的都会接收），如果转换成功，则值为非0，如果转换不成功就返回为0
        */
		return false;
	if (sin >> p)
		/*解释：此部分用于检测错误输入中，数字加字符串的输入形式（例如：34.f），在上面的的部分（sin>>t）已经接收并转换了输入的数字部分，在stringstream中相应也会把那一部分给清除，如果此时传入字符串是数字加字符串的输入形式，则此部分可以识别并接收字符部分，例如上面所说的，接收的是.f这部分，所以条件成立，返回false;如果剩下的部分不是字符，那么则sin>>p就为0,则进行到下一步else里面
          */
		return false;
	else
		return true;
}