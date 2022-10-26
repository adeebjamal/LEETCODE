#include<bits/stdc++.h>
using namespace std;
class Cashier {
public:
    int number;
    unordered_map<int,int> mp;  // <product ID, price>
    int customer_number;
    double discount;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->number=n;
        this->discount=(double)(100 - discount)/100;
        int len=products.size();
        for(int i=0; i<len; i++) {
            mp[products[i]]=prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        customer_number++;
        double total=0; 
        int len=product.size();
        for(int i=0; i<len; i++) {
            total+= mp[product[i]] * amount[i];
        }
        if(customer_number % number == 0) {
            return total*((100-discount)/100);
        }
        return total;
    }
};