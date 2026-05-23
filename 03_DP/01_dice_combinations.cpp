#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
const int MOD = 7+1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>dp(n+1);
    dp[0] = 1;
    for(int sum=1;sum<=n;sum++){
        for(int dice=1;dice<=6;dice++){
            if(dice>sum) continue;
            dp[sum] += dp[sum-dice];
            dp[sum]%=MOD;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}