#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void psefunc(vector<int>&nums,vector<int>&pse){
    stack<pair<int,int>>st;
    for(int i=0;i<(int)nums.size();i++){
        while(!st.empty() && st.top().first>=nums[i]){
            st.pop();
        }
        st.empty() ? pse[i]=0 : pse[i]=st.top().second;
        st.push({nums[i],i+1});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>nums(n);
    vector<int>pse(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    psefunc(nums,pse);
    for(auto it:pse) cout<<it<<" ";
    return 0;
}