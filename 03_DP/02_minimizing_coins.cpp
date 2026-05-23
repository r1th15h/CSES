#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    vector<vector<int>>dp(n,vector<int>(x+1,0));
    for(int i=0;i<=x;i++){
        if(i%coins[0]==0) dp[0][i] = i/coins[0];
        else dp[0][i] = 1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int sum=1;sum<=x;sum++){
            int pick = 1e9;
            if(coins[ind]<=sum) pick = 1+dp[ind][sum-coins[ind]];
            int notpick = dp[ind-1][sum];
            dp[ind][sum] = min(pick,notpick);
        }
    }
    int ans = dp[n-1][x]<1e9? dp[n-1][x]:-1;
    cout<<ans<<endl;
    return 0;
}