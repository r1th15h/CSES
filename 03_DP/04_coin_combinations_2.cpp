#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 7+1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    vector<vector<int>>dp(n,vector<int>(x+1,0));
    for(int i=0;i<=x;i++){
        if(i%coins[0]==0) dp[0][i] = 1;
        else dp[0][i] = 0;
    }
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=x;sum++){
            int pick = 0;
            if(coins[ind]<=sum) pick = dp[ind][sum-coins[ind]];
            int notpick = dp[ind-1][sum];
            dp[ind][sum] = (pick+notpick)%MOD;
        }
    }
    cout<<dp[n-1][x]<<endl;
    return 0;
}