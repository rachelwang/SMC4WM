
/**
 * the interface to the external software (C code) which wants to use the online model
 * checker
 */
#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include "checker.hpp"
#include<stdio.h>
#include<vector>

#include"Sampler.h"

#include <sys/types.h>
#include <dirent.h>
#include<fstream>
class interface
{
public:
    interface();
    string tracefile;
    vector<string> state_vars;
    vector<pair<string, double> > state;
    int length_explored;
    Checker *c;
    void read_property(char *);
    void init_signals(vector<string>);
    valType advance(vector<double>);
    int checkmodel(string,char*);
    bool check_trace(Sampler,char*,string);
    void sample(int,string,string);
};
#endif
