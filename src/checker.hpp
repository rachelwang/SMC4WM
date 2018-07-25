#ifndef CHECKER_HPP
#define CHECKER_HPP
#include "parser.hpp"
#include<stdio.h>
class Checker {
private:
  list<LogicalRelationalNode *> init_propagateList;
  list<pair<LogicalRelationalNode *, bool> > curr_list, aux_list;
  list<pair<pair<LogicalRelationalNode *, int>, bool> > no_future_list;
  vector<pair<LogicalRelationalNode *, bool> > prev_vect;
  map<LogicalRelationalNode *, int> prev_vect_map;
  valType val_init_tree;
  double ts_new, ts_old;

  void patch (LogicalRelationalNode *, LogicalRelationalNode *, double);
  Node *node_copy(Node *, double);
  void traverse_patch(LogicalRelationalNode *, double);
  void no_future(LogicalRelationalNode *, int);
  void build_from(LogicalRelationalNode *, double);
  void build_tree_list(double);
  double get_val(string, vector<pair<string, double> >);
  void eval_arithmetic(ArithmeticNode *, vector<pair<string, double> >);
  void eval_tree(LogicalRelationalNode *, vector<pair<string, double> >);
  void remove(LogicalRelationalNode *, LogicalRelationalNode *, double, bool);
  void change_propagateList(LogicalRelationalNode *,
                            double,
                            LogicalRelationalNode *,
                            LogicalRelationalNode *,
                            nodeType);
  void pull_node(LogicalRelationalNode *, nodeType);
  void set_and_propagate(LogicalRelationalNode *, int, valType, int);
  void propagate_value(LogicalRelationalNode *, double, nodeType, valType);
  void propagate(void);
  valType evaluate(vector<pair<string, double> >);
public:
  Checker();
  ~Checker();
  valType advance(vector<pair<string, double> >, double);
};
#endif
