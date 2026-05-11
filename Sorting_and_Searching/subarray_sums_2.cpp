#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    map<ll,ll>mpp;
    mpp[0] = 1;
    ll sum=0,c=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        ll target = sum-x;
        if(mpp.find(target)!=mpp.end()) c+=mpp[target];
        mpp[sum]++;
    }
    cout<<c<<endl;
    return 0;
}