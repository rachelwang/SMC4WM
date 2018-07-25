
/**
 * the interface to the external software (C code) which wants to use the online model
 * checker
 */
#include"interface.hpp"
#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
extern int yyparse (void *YYPARSE_PARAM);
#else
extern int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
extern int yyparse (void);
#else
extern int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */
extern FILE *yyin;
interface::interface()
{
}
/**
 * assuming the external software is a C code

extern "C" {
  void read_property(char *);
  void init_signals(vector<string>);
  valType advance(vector<double>);
}*/

/**
 * reads the BLTL property specified in the file whose path is specified in the
 * parameter `file'
 *
 * ideally, this has to be the first thing to do
 */
void interface::read_property(char *file) {

  yyin = fopen(file, "r");
  if (!yyin) {
    fprintf(stderr, "ERROR: Property file does not exist\n");
    exit(EXIT_FAILURE);
  }
  yyparse();
  fclose(yyin);
  c = NULL;
}

/**
 * register all the signals whose values appear in the trace
 *
 * parameter `list' contains the list of character strings of the
 * alphanumeric and case-sensitive names of the signals, in the exact order as
 * they appear in the trace
 *
 * parameter `len' is the number of signals in the parameter `list'
 *
 * a call to this has to precede a call to `advance' to check the trace
 */
void interface::init_signals(vector<string>list) {
  state_vars.clear();
  for (int i = 0; i < list.size(); i++) {
    state_vars.push_back(list[i]);
    #ifdef VERBOSE
    cout << list[i] << " ";
    #endif
  }
  #ifdef VERBOSE
  cout << endl;
  length_explored = 0;
  #endif
  /* create a new checker */
  delete c;
  c = new Checker();
}
void getFiles(vector<string>& files )
{
    DIR *dp;
    struct dirent *dirp;
    if(!(dp = opendir("../trace")))
        printf("can't open");
    string::size_type idx;
    while (((dirp=readdir(dp))!=NULL))
    {
        string a = dirp->d_name;
        idx=a.find("trace");
        if(idx == string::npos )
        {
        }
        else
            files.push_back(a);
    }
    closedir(dp);
}
string gettracefilename()
{
    vector<string>files;
    getFiles(files);
    int size1 = files.size();
    string newfile = "../trace/trace_";
    newfile += to_string(size1);
    return newfile;
}
/**
 * advances model checking the trace by one step
 *
 * parameter `new_state' is the sequence of double values corresponding to the
 * signals
 *
 * parameter `len' is the length of the sequence `new_state'
 *
 * returns
 *   SAT/UNSAT if the property satisfiability can be decided at this point on
 *             the trace
 *   DONT_KNOW if the trace has to explored further
 */
valType interface::advance(vector<double>new_state) {
  #ifdef VERBOSE
  length_explored++;
  cout << "step " << length_explored << endl;
  #endif
  double ts = new_state[0];
  valType result;
  #ifdef VERBOSE
  cout << "timestamp : " << ts << endl;
  cout << ts << " ";
  #endif
  for (int i = 0; i < new_state.size() - 1; i++) {
    state.push_back(make_pair(state_vars.at(i), new_state[i+1]));
    #ifdef VERBOSE
    cout << state_vars[i] << " ";
    #endif
  }
  #ifdef VERBOSE
  cout << endl;
  #endif
  result = c->advance(state, ts);
  state.clear();
  return result;
}
bool interface::check_trace(Sampler sample1,char *prop_file1,string modelfile)
{
    ofstream file1(tracefile);
    vector<string> state_vars;
    valType t;
    double ts;
    vector<pair<string, double> > state;
    yyin = fopen(prop_file1, "r");
    if (!yyin) {
        fprintf(stderr, "ERROR: Property file does not exist\n");
        exit(EXIT_FAILURE);
    }
    yyparse();
    fclose(yyin);
    c = new Checker();

        //cout<<"check"<<endl;
    ts = 0;
    while(1)
    {
        sample1.get_one_sample();
        //cout<<sample1.cpd_order.size()<<" "<<state_vars.size()<<" "<<endl;

        if(sample1.sample_size==1)
        {
            file1<<"time";
            for(int i=0;i<sample1.variable_num;i++) {//
                state_vars.push_back(string(sample1.cpd_order[i]));
                file1<<" "<<sample1.cpd_order[i];
                //cout<<string(sample1.cpd_order[i])<<endl;
            }
            file1<<endl;
        }
        file1<<ts<<" ";
        for (int j = 0; j <state_vars.size() ; j++) {//
            state.push_back(make_pair(state_vars.at(j), sample1.value[sample1.NOW][j]));
            file1<<sample1.value[sample1.NOW][j]<<" ";
            //cout<<state_vars.at(j)<<" "<<sample1.old_sample[j]<<endl;
        }
        file1<<endl;
            //cout<<i<<endl;
        if ((t = (*c).advance(state, ts)) == SAT) {

            file1<<"#"<<modelfile<<endl;
            file1<<"#"<<prop_file1<<endl;
            file1<<"1"<<endl;
            file1.close();
            return 1;
        } else if (t == UNSAT) {
            file1<<"#"<<modelfile<<endl;
            file1<<"#"<<prop_file1<<endl;
            file1<<"0"<<endl;
            file1.close();
            return 0;
        }
        state.clear();
        ts += 1;
           /**/
    }
    return 1;
}
int interface::checkmodel(string modelfile,char*propfile)
{
    tracefile = gettracefilename();

	Sampler sample1(modelfile);
    //cout<<modelfile<<endl;
	//gm.bayesnet.get_cpd_info();
    int result = 0;
    //cout<<"Strat checking"<<endl;
    result = check_trace(sample1,propfile,modelfile);
    if(result == 1)
    {
        //cout << "satisfiable!" << endl;
        return 1;
    }
    else
    {
        //cout << "unsatisfiable!" << endl;
        return 0;
    }
}
void interface::sample(int num,string modelfile ,string file)
{
    Sampler sample1(modelfile);
    ofstream file1(file);
    for(int i=0;i<num;i++)
    {
        sample1.get_one_sample();
        //cout<<sample1.variable_num<<endl;
        if(sample1.sample_size==1)
        {
            file1<<"time";
            for(int j=0;j<sample1.variable_num;j++) {//
                file1<<" "<<sample1.cpd_order[i];
            }
            file1<<endl;
        }
        file1<<i<<" ";
        for (int j = 0; j <sample1.variable_num ; j++) {//
            file1<<sample1.value[sample1.NOW][j]<<" ";
            //cout<<state_vars.at(j)<<" "<<sample1.old_sample[j]<<endl;
        }
        file1<<endl;
    }
    file1.close();
}
