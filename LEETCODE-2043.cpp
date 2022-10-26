#include<bits/stdc++.h>
using namespace std;
class Bank {
public:
    unordered_map<int,long long>m;
    Bank(vector<long long>& balance) {
        for(int i=0;i<balance.size();i++) {
            m[i+1]=balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1<1 || account1>m.size() || account2<1 || account2>m.size()) {
            return false;
        }
        if(m[account1]<money) {
            return false;
        }
        m[account1]-=money;
        m[account2]+=money;
        return true;
    }
    
    bool deposit(int account, long long money) { 
        if(account<1 || account>m.size()) {
            return false;
        }
        m[account]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account<1 || account>m.size() || m[account]<money) {
            return false;
        }
        m[account]-=money;
        return true;
    }
};
int main() {
    return 0;
}