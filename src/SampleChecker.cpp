#include"interface.hpp"
int main(int argc, char * argv[])
{
    interface in;

    char prop_file[] = "testcase/prop";
    char model_file[] = "testcase/cra_cag_to_praise_code v2.dat";
    int result;
    if(argc == 5)
    {
        result = in.checkmodel(argv[1],argv[2], argv[3], atoi(argv[4]));
    }
    else
    {

    }
    //cout<<result<<endl;
    return result;
}
