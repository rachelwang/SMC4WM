#include "Tools.h"
#include <stack>
#include <set>
#include <algorithm>
#include <fstream>
using namespace std;
class ModelSearch : public Tools
{
  public:
    ModelSearch();
    ModelSearch(string);
    vector<string> satFiles;
    string folderName;
    void getStruct(string trace);
    void readstruct();
    void setNewKnowladge();
    struct relation
    {
      string node1;
      string node2;
      int type;
    };
    vector<relation> network;
};