#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int getmoves(int a,int b,vector<vector<int>>&dp){
    if(a==b) return 0;
    if(dp[a][b]!=-1) return dp[a][b];
    int lenpar = 0;
    int widpar = 0;
    int miniwid = INT_MAX;
    int minilen = INT_MAX;
    for(int i=1;i<a;i++){
        lenpar = 1+ getmoves(i,b,dp)+getmoves(a-i,b,dp);
        minilen = min(minilen,lenpar);
    }
    for(int i=1;i<b;i++){
        widpar = 1+ getmoves(a,i,dp)+getmoves(a,b-i,dp);
        miniwid = min(miniwid,widpar);
    }
    return dp[a][b] = min(minilen,miniwid);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b;
    cin>>a>>b;
    vector<vector<int>>dp(a+1,vector<int>(b+1,1e9));
    for(int i=0;i<=min(a,b);i++) dp[i][i] = 0;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j) continue;
            for(int k=1;k<i;k++){
                dp[i][j] = min(dp[i][j],1 + dp[k][j] + dp[i-k][j]);
            }
            for(int k=1;k<j;k++){
                dp[i][j] = min(dp[i][j],1 + dp[i][k] + dp[i][j-k]);
            }
        }
    }
    cout<<dp[a][b]<<endl;
    return 0;
}