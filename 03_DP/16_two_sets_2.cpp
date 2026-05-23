#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

int getPossiblesum(int n,int num,ll& totsum,int sum){
    if(num>n){
        if(2*sum==totsum) return 1;
        return 0;
    }
    int pick = 0;
    if(2*(sum+num)<=totsum) pick = getPossiblesum(n,num+1,totsum,sum+num);
    int notpick = getPossiblesum(n,num+1,totsum,sum);
    return pick+notpick;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    ll totsum = (n*(n+1))/2;
    if(totsum%2!=0){
        cout<<0<<endl;
        return 0;
    }
    // cout<<getPossiblesum(n,1,totsum,0)/2<<endl;
    ll req = totsum/2;
    vector<vector<int>>dp(n+1,vector<int>(req+1,0));
    for(int i=0;i<=n;i++) dp[i][0] = 1;
    for(int i=1;i<n;i++){
        for(int sum=0;sum<=req;sum++){
            int pick = 0;
            if(i<=sum) pick = dp[i-1][sum-i];
            int notpick = dp[i-1][sum];
            dp[i][sum] = (pick+notpick)%MOD;
        }
    }
    cout<<dp[n-1][req]<<endl;
    return 0;
}