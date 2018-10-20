#include "ModelSearch.h"
ModelSearch::ModelSearch()
{
}
ModelSearch::ModelSearch(string FN)
{
    this->folderName = FN;
}
void ModelSearch::getStruct(string trace)
{
    string callTC1 = "java -jar ../tetrad/tetradcmd-5.0.0-19.jar -data ";
    callTC1 += trace + " -datatype continuous -algorithm pc -verbose";
    callTC1 += " -graphtxt " + folderName + "/STRUCTINFO/graph.txt";
    callTC1 += " -knowledge " + folderName + "/STRUCTINFO/BN";
    cout << callTC1 << endl;
    //FILE *fp1;
    //fp1 = popen(callTC1.c_str(), "r");
    FILE *fp;
    if ((fp = popen(callTC1.c_str(), "r")) == NULL)
    {
        perror("popen failed");
        return;
    }
    char buf[256];
    while (fgets(buf, 255, fp) != NULL)
    {
        //printf("***%s***", buf);
    }
    if (pclose(fp) == -1)
    {
        perror("pclose failed");
        return;
    }
}
void ModelSearch::readstruct()
{
    string file_path = folderName + "/STRUCTINFO/graph.txt";
    //string file_path = "../trace/SMC_wm_5/STRUCTINFO/graph.txt";
    cout << file_path << endl;
    ifstream fin(file_path);
    string s;
    int begin_flag = 0;
    while (fin >> s)
    {
        if (s == "Edges:")
        {
            begin_flag = 1;
            continue;
        }
        if (begin_flag == 0)
            continue;
        string str1, str2, str3;
        fin >> str1;
        fin >> str2;
        fin >> str3;
        relation temp_r;
        temp_r.node1 = str1;
        temp_r.node2 = str3;
        if (str2 == "-->")
            temp_r.type = 0;
        else if (str2 == "---")
            temp_r.type = 1;
        else if (str2 == "<--")
            temp_r.type = 2;
        else
            temp_r.type = 3;
        network.push_back(temp_r);
    }
    fin.close();
}
void ModelSearch::setNewKnowladge()
{
    string filename = folderName + "/STRUCTINFO/BN";
    ofstream fout1(filename);
    fout1 << "/knowledge" << endl
          << "forbiddirect" << endl
          << endl
          << "requiredirect" << endl;
    for (int i = 0; i < network.size(); i++)
    {
        if (network[i].type == 0)
            fout1 << network[i].node1 << " " << network[i].node2 << endl;
        else if(network[i].type == 2)
            fout1 << network[i].node2 << " " << network[i].node1 << endl;
    }
    fout1 << endl
          << "addtemporal" << endl;
    fout1.close();
}