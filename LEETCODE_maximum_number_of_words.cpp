#include<bits/stdc++.h>
using namespace std;
int mostWordsFound(vector<string>& sentences) {
        vector<int> deq;
        for(string sentence: sentences) {
            int count=0;
            for(char i: sentence) {
                if(i==' ') {
                    count++;
                }
            }
            deq.push_back(count+1);
        }
        sort(deq.begin(), deq.end());
        return deq.back();
    }
int main() {
    vector<string> sentences;
    for(int i=0; i<3; i++) {
        string str="";
        getline(cin,str);
        sentences.push_back(str);
    }
    cout<<mostWordsFound(sentences)<<endl;
    return 0;
}