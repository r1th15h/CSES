#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<pair<int,int>>nums(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        nums[i] = {a,i+1};
    }
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i].first==nums[i-1].first) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum = nums[i].first+nums[j].first+nums[k].first;
            if(sum==x){
                cout<<nums[i].second<<" "<<nums[j].second<<" "<<nums[k].second<<endl;
                return 0;
            }
            else if(sum<x) j++;
            else if(sum>x) k--;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}