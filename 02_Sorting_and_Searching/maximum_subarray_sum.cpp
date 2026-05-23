#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    ll c = 0;
    ll maxc = LONG_LONG_MIN;
    for(auto it:nums){
        c+=it;
        maxc = max(maxc,c);
        if(c<0){
            c=0;
        }
    }
    cout<<maxc<<endl;
    return 0;
}