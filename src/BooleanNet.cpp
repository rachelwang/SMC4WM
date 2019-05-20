#include "BooleanNet.hpp"
BooleanNet::BooleanNet(string booleanFile)
{
    //cout << booleanFile << endl;
    getData(booleanFile);
}
BooleanNet::BooleanNet()
{
}
BooleanNet::~BooleanNet()
{
}
void BooleanNet::getData(string booleanFile)
{
    ifstream file2(booleanFile);
    string temp;
    //cout << booleanFile << endl;

    int state = 0;
    int flag = 0;
    vector<vector<string> > traceTemp2;
    while (getline(file2, temp))
    {
        if (findString(temp, "Run") == 1)
        {
            state = 0;
            if (flag != 0)
            {
                traces.push_back(getOneTrace(traceTemp2));
                sampleNum += 1;
                traceTemp2.clear();
                continue;
            }
            flag = 1;
            continue;
        }
        else if (findString(temp, "Frequency") == 1)
        {
            traces.push_back(getOneTrace(traceTemp2));
            sampleNum += 1;
            break;
        }
        vector<string> tempLine = split(temp, " ");
        string varN;
        for(int i=0;i<tempLine[0].length()-3;i++)
        {
            varN+=tempLine[0][i];
        }
        tempLine[0] = varN;

        traceTemp2.push_back(tempLine);
        if (sampleNum == 0)
        {
            sampleLength = traceTemp2[0].size() - 1;
            setVar(tempLine[0]);
        }
        state += 1;
    }
    int size = varriableNum;
    for(int i=0;i<size;i++)
    {
        addVarder(varriableList[i]);
    }
}
int BooleanNet::getVarInd(string s)
{
    int k = -1;
    for (int i = 0; i < varriableNum; i++)
    {
        if (varriableList[i].compare(s) == 0)
        {
            k = i;
            break;
        }
    }
    return k;
}
string BooleanNet::getVar(int k)
{
    if (k > varriableNum)
    {
        cout << "error" << endl;
        return "error";
    }
    else
        return varriableList[k];
}
int BooleanNet::setVar(string s)
{
    if (getVarInd(s) == -1)
    {
        varriableList.push_back(s);
        varriableNum += 1;
        return varriableNum - 1;
    }
    else
        return getVarInd(s);
}
void BooleanNet::showTraces()
{
    cout << "trace num: " << sampleNum << endl;
    cout << "trace length: " << sampleLength << endl;
    cout << "varriable num: " << varriableNum << endl;
    for (int i = 0; i < sampleNum; i++)
    {
        cout << "trace " << i + 1 << endl;
        for (int j = 0; j < varriableNum; j++)
        {
            cout << varriableList[j] << " ";
        }
        cout << endl;
        for (int j = 0; j < sampleLength; j++)
        {
            for (int ij = 0; ij < varriableNum; ij++)
            {
                cout << traces[i][j][ij] << " ";
            }
            cout << endl;
        }
    }
}
vector<vector<int> > BooleanNet::getOneTrace(vector<vector<string> > data2)
{
    
    vector<vector<int> > data1;
    for (int i = 0; i < sampleLength; i++)
    {
        vector<int> tempLine1;
        for (int j = 0; j < varriableNum; j++)
        {
            tempLine1.push_back(0);
        }
        data1.push_back(tempLine1);
    }
    for (int i = 0; i < sampleLength; i++)
    {
        for (int j = 0; j < varriableNum; j++)
        {
            int indTemp = getVarInd(data2[j][0]);
            data1[i][indTemp] = str2int(data2[j][i+1]);
        }
    }
    return data1;
}
void BooleanNet::addVarder(string s)
{
    int ind = getVarInd(s);
    string varDer = varriableList[ind]+"_derivative";
    for(int i=0;i<sampleNum;i++)
    {
        for(int j=0;j<sampleLength;j++)
        {
            if(j==0)
                traces[i][j].push_back(0);
            else
            {
                traces[i][j].push_back(traces[i][j][ind] - traces[i][j - 1][ind]);
            }
        }
    }
    varriableNum+=1;
    varriableList.push_back(varDer);
}