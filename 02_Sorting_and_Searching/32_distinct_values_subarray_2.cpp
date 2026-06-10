#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    map<int,int>mpp;
    int l=0,r=0;
    ll c=0;
    while(r<n){
        mpp[nums[r]]++;
        while((int)mpp.size()>k){
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0) mpp.erase(nums[l]);
            l++;
        }
        c+=(r-l+1);
        r++;
    }
    cout<<c<<endl;
    return 0;
}