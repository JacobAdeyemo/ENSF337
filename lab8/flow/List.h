

#ifndef OLLIST_H
#define OLLIST_H

struct ListItem {
	int year;
	double flow;
};

struct Node {
  ListItem item;
  Node *next;
};

class FlowList {
public:
  FlowList(); 
  void setnode(int a, double b);
  void sort_nodes();
  void next_flow();
  double get_flow() const;
  void reset_flow();
  int get_year() const;
  void destroy();
  void insert(int year, double flow);
  
private:
  Node *head, *body, *index;
};
#endif
