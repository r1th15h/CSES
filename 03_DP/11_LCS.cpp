#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    vector<int>b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int row = n;
    int col = m;
    vector<int>ans;
    while(row>0 && col>0){
        if(a[row-1]==b[col-1]){
            ans.push_back(a[row-1]);
            row--;
            col--;
        }
        else{
            if(dp[row-1][col]>=dp[row][col-1]){
                row--;
            }
            else col--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<dp[n][m]<<endl;
    for(auto it:ans) cout<<it<<" ";
    return 0;
}