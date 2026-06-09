#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int findnode(int node,int k,vector<vector<int>>&dp){
    int x = node;
    for(int i=0;i<30;i++){
        if(k & (1<<i)){
            x = dp[x][i];
        }
    }
    return x;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,q;
    cin>>n>>q;
    vector<vector<int>>dp(n+1,vector<int>(30,-1));
    for(int i=1;i<=n;i++) cin>>dp[i][0];
    for(int i=1;i<30;i++){
        for(int j=1;j<=n;j++){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }
    for(int i=0;i<q;i++){
        int node,k;
        cin>>node>>k;
        cout<<findnode(node,k,dp)<<'\n';
    }
    return 0;
}
