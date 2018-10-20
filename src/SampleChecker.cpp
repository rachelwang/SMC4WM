#include "interface.hpp"
int main(int argc, char *argv[])
{
    interface in;

    char prop_file[] = "../testcase/prop";
    char model_file[] = "../testcase/cra_cag_to_praise_code.dat";
    char folder[] = "../trace/test";
    string interfile = "../testcase/intervention";
    int result;
    if (argc == 7)
    {
        result = in.checkmodel(argv[1], argv[2], argv[3], atoi(argv[6]),argv[4], argv[5]);
    }
    else if (argc == 6)
    {
        result = in.checkmodel(argv[1], argv[2], argv[3], atoi(argv[5]), "", argv[4]);
        cout<<"123"<<endl;
    }
    else
    {
        result = in.checkmodel(model_file, prop_file, folder, 0, interfile, "../testcase/initConfig.txt");
    }
    //cout<<result<<endl;
    return result;
}
