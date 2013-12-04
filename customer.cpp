//Name: Alex Bowman and Tyler Hembrock   11.19.2013
//CS53 section F
//Description: Simulation of competing companies of Comic Book Guy and Moe.
// The program implements multiple classes and interactions between them.
//Customer functions File


#include "customer.h"

Customer::Customer()
{
  //m_cust_name = "";
  m_purchase_amount = 0;
  m_spending_money = (rand()%245 +5);
  m_satisfaction = (rand()%100 +1);
}

Customer::Customer(float money, string name)
{
  m_spending_money = money;
  m_cust_name = name;
  m_purchase_amount = 0;
}

bool Customer::buy_something(product item)
{
  bool wantBuy, willBuy;
  
  wantBuy = rand()%2; //Rand either 1 or 0. True or false.
  if(wantBuy)
  {
    
    if(m_product[m_purchase_amount].pPrice < m_spending_money
       && m_purchase_amount < PURCHASE_MAX)
    {
      m_product[m_purchase_amount].pName = item.pName;
      m_purchase_amount ++;
      m_spending_money -= item.pPrice;
      m_satisfaction += 15;
      willBuy = true;
      cout << m_cust_name << " purchased a " 
      << m_product[m_purchase_amount - 1].pName
      << " for $" << m_product[m_purchase_amount - 1].pPrice << endl;
      
    } 
    else
    {
      m_satisfaction -= 10;
      willBuy = false;
    }
  }
  else
  {
    m_satisfaction -= 10;
    willBuy = false;
  }  
  return willBuy;
}

bool Customer::throws()
{
  bool success;
  if(m_purchase_amount > 0)
  {
    success = true;
  }
  else
  {
    success = false;
  }
  return success;
  
}
bool Customer::robs()
{
  bool success;
  if(m_purchase_amount >= PURCHASE_MAX)
    success = false;
  return success;
}

void Customer::changeSat(int mood)
{
  m_satisfaction += mood;
  return;
}


void Customer::changeMoney(const int money)
{
  m_spending_money += money;
  return;
}

void Customer::changeInc(bool tf)
{
  m_inclination = tf;
  return;
}


ostream & operator <<(ostream & out, Customer & s)
{
  out << s.m_cust_name << " has $" << s.m_spending_money << " and purchases ";
  
  if(s.m_purchase_amount > 0)
  {
    for(int i = 0; i < s.m_purchase_amount; i++)
    {
      out << s.m_product[i].pName;
      if(s.m_purchase_amount -1 == i)
        out << ".";
      else
        out << ", ";
    }
  }
  else
    out << "nothing.";
  out << endl;
  return out;

}