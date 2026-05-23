#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int x=1;x<=m;x++){
        if(nums[0]==x || nums[0]==0) dp[1][x] = 1;
    }
    for(int i=2;i<=n;i++){
        for(int x=1;x<=m;x++){
            if(nums[i-1]!=0 && nums[i-1]!=x) continue;
            for(int prev=x-1;prev<=x+1;prev++){
                if(prev<1 || prev>m) continue;
                dp[i][x] += dp[i-1][prev];
                dp[i][x]%=MOD;
            }
        }
    }
    long long ans = 0;
    for(int i=1;i<=m;i++){
        ans+=dp[n][i];
        ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}