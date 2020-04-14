#ifndef abc123
#define abc123

#include "List.h"

void displayHeader();
int readData(FlowList& data);
double average(int num, FlowList& data);
double median(int num, FlowList& data);
int menu();
void display(int num, FlowList &data);
int addData(int n, FlowList& data);
int removeData(int n, FlowList& data);
void press_enter();
void saveData(int num, FlowList &data);

#endif