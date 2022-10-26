#include<bits/stdc++.h>
using namespace std;
bool IsSorted(deque<int>& arr) {
    int i=0;
    for(i=0; i<arr.size()-1; i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}
int main() {
    deque<int> deq={3,4,5,1,2};
    bool ans=false;
    for(int i=0; i<deq.size(); i++){
        if(IsSorted(deq)) {
            ans=true;
        }
        else {
            deq.push_front(*(deq.end()-1));
            deq.erase(deq.end()-1);
        }
    }
    cout<<ans<<endl;
    return 0;
}