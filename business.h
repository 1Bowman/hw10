//Name: Alex Bowman and Tyler Hembrock   11.19.2013
//CS53 section F
//Description: Simulation of competing companies of Comic Book Guy and Moe.
// The program implements multiple classes and interactions between them.
//Business Header File

#ifndef BUSINESS_H
#define BUSINESS_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "customer.h"
#include "product.h"

using namespace std;
const int MAX_CUST = 20;
const int MAX_ITEMS = 10;

class Business
{
  private:
    string m_business_name;
    float m_register_money;
    short m_items_ammnt;
    short m_num_cust;
    product m_items_sold[MAX_ITEMS];
    Customer m_cust_objects[MAX_CUST];
    //product product[10];

  public:
    //Pre: n/a
    //Post: Sets name to empty, and register money, amount of items, and
    //      number of customers to zero
    //Description: default constructor for the business class
    Business();
    
    //Pre: Business name and money in the register must be passed to the funct.
    //Post: Sets the input business name and money in the register to what the
    // input values were.  It also sets the number of customers inside the 
    //business to zero and reads in the items in items.txt to m_items_sold[]
    //Function: Sets bName and regMoney to what the program defines
    Business(const string bName, const float regMoney, ifstream & fin);
    
    //Pre: None, because blank parameters are accepted
    //Post: Outputs name of the business, the name of each customer, their
    //money, and what they bought, along with all of the items available
    //Function: outputs name of business, what everyone bought, and how much
    // they have.
    void printBiz();
    
    //Pre: The program must have a Customer within the function
    //Post: places a customer in the customer array and increases the ammount
    // of customers by 1
    //Function: puts customers in the business
    void addCustomer(Customer custName);
    
    //Pre: must be ran by a business
    //Post: if the user has more than $40, then a random object is set to the
    //array of things thye purchased and decreases their net worth by $40
    //Function: assigns a random item to people with more than $40
    // void make_a_sale();

    //Pre:
    //Post:
    //Function: Walks down array, sees if customers are going to buy something
    //and invokes the buy_something() function, if they do buy something, the 
    //product and money will be transfered
    void sell_stuff();

    //Pre:
    //Post:
    //Function: Copies array of customers in the business to the array of 
    //customers in this function.
    void customers_leave();
    
    //Pre: None.
    //Post: allows the m_items_sold array to be accessible.
    //Function: Allows access to the m_items_sold array. Accessor.
    product getProducts();
    
    //Pre: None.
    //Post: The amount in the register is incremented by the money passed in.
    //Function: Adds to the register the amount passed in.
    void add_to_register(const int money);


};
#endif