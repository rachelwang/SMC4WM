#include"linearEquation.h"
#include<iostream>
using namespace std;

linearEquation::linearEquation()
{

}
linearEquation::linearEquation(vector<vector<double > > p)
{
    setCM(p);
}
void linearEquation::setCM(vector<vector<double > > p)
{
    this->n = p.size();
    this->x0 = new double[n];
    this->A = new double[n*n];
    this->L = new double[n*n];
    this->U = new double[n*n];
    this->v = new double[n];
    for(int i = 0; i < n; i++)
    {
        if(p[i].size() != n + 1)
        {
            cout<<"Error:"<<endl;
        }
        for(int j = 0; j < n; j++)
        {
            A[i * n + j] = p[i][j];
        }
        x0[i] = p[i][n];
        v[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            *(U + i*n + j) = 0;
            if (i==j)
            {
                *(L + i*n + j) = 1;
            }
            else
            {
                *(L + i*n + j) = 0;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int j = k; j < n; j++)
        {
            *(U + k*n + j) = *(A + k*n + j);
            for (int r = 0; r < k; r++)
            {
                *(U + k*n + j) = *(U + k*n + j) - (*(L + k*n + r)*(*(U + r*n + j)));
            }
        }
        for (int i = k+1; i < n; i++)
        {
            *(L + i*n + k) = *(A + i*n + k);
            for (int r = 0; r < k; r++)
            {
                *(L + i*n + k) = *(L + i*n + k) - (*(L + i*n + r)*(*(U + r*n + k)));
            }
            *(L + i*n + k) = *(L + i*n + k) / (*(U + k*n + k));
        }
    }
}
void linearEquation::setVar(vector<double> var)
{
    if(var.size()!=n)
    {
        cout<<"Error:"<<endl;
    }
    for(int i = 0; i < n; i++)
    {
        v[i] = var[i];
    }
}
vector<double> linearEquation::getResult(vector<double> s)
{
    x = new double[n];
    y = new double[n];
    double *b = new double[n];
    for(int i = 0; i < n; i++)
    {
        *(b + i) = s[i] - x0[i];
    }
    for (int i = 0; i < n; i++)//由Ly=b算y
    {
        *(y + i) = *(b + i);
        for (int j = 0; j < i; j++)
        {
            *(y + i) = *(y + i) - *(L + i*n + j)*(*(y + j));
        }
    }
    /*
    cout<<"MU:"<<endl;
    for(int i=0;i<n*n;i++)
    {
        cout<<A[i]<<" ";
        if((i+1)%n==0)cout<<endl;
    }
    */
    //cout<<endl<<"endMU"<<endl;
    for (int i = n-1; i >= 0; i--)
    {
        *(x + i) = *(y + i);
        for (int j = i+1; j < n; j++)
        {
            *(y + i) = *(y + i) - *(U + i*n + j)*(*(x + j));
        }
        *(x + i) = *(y + i) / (*(U + i*n + i));
    }
    vector<double> result;
    for (int i = 0; i < n; i++)
    {
        //cout <<"x"<<i+1<<"："<< *(x + i) << endl;
        result.push_back(*(x + i));
    }
    delete[]x;
    delete[]y;
    delete[]b;
    return result;
}