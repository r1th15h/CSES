#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 7+1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>nums(n);
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        mpp[nums[i]]++;
    }
    ll ans = 1;
    for(auto it:mpp){
        ans *= (it.second+1);
        ans %= MOD;
    }
    cout<<ans-1<<endl;
    return 0;
}