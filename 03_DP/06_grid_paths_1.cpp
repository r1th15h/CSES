#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 7+1e9;

ll getCount(vector<vector<char>>&grid,int row,int col,vector<vector<ll>>&dp,int n){
    if(row<0 || col<0 || row>=n || col>=n) return 0;
    if(grid[row][col]=='*') return 0;
    if(row==n-1 && col==n-1) return 1;
    if(dp[row][col]!=-1) return dp[row][col];
    ll ans = getCount(grid,row,col+1,dp,n) + getCount(grid,row+1,col,dp,n);
    return dp[row][col] = ans%MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<ll>>dp(n,vector<ll>(n,0));
    if(grid[0][0]=='*'){
        cout<<0<<endl;
        return 0;
    }
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0) continue;
            if(grid[i][j]=='*') continue;
            ll left=0,up=0;
            if(j>0) left = dp[i][j-1];
            if(i>0) up = dp[i-1][j];
            dp[i][j] = (left+up)%MOD;
        }
    }
    cout<<dp[n-1][n-1]<<endl;
    return 0;   
}