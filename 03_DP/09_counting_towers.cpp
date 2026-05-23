#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    vector<vector<ll>>dp(1e6+1,vector<ll>(2,0));
    dp[1e6][0] = 1;
    dp[1e6][1] = 1;
    for(int i=1e6-1;i>=0;i--){
        dp[i][0] = 2*dp[i+1][0] + dp[i+1][1];
        dp[i][1] = dp[i+1][0] + 4*dp[i+1][1];
        dp[i][0]%=MOD;
        dp[i][1]%=MOD;
    }    
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        cout<<((dp[1e6-n+1][0]+dp[1e6-n+1][1])%MOD)<<endl;
    }
    return 0;
}