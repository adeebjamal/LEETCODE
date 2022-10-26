#include<bits/stdc++.h>
using namespace std;
void func(string& num, vector<string>& vec) {
    string temp="";
    for(char& ch: num) {
        if(ch=='+') {
            vec.push_back(temp);
            temp="";
        }
        else {
            temp.push_back(ch);
        }
    }
    vec.push_back(temp);
    vec[1].pop_back();
}
string complexNumberMultiply(string num1, string num2) {
    vector<string> a,b;
    func(num1,a);
    func(num2,b);
    int real=0, img=0;
    real+= stoi(a[0])*stoi(b[0]);
    real+= -1*(stoi(a[1])*stoi(b[1]));
    img+= stoi(a[0])*stoi(b[1]);
    img+= stoi(a[1])*stoi(b[0]);
    return to_string(real) + "+" + to_string(img) + "i";
}
int main() {
    string num1="", num2="";
    cin>>num1>>num2;
    cout<<complexNumberMultiply(num1,num2)<<endl;
    return 0;
}