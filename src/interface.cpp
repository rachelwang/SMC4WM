
/**
 * the interface to the external software (C code) which wants to use the online model
 * checker
 */
#include "interface.hpp"
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
extern int yyparse(void *YYPARSE_PARAM);
#else
extern int yyparse();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
extern int yyparse(void);
#else
extern int yyparse();
#endif
#endif /* ! YYPARSE_PARAM */
extern FILE *yyin;
interface::interface()
{
    trace_num = 0;
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
void interface::read_property(char *file)
{

    yyin = fopen(file, "r");
    if (!yyin)
    {
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
void interface::init_signals(vector<string> list)
{
    state_vars.clear();
    for (int i = 0; i < list.size(); i++)
    {
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
void getFiles(vector<string> &files, string folder_name, string file_name)
{
    DIR *dp;
    struct dirent *dirp;
    if (!(dp = opendir(folder_name.c_str())))
        printf("can't open");
    string::size_type idx;
    while (((dirp = readdir(dp)) != NULL))
    {
        string a = dirp->d_name;
        idx = a.find(file_name);
        if (idx == string::npos)
        {
        }
        else
            files.push_back(a);
    }
    closedir(dp);
}
string gettracefilename(string folder_name, string file_name)
{
    vector<string> files;
    getFiles(files, folder_name, file_name);
    int size1 = files.size();
    string newfile = folder_name + "/" + file_name + "_";

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
valType interface::advance(vector<double> new_state)
{
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
    for (int i = 0; i < new_state.size() - 1; i++)
    {
        state.push_back(make_pair(state_vars.at(i), new_state[i + 1]));
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
bool interface::check_trace(Sampler sample1, char *prop_file1, string modelfile)
{
    //ofstream file1(tracefile);
    vector<string> state_vars;
    valType t;
    double ts;
    vector<pair<string, double> > state;
    yyin = fopen(prop_file1, "r");
    if (!yyin)
    {
        fprintf(stderr, "ERROR: Property file does not exist\n");
        exit(EXIT_FAILURE);
    }
    yyparse();
    fclose(yyin);
    c = new Checker();

    //cout<<"check"<<endl;
    ts = 0;
    while (1)
    {
        sample1.get_one_sample();
        //for(int i=0;i<sample1.variable_num;i++)
        //{
            //cout<<sample1.value[sample1.NOW][i]<<" ";
        //}
        //cout<<endl;
        //cout<<sample1.cpd_order.size()<<" "<<state_vars.size()<<" "<<endl;
        
        if (sample1.sample_size == 1)
        {
            //file1<<"time";
            for (int i = 0; i < sample1.variable_num; i++)
            { //
                state_vars.push_back(string(sample1.cpd_order[i]));
                //file1<<" "<<sample1.cpd_order[i];
                //cout<<string(sample1.cpd_order[i])<<endl;
            }
            //file1<<endl;
        }
        //file1<<ts<<" ";
        for (int j = 0; j < state_vars.size(); j++)
        { //
            state.push_back(make_pair(state_vars.at(j), sample1.value[sample1.NOW][j]));
            //file1<<sample1.value[sample1.NOW][j]<<" ";
            //cout<<state_vars.at(j)<<" "<<sample1.old_sample[j]<<endl;
        }
        //file1<<endl;
        //cout<<i<<endl;
        if ((t = (*c).advance(state, ts)) == SAT)
        {
            tracefile += "/SAT/trace_" + to_string(trace_num);
            sample1.saveSampleResult(tracefile);
            //file1<<"#"<<modelfile<<endl;
            //file1<<"#"<<prop_file1<<endl;
            //file1<<"1"<<endl;
            //file1.close();
            return 1;
        }
        else if (t == UNSAT)
        {
            tracefile += "/UNSAT/trace_" + to_string(trace_num);
            sample1.saveSampleResult(tracefile);
            //file1<<"#"<<modelfile<<endl;
            //file1<<"#"<<prop_file1<<endl;
            //file1<<"0"<<endl;
            //file1.close();
            return 0;
        }
        state.clear();
        ts += 1;
        /**/
    }
    return 1;
}
int interface::checkmodel(string modelfile, char *propfile, string folder_name, int numTrace, string interfile, string initfile)
{
    tracefile = "";
    tracefile += folder_name;
    trace_num = numTrace;
    Sampler sample1(modelfile, interfile);
    sample1.getInital(initfile);
    sample1.net_DBN.get_network_info();

    //cout<<modelfile<<endl;
    //gm.bayesnet.get_cpd_info();
    int result = 0;
    //cout<<"Strat checking"<<endl;
    result = check_trace(sample1, propfile, modelfile);
    string structfolder = folder_name + "/STRUCTINFO/";
    outputStruct(structfolder, sample1);
    getGraph(sample1);
    if (result == 1)
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
void interface::sample(int num, string modelfile, string file)
{
    Sampler sample1(modelfile, "");
    ofstream file1(file);
    for (int i = 0; i < num; i++)
    {
        sample1.get_one_sample();
        //cout<<sample1.variable_num<<endl;
        if (sample1.sample_size == 1)
        {
            file1 << "time";
            for (int j = 0; j < sample1.variable_num; j++)
            { //
                file1 << " " << sample1.cpd_order[i];
            }
            file1 << endl;
        }
        file1 << i << " ";
        for (int j = 0; j < sample1.variable_num; j++)
        { //
            file1 << sample1.value[sample1.NOW][j] << " ";
            //cout<<state_vars.at(j)<<" "<<sample1.old_sample[j]<<endl;
        }
        file1 << endl;
    }
    file1.close();
}
void interface::outputStruct(string folder, Sampler sample)
{
    string filename = folder + "/" + "BN";
    if (trace_num != 0)
        return;
    if (sample.sampler_type == 1)
    {
        creatFolder(folder);
        vector<string> NodesatT;
        vector<string> NodesatTplus1;
        vector<string> Nodes;
        vector<vector<string > > edge_LDBN;
        vector<vector<string > > edge_BN_c;
        vector<vector<string > > edge_BN;

        for (int i = 0; i < sample.net_DBN.cpd_list.size(); i++)
        {
            if (sample.net_DBN.cpd_list[i].intervention.size() > 0)
            {
                vector<string> tempset;
                string sonName = sample.net_DBN.cpd_list[i].cpd_name + "(t+1)";
                insert_v(NodesatTplus1, sonName);
                for (int j = 0; j < sample.net_DBN.cpd_list[i].intervention[0].Postfix.size(); j++)
                {
                    if (sample.net_DBN.cpd_list[i].intervention[0].Postfix[j].type == 0)
                    {
                        string parName = sample.net_DBN.cpd_list[i].intervention[0].Postfix[j].name;
                        string::size_type nPos2 = 0;
                        nPos2 = parName.find("beta", nPos2);
                        if (nPos2 != string::npos)
                            continue;
                        nPos2 = 0;
                        nPos2 = parName.find("_next", nPos2);
                        if (nPos2 == string::npos)
                        {
                            parName += "(t)";
                            insert_v(NodesatT, parName);
                        }
                        else
                        {
                            string_replace(parName, "_next", "(t+1)");
                            insert_v(NodesatTplus1, parName);
                        }
                        tempset.push_back(parName);
                        vector<string> temp_edge;
                        temp_edge.push_back(parName);
                        temp_edge.push_back(sonName);
                        edge_LDBN.push_back(temp_edge);
                    }
                }
            }
        }
        filename = folder + "/" + "LDBN";
        ofstream fout1(filename);
        fout1 << "/knowledge" << endl
              << "forbiddirect" << endl
              << endl
              << "requiredirect" << endl;
        for (int i = 0; i < edge_LDBN.size(); i++)
        {
            fout1 << edge_LDBN[i][0] << " " << edge_LDBN[i][1] << endl;
        }
        fout1 << endl
              << "addtemporal" << endl;
        fout1 << "0";
        for (int i = 0; i < NodesatT.size(); i++)
        {
            fout1 << " " << NodesatT[i];
        }
        fout1 << endl
              << "1";
        for (int i = 0; i < NodesatTplus1.size(); i++)
        {
            fout1 << " " << NodesatTplus1[i];
        }
        fout1 << endl;
        fout1.close();
        /*
        /knowledge
        forbiddirect
        输出LDBN的tetrad
        
        */

        for (int i = 0; i < NodesatT.size(); i++)
        {
            string_replace(NodesatT[i], "(t)", "");
        }
        for (int i = 0; i < NodesatTplus1.size(); i++)
        {
            string_replace(NodesatTplus1[i], "(t+1)", "");
        }
        Nodes = merge_v(NodesatT, NodesatTplus1);
        for (int i = 0; i < edge_LDBN.size(); i++)
        {
            for (int j = 0; j < 2; j++)
            {
                string_replace(edge_LDBN[i][j], "(t)", "");
                string_replace(edge_LDBN[i][j], "(t+1)", "");
            }
        }
        filename = folder + "/" + "BN_c";
        ofstream fout2(filename);
        fout2 << "/knowledge" << endl
              << "forbiddirect" << endl
              << endl
              << "requiredirect" << endl;
        for (int i = 0; i < edge_LDBN.size(); i++)
        {
            fout2 << edge_LDBN[i][0] << " " << edge_LDBN[i][1] << endl;
        }
        fout2 << endl
              << "addtemporal" << endl;
        fout2.close();
        /*
        
        输出BN_c的tetrad
        
        */
        for (int i = 0; i < edge_LDBN.size(); i++)
        {
            if (edge_LDBN[i][0] != edge_LDBN[i][1])
            {
                edge_BN.push_back(edge_LDBN[i]);
            }
        }
        filename = folder + "/" + "BN";
        ofstream fout3(filename);
        fout3 << "/knowledge" << endl
              << "forbiddirect" << endl
              << endl
              << "requiredirect" << endl;
        for (int i = 0; i < edge_BN.size(); i++)
        {
            fout3 << edge_BN[i][0] << " " << edge_BN[i][1] << endl;
        }

        fout3 << endl
              << "addtemporal" << endl;

        fout3.close();
        filename = folder + "/" + "graph.txt";
        ofstream fout4(filename);
        fout4 << "Graph Nodes:" << endl;
        int sumNum = 0;
        for(int i=0;i<sample.net_DBN.cpd_list.size();i++)
        {
            if(sample.net_DBN.cpd_list[i].cpd_type!=2)
            {
                if(sumNum!=0)
                    fout4<<",";
                fout4<<sample.net_DBN.cpd_list[i].cpd_name;
                sumNum++;
            }
        }
        fout4<<endl;
        fout4 << endl
              << "Graph Edges:" << endl;
        for (int i = 0; i < edge_BN.size(); i++)
        {
            fout4 << i+1 << ". " << edge_BN[i][0] << " --> " << edge_BN[i][1] << endl;
        }

        fout4.close();
        /*
        
        输出BN的tetrad
        
        */
    }
}
void interface::getGraph(Sampler sample)
{
    if (trace_num != 0)
        return;
    if (sample.sampler_type == 1)
    {
        while (sample.sample_size < 1000)
        {
            sample.get_one_sample();
        }
        sample.saveSampleResult("../tetrad/trace.txt");
    }
}