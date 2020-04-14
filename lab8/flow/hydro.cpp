#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
using namespace std;
#include "List.h"
#include "hydro.h"

int main()
{
	FlowList x;
  int numRecords;
  displayHeader();
  numRecords = readData(x);
  int quit = 0;

  while(1)
  {
    switch(menu()){
      case 1:
            press_enter();
            display(numRecords, x);
            break;
      case 2:
            press_enter();
            numRecords = addData(numRecords, x);
            break;
      case 3:
            press_enter();
            saveData(numRecords, x);
            break;
      case 4:
            press_enter();
            numRecords = removeData(numRecords, x);
            break;
      case 5:
            cout << "\nProgram terminated!\n\n";
            quit = 1;
            break;
      default:
            cout << "\nNot a valid input.\n";
            press_enter();
      }
  if(quit == 1) break;
  }
}

void displayHeader()
{
  cout<<"Program: Flow Studies – Fall 2019"<<endl;
  cout<<"Version: 1.0"<<endl;
  cout<<"Lab section: B01"<<endl;
  cout<<"Produced by: Jay Chuang"<<endl;
}

void press_enter()
{
  cout<<"\n<<< Press enter to Continue>>>\n";
  while(1)
  if(cin.get()=='\n') break;
}

int menu()
{
  press_enter();
	cout << "Please select on the following operations"<<endl;
	cout<<"1. Display flow list, average and median"<<endl;
	cout<<"2. Add data"<<endl;
	cout<<"3. Save data into the file"<<endl; 
  cout<<"4. Remove data"<<endl; 
  cout<<"5. Quit"<<endl; 
  cout<<"Enter your choice (1, 2, 3, 4, of 5): "<<endl;

  int in;
  cin>>in;
  return in;
}

int readData(FlowList &data)
{
  ifstream in;
  in.open("flow.txt");
  if(in.fail())
  {
	  cout << "Error flow.txt not defined" << endl;
	  exit(1);
  }
  int a;
  double b;
  int count = 0;
  
  while(1)
  {
	  if(in.eof()) {
      data.setnode(a, b);
      break;
    }

    in >> a;
	  in >> b;
	  
    data.setnode(a ,b);  	  
    count++;
  }
  data.sort_nodes();
  in.close();
  return count;
}

void saveData(int num, FlowList &data)
{
  ofstream outputfile;
  outputfile.open("flow.txt");
  if(outputfile.fail())
  {
	  cout << "Error flow.txt not defined" << endl;
	  exit(1);
  }
  data.reset_flow();

  for(int i = 0; i < num; i++)
  {
    outputfile << data.get_year() << "     ";
    outputfile << data.get_flow() << endl;

    data.next_flow();
  }
  cout << "Data are saved into the file." << endl;
  outputfile.close();
}

double average(int num, FlowList& data)
{
  double sum = 0;
  int count = 0;
  data.reset_flow();

  while(count<num)
  {
	  sum += data.get_flow();	
	  count++;
    data.next_flow();
  }
  return sum/num;
}

double median(int num, FlowList& data)
{
  data.reset_flow();
  for(int i = 0; i < int(num/2); i++)
  data.next_flow();

  if(num%2 == 1)
    return data.get_flow();
  else
  {
    int a = data.get_flow();
    data.next_flow();
    int b = data.get_flow();
    return(a+b)/2;
  }
}

void display(int num, FlowList &data)
{
    cout<< setw (10)<<"Year"<< setw (50)<<"Flow (in billions of cubic meters)"<<endl<<endl;
    data.reset_flow();
    for(int i = 0;i<num;i++)
    {
        cout<< setw(10)<< data.get_year()<<setw(25)<<data.get_flow()<<endl;
        data.next_flow();
    }
    cout<<endl<<"The annual average of the flow is:"<<average(num,data)<<" millions cubic meters"<<endl;
    cout<<"The annual median flow is:"<<median(num,data)<<" millions cubic meters"<<endl;
}

int removeData(int num,FlowList & data)
{
  cout<<"Please enter a valid year to be removed:"<<endl;
  int year;
  cin>>year;
   
  data.reset_flow();
  for(int i = 0;i<num;i++)
  {
    if(data.get_year()==year)
    {
    data.destroy();
    cout<<"Delete successful!"<<endl;
    return num - 1;
    }
    data.next_flow();
  }
  cout<<"Delete unsuccessful, no such year"<<endl;
  return num;
}

int addData (int num, FlowList & data)
{
  cout<<"Please enter a valid year to be added:"<<endl;
  int year;
  cin>>year;

  data.reset_flow();
  for(int i = 0;i<num;i++)
  {
    if(data.get_year()==year)
    {
      cout<<"Data point already exists!"<<endl;
      return num;
    }
    data.next_flow();
  }
  cout<<"Please enter a valid flow to be added:"<<endl;
  double flow;
  cin>>flow;
  data.insert(year,flow);
  cout<<"Insert Successful!"<<endl;
  return num+1;
}