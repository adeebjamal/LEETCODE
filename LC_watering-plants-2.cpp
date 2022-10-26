#include<bits/stdc++.h>
using namespace std;
int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
    int alice= capacityA;
    int bob= capacityB;
    int refill=0;
    int i=0;
    int j=plants.size()-1;
    while(i<j) {
        if(plants[i]<=capacityA) {
            capacityA-= plants[i];
            i++;
        }
        else if(plants[i]>capacityA) {
            refill++;
            capacityA=alice;
            capacityA-= plants[i];
            i++;
        }
        if(plants[j]<=capacityB) {
            capacityB-=plants[j];
            j--;
        }
        else if(plants[j]>capacityB) {
            refill++;
            capacityB= bob;
            capacityB-= plants[j];
            j--;
        }
    }
    if(i==j) {
        if(capacityA>capacityB) {
            if(capacityA<plants[i]) {
                refill++;
            }
        }
        else if(capacityB>capacityA) {
            if(capacityB<plants[j]) {
                refill++;
            }
        }
        else if(capacityA==capacityB) {
            if(capacityA<plants[i]) {
                refill++;
            }
        }
    }  
    return refill; 
}
int main() {
    vector<int> plants={2,2,3,3};
    int capacityA= 3;
    int capacityB= 4;
    cout<<minimumRefill(plants, capacityA, capacityB)<<endl;
    return 0;
}