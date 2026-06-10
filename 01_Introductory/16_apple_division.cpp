#include<bits/stdc++.h>
using namespace std;

long long solve(vector<int>&nums,long long total,int ind,long long sum){
    if(ind==(int)nums.size()){
        return abs(total-(2*sum));
    }
    long long pick = solve(nums,total,ind+1,sum+nums[ind]);
    long long notpick = solve(nums,total,ind+1,sum);
    return min(pick,notpick);
}

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    long long sum = 0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum+=nums[i];
    }
    cout<<solve(nums,sum,0,0)<<endl;
    return 0;
}