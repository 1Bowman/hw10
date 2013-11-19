//Name: Alex Bowman and Tyler Hembrock   11.19.2013
//CS53 section F
//Description: Simulation of competing companies of Comic Book Guy and Moe.
// The program implements multiple classes and interactions between them.
//Customer functions File


#include "customer.h"

Customer::Customer()
{
  //m_cust_name = "";
  m_purchase_ammount = 0;
  m_spending_money = (rand()%245 +5);
  m_satisfaction = (rand()%100+1);
}

Customer::Customer(float money, string name)
{
  m_spending_money = money;
  m_cust_name = name;
  m_purchase_ammount = 0;
}

bool Customer::buy_something()
{
  //Look back at hw to add more functionality, because
  //I'm not sure at this point in time what all to add.
  return true;
}

// bool Customer::purchase(string itemPurchased)
// {
//   bool enoughMoney = false;
  
//   if(m_spending_money >= 40)
//   {
//     enoughMoney = true;
//     m_product[m_purchase_ammount] = itemPurchased;
//     m_purchase_ammount++;
//   }
//   return enoughMoney;
// }

void Customer::changeMoney(const int money)
{
  m_spending_money += money;
  return;
}

void Customer::printCust()
{
  cout << m_cust_name << " has $" << m_spending_money << " and purchases ";
  
  if(m_purchase_ammount > 0)
  {
    for(int i = 0; i < m_purchase_ammount; i++)
    {
      cout << m_purchases[i];
      if(m_purchase_ammount -1 == i)
        cout << ".";
      else
        cout << ", ";
    }
  }
  else
   cout << "nothing.";
    
  cout << endl;
  return;
}