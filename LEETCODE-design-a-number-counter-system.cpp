#include<bits/stdc++.h>
using namespace std;
class NumberContainers {
public:
    unordered_map<int,int> arr;
    unordered_map<int,set<int>> search;
    NumberContainers() {
        return;
    }
    
    void change(int index, int number) {
        arr[index]=number;
        search[number].insert(index);
    }
    
    int find(int number) {
        set<int> indexes=search[number];
        for(auto it=indexes.begin(); it != indexes.end(); it++) {
            if(arr[*it] == number) {
                return *it;
            }
        }
        return -1;
    }
};