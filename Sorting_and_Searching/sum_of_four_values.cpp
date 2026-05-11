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
        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j].first==nums[j-1].first) continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum = nums[i].first+nums[j].first;
                sum += nums[k].first+nums[l].first;
                if(sum==x){
                    cout<<nums[i].second<<" "<<nums[j].second<<" "<<nums[k].second<<" "<<nums[l].second<<endl;
                    return 0;
                }
                else if(sum>x) l--;
                else k++;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}