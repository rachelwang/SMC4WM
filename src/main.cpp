#include<iostream>
#include"Sampler.h"
using namespace std;
int main()
{
    Sampler s("cra_cag_praise_2019-02-03_01-14-16_histogram.dat","");
    for(int i=0;i<10;i++)
        s.getBackwardSample();
}