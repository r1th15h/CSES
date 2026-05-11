#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool ispossible(int k,vector<int>&nums,ll mid){
    ll sum = 0;
    for(int i=0;i<(int)nums.size();i++){
        sum+=nums[i];
        if(sum>mid){
            sum = nums[i];
            k--;
            if(k<=0) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    ll sum = 0;
    for(auto it:nums) sum+=it;
    ll high = sum;
    ll low = *max_element(nums.begin(),nums.end());
    while(low<high){
        ll mid = low+(high-low)/2;
        if(ispossible(k,nums,mid)){
            high = mid;
        }
        else low = mid+1;
    }
    cout<<high<<endl;
    return 0;
}