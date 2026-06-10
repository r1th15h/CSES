#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    sort(coins.begin(),coins.end());
    ll maxi = 0;
    for(auto it:coins){
        if(it>maxi+1){
            cout<<maxi+1<<endl;
            return 0;
        }
        maxi += it;
    }
    cout<<maxi+1<<endl;
    return 0;
}