#include<iostream>
#include<vector>
using namespace std;
class linearEquation
{
    
public:
    linearEquation();
    linearEquation(vector<vector<double > >);
    void setCM(vector<vector<double > >);
    void setVar(vector<double>);
    vector<double> getResult(vector<double>);
private:
    int n;
    double *A;
    double *B;
    double *v;
    double *L;
    double *U;
    double *y;
    double *x;
    double *x0;
};