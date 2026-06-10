#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void josephus(vector<int>& nums){
    int n = nums.size();
    if(n==1){
        cout<<nums[0]<<" ";
        return;
    }
    for(int i=1;i<n;i+=2) cout<<nums[i]<<" ";
    vector<int>newarr;
    if(n%2!=0){
        newarr.push_back(nums[n-1]);
    }
    for(int i=0;i<n-1;i+=2) newarr.push_back(nums[i]);
    josephus(newarr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=1;i<=n;i++) nums[i-1] = i;
    josephus(nums);
    return 0;
}