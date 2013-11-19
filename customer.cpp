//Name: Alex Bowman   11.7.2013
//CS53 section F
//Description: The implementation of OOP classes with a customers and a
//             business which takes values possessed by the customer and
//             and buys various things.
//Customer functions File


#include "customer.h"

Customer::Customer()
{
  m_cust_name = "";
  m_purchase_ammount = 0;
  m_spending_money = (rand()%245 +5);
}

Customer::Customer(float money, string name)
{
  m_spending_money = money;
  m_cust_name = name;
  m_purchase_ammount = 0;
}

bool Customer::purchase(string itemPurchased)
{
  bool enoughMoney = false;
  
  if(m_spending_money >= 40)
  {
    enoughMoney = true;
    m_purchases[m_purchase_ammount] = itemPurchased;
    m_purchase_ammount++;
  }
  return enoughMoney;
}

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