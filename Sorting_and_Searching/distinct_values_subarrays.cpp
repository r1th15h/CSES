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
    map<int,int>mpp;
    int l=0,r=0;
    ll c=0,maxc=0;
    while(r<n){
        if(mpp.find(nums[r])!=mpp.end() && mpp[nums[r]]>=l){
            l = mpp[nums[r]]+1;
        }
        mpp[nums[r]] = r;
        c+= (r-l+1);
        maxc = max(maxc,c);
        r++;
    }
    cout<<maxc<<endl;
    return 0;
}