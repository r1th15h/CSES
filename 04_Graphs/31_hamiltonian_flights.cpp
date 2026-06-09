#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9+7;

int dfs(int node,int mask,int n,vector<vector<int>>&adjlist,vector<vector<ll>>&dp){
    mask ^= (1<<node);
    if(mask==0 && node==n-1) return 1;       
    if(node==n-1) return 0; 
    if(dp[node][mask]!=-1) return dp[node][mask];
    ll ans = 0;
    for(auto it:adjlist[node]){
        if(mask & (1<<it)){
            ans += dfs(it,mask,n,adjlist,dp);
            ans%=MOD;
        }
    }
    return dp[node][mask] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>adjlist(n);
    vector<vector<ll>>dp(n,vector<ll>((1<<n),-1));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adjlist[a-1].push_back(b-1);
    }
    cout<<dfs(0,(1<<n)-1,n,adjlist,dp)<<'\n';
    return 0;
}