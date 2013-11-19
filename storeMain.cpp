//Name: Alex Bowman   11.7.2013
//CS53 section F
//Description: The implementation of OOP classes with a customers and a
//             business which takes values possessed by the customer and
//             and buys various things.
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
  Customer c1(10, "Clayton Price");
  Customer c2(400, "Eric Barnes"); 
  Customer c3;
  Business b1;
  Business b2("MichaelSoft inc.", 4000);
  
  
  b2.enterBiz(c1);
  b2.enterBiz(c2);
  b2.enterBiz(c3);
  b2.make_a_sale();
  b2.make_a_sale();
  
  b1.printBiz();
  b2.printBiz();
  
  return 0;
}