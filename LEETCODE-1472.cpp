#include<bits/stdc++.h>
using namespace std;
class BrowserHistory {
public:
    vector<string>browser;
    int pos=0;
    BrowserHistory(string homepage) {
        browser.push_back(homepage);
    }
    
    void visit(string url) {
        pos++;
        if(pos<=browser.size()-1){
            browser[pos]=url;
            browser.resize(pos+1);
            return;
        }
        browser.push_back(url);       
    }
    string back(int steps) {
        pos-=steps;
        if(pos<0){
            pos=0;
        }
        return browser[pos];
    }
    
    string forward(int steps) {
        pos+=steps;
        if(pos>browser.size()-1){
            pos=browser.size()-1;
        }
        return browser[pos];
    }
};