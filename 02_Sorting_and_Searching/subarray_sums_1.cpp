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
    int l=0,r=0;
    ll sum = 0;
    ll c = 0; 
    while(r<n){
        sum+=nums[r];
        while(sum>x){
            sum-=nums[l];
            l++;
        }
        if(sum==x) c++;
        r++;
    }
    cout<<c<<endl;
    return 0;
}