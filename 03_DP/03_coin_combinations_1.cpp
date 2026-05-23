#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 7+1e9;

int getCombinations(vector<int>&coins,int n,int x){
    if(x==0) return 1;
    int pick=0;
    for(int i=0;i<n;i++){
        if(coins[i]<=x) pick += getCombinations(coins,n,x-coins[i]);
    }
    return pick;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    vector<int>dp(x+1,0);
    dp[0] = 1;
    for(int sum=1;sum<=x;sum++){
        for(int i=0;i<n;i++){
            if(coins[i]<=sum) dp[sum] += dp[sum-coins[i]];
            dp[sum]%=MOD;
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}