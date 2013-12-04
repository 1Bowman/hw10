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
  
  int count = 1;
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
  cout << m_business_name << "\n------------------" << endl;
  
  cout << "Customers\n---------" << endl;
  for(int i = 0; i < m_num_cust; i++)
    m_cust_objects[i].printCust();
  
  cout << endl << "Items on the shelf\n------------------" << endl;
  for(int i = 0; i < m_items_ammnt; i++)
    cout << m_items_sold[i].pName << endl;
  
  return;
}

void Business::addCustomer(Customer custName)
{
  m_cust_objects[m_num_cust] = custName; //implement calling object
  m_num_cust++;
  return;
}

void Business::sell_stuff()
{
  //assigns an item for each customer in the business to purchase
  //Uses the buy_something customer function.
  product item;
  bool buy;
  for(int i = 0; i < m_num_cust; i++)
  {
  
    
               //****Took out these*****
    //randItem = rand()%7;   Put in buy_something() function
    //if(m_cust_objects[i].purchase(m_items_sold[randItem]))
    //***** Changed to this if statement *******
    //***** instead of changing customers money which is done with the 
    //buy_something() function. I added a mutator to add to the register.
      
      
      
      
       // ****** Creates errors until products are declared *****
      //Still need next two lines. Need product declaration
      //from lists first.s
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