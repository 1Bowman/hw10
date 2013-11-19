//Name: Alex Bowman and Tyler Hembrock   11.19.2013
//CS53 section F
//Description: Simulation of competing companies of Comic Book Guy and Moe.
// The program implements multiple classes and interactions between them.
//Business functions File

#include "business.h"
#include "customer.h"

Business::Business() //Default constructor
{
  m_business_name = "";
  m_register_money = 0;
  m_items_ammnt = 0;
  m_num_cust = 0;
}

Business::Business(const string bName, const float regMoney)
{
  ifstream fin;
  
  // int count = 0;
  string holder;
  m_business_name = bName;
  m_register_money = regMoney;
  m_num_cust = 0;

  fin.open("items.txt");

  
  while(fin >> holder)
  {
    m_items_sold[m_items_ammnt] = holder;
    m_items_ammnt++;
  }
  
  fin.close();
}

void Business::printBiz()
{
  cout << m_business_name << "\n------------------" << endl;
  
  cout << "Customers\n---------" << endl;
  for(int i = 0; i < m_num_cust; i++)
    m_cust_objects[i].printCust();
  
  cout << endl << "Items on the shelf\n------------------" << endl;
  for(int i = 0; i < m_items_ammnt; i++)
    cout << m_items_sold[i] << endl;
  
  return;
}

void Business::addCustomer()
{
  m_cust_objects[m_num_cust] = custName; //implement calling object
  m_num_cust++;
  return;
}

void Business::make_a_sale()
{
  //assigns an item for each customer in the business to purchase
  int randItem;
  string holder;
  
  for(int i = 0; i < m_num_cust; i++)
  {
    randItem = rand()%7;
    if(m_cust_objects[i].purchase(m_items_sold[randItem]))
      m_cust_objects[i].changeMoney(-40);
  }  
  return;
}