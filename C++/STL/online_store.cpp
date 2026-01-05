#include<iostream>
#include<string>
#include<deque>
#include<map>
#include<vector>
#include<set>
#include<list>
#include<ctime>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

struct Product
{
    int productID;
    string name;
    double price;
    int stock;
    string category;

};

struct Order
{
    int orderID;
    vector<Product> products;
    double totalAmount;
    time_t orderDate;
};

struct Customer
{
    int customerID;
    string name;
    string email;
    string address;
    vector<Order> orderHistory;
};


int main()
{
    vector<Product> products = {
        {1, "Laptop", 999.99, 10, "Electronics"},
        {2, "Smartphone", 499.99, 25, "Electronics"},
        {3, "Book", 19.99, 100, "Books"},
        {4, "Headphones", 79.99, 50, "Electronics"},
        {5, "Coffee Maker", 39.99, 15, "Home Appliances"}
    };


    deque<Customer> customers;
    customers.push_back({1, "Alice Smith", "alice@example.com", "123 Main St", {}});

    return 0;
}
