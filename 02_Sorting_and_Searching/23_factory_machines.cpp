#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool getans(ll mid,vector<int>&times,int t){
    ll ans = 0;
    for(auto it:times){
        ans += mid/it;
        if(ans>=t) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,t;
    cin>>n>>t;
    vector<int>times(n);
    for(int i=0;i<n;i++){
        cin>>times[i];
    }
    ll l = 1;
    ll r = 1e18;
    while(l<r){
        ll mid = l+(r-l)/2;
        if(getans(mid,times,t)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    cout<<r<<endl;
    return 0;
}