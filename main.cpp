//Name: Alex Bowman and Tyler Hembrock   11.19.2013
//CS53 section F
//Description: Simulation of competing companies of Comic Book Guy and Moe.
// The program implements multiple classes and interactions between them.
//Main File

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "business.h"
#include "customer.h"

using namespace std;


int main()
{
  srand(time(NULL));

  Customer cust_array[MAX_LIST];
  
  ifstream fin;
  for(int i=0; i < MAX_LIST; i++)
  {
    int num;
    string name;
    fin.open("people.txt");
    getline(fin, name, ',');
    cust_array[i].getName() = name;
    fin.ignore();
    fin >> num;
    num ++;
    if(num)
      cust_array[i].changeInc(true);
    else
      cust_array[i].changeInc(false);
  }
  fin.close();
    
  ifstream finMo;
  finMo.open("moeitems.txt");
  Business b1("Moe's Bar", 0, finMo);
  finMo.close();
  
  ifstream finComic;
  finComic.open("comicitems.txt");
  Business b2("Comic Book Guy's Store", 0, finComic);
  finComic.close();
     
  b1.addCustomers();
  b2.addCustomers();
     
  b1.printBiz();
  b2.printBiz();
  
  cout << endl << endl;
  cout << cust_array[0];
  cout << cust_array[1];

  
  return 0;
}

//Had trouble with m_cust_name functionality. Happiness also posed
//a problem, while money didn't even though they both had the same
//structure..