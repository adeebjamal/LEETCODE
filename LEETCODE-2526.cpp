#include<bits/stdc++.h>
using namespace std;
class DataStream {
public:
    int value=0, k=0, curr_count=0;
    DataStream(int value, int k) {
        this->value=value;
        this->k=k;
    }
    
    bool consec(int num) {
        if(num==this->value) {
            this->curr_count++;
        }
        else {
            this->curr_count=0;
        }
        return this->curr_count >= this->k;
    }
};