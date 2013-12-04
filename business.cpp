//Name: Alex Bowman and Tyler Hembrock   11.19.2013
//CS53 section F
//Description: Simulation of competing companies of Comic Book Guy and Moe.
// The program implements multiple classes and interactions between them.
//Business functions File

#include "business.h"

Business::Business() //Default constructor
{
  m_business_name = "";
  m_register_money = 0;
  m_items_ammnt = 0;
  m_num_cust = 0;
}

Business::Business(const string bName, const float regMoney, ifstream & fin)
{
  
  int price;
  string name;
  m_business_name = bName;
  m_register_money = regMoney;
  m_num_cust = 0;

  
  while(fin >> price)
  {
    m_items_sold[m_items_ammnt].pPrice = price;
    getline(fin, name, '\n');
    m_items_sold[m_items_ammnt].pName = name;
    m_items_ammnt ++;
  }
  
}

void Business::printBiz()
{
  cout << endl;
  cout << m_business_name << "\n------------------" << endl;
  
  cout << "Customers\n---------" << endl;
  for(int i = 0; i < m_num_cust; i++)
  {
    cout << m_cust_objects[i].getName() << " has $"
    << m_cust_objects[i].getMoney() << " with Happiness "
    << m_cust_objects[i].getSat();
    if(m_cust_objects[i].getAmnt() > 0)
    {
      cout << " and has a ";
      for(int j = 0; j < m_cust_objects[i].getAmnt(); j++)
      {
        cout << m_cust_objects[i].getpName(j) << ",";
      }
    }
  }
  
  return;
}

void Business::customers_leave()
{

}

void Business::addCustomers()
{
  string name;
  static int isb1 = false;
  for(int i=0; i < MAX_CUST; i++)
  {
    if(m_cust_objects[i].getInc() == isb1)
    {  
      m_cust_objects[m_num_cust].getName() = name;
      m_num_cust++;
    }
  }
  for(int i=0; i < MAX_CUST; i++)
  {
    if(m_cust_objects[i].getInc() != isb1)
    {  
      m_cust_objects[m_num_cust].getName() = name;
      m_num_cust++;
    }
  }
  isb1 = false;
  return;
}

void Business::sell_stuff()
{
  //assigns an item for each customer in the business to purchase
  //Uses the buy_something customer function.
  product item;
  for(int i = 0; i < m_num_cust; i++)
  {
      item = getProducts();
      if(m_cust_objects[i].buy_something(item))
      {
        m_cust_objects[i].changeMoney(-m_items_sold[m_items_ammnt].pPrice);
        add_to_register(m_items_sold[m_items_ammnt].pPrice);   
      }  
  }
  return;
}

product Business::getProducts()
{
  return m_items_sold[rand()%10]; //10 needs to be changed
}

void Business::add_to_register(const int money)
{
  m_register_money += money;
  return;
}