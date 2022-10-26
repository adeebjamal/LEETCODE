#include<bits/stdc++.h>
using namespace std;
double angleClock(int hour, int minutes) {
    double min_angle= minutes * 6.0;
    double hour_angle= hour * 30;
    hour_angle+= 0.5 * minutes;
    double ans= abs(min_angle - hour_angle);
    if(ans>180) {
        return 360.0 - ans;
    }
    return ans;
}
int main() {
    int h=0, m=0;
    cin>>h>>m;
    cout<<angleClock(h,m)<<endl;
    return 0;
}