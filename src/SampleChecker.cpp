#include "interface.hpp"
int main(int argc, char *argv[])
{
    interface in;

    char prop_file[] = "../testcase/prop";
    //char model_file[] = "../testcase/cra_cag_praise_2019-02-03_01-14-16_histogram.dat";
    char model_file[] = "../testcase/model";
    char folder[] = "../trace/test";
    string interfile = "../testcase/intervention";
    int result;
    if (argc == 7)
    {
        try
        {
           result = in.checkmodel(argv[1], argv[2], argv[3], atoi(argv[6]),argv[4], argv[5]);
        } 
        catch(...)
        {
            return -1;
        }
        
    }
    else if (argc == 6)
    {

        try
        {
            result = in.checkmodel(argv[1], argv[2], argv[3], atoi(argv[5]), "", argv[4]);
        } 
        catch(...)
        {
            return -1;
        }
    }
    else
    {

        try
        {
            result = in.checkmodel(model_file, prop_file, folder, 0, interfile, "../testcase/bmi_config.txt");
        } 
        catch(...)
        {
            return -1;
        }
    }
    cout<<"result: "<<result<<endl;
    return result;
}
