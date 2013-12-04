//Name: Alex Bowman and Tyler Hembrock   11.19.2013
//CS53 section F
//Description: Simulation of competing companies of Comic Book Guy and Moe.
// The program implements multiple classes and interactions between them.
//Customer Header File

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "product.h"

using namespace std;

const int PURCHASE_MAX = 20;
//static int randItem;

class Customer
{
  private:
    short m_purchase_amount;
    product m_product[PURCHASE_MAX]; //m_purchase_amount in case I forgot to change to the new name
    int m_satisfaction;
    bool m_inclination; 
    //unspecified member variables, but used in last program
    float m_spending_money;
    string m_cust_name;
  public:

    //Pre: n/a
    //Post: sets customer name to an empty string, the amount of purchases
    // they've made to 0, and sets a random amount of spending money between
    // 4 and 250 doll hairs
    //Function: default constructor
    Customer();
    
    //Pre: The program must input values for spending money and the customers
    // name
    //Post: Constructor setting the customers name, amount of spending money
    //to program defined values and the amount of purchases they've made to 0
    //Function:
    Customer(float money, string name);
    
    //Pre:
    //Post:
    //Function:
    bool buy_something(product item);

    //Pre: must take in an item purchased from 'items.txt'
    //Post: if spending money is more than $40, then it sets the defined 
    //value of 'itemPurchased' to a value in the purchased item array
    //Function: sets the array of m_purchases to a value from 'items.txt'
    // if the user has enough money
    //bool purchase(string itemPurchased);
    
    //Pre:
    //Post:
    //Function:
    //void throw();  Not here yet

    //Pre:
    //Post:
    //Function:
    //void rob();    Not here yet

    //Pre: n/a
    //Post: sets getMoney to m_spending_money
    //Function: accessor for spending_money
    float getMoney() const {return m_spending_money;}
    
    //Pre: n/a
    //Post:  sets getName to m_cust_name
    //Function: accessor for customer name
    string getName() const {return m_cust_name;}
  
    //Pre: an integer value of money must be passed in
    //Post: returns an added amount of money to m_spending_money
    //Function:  adds whatever is passed into the function to m_spending_money
    void changeMoney(const int money);
    
    //Pre:
    //Post:
    //Function:
    void printCust();

    //Pre: must be initialized by a value of customer
    //Post: outputs a template of the customers name, how much money they
    // have, and what they purchased (if anything)
    //Function: prints a set template of what values the user holds
    // void printCust();

    /*OVERLOAD THE << OPERATOR AS A FRIEND AS TO OUTPUT THE CUSTOMER
    OBJECTS VALUES IN NORMAL PEOPLE FORMAT */
};

#endif