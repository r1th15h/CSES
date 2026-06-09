#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int getdist(int node,int k,vector<vector<int>>&dp){
    if(k<0) return -1;
    int x = node;
    for(int i=0;i<=18;i++){
        if(k & (1<<i)){
            x = dp[x][i];
        }
    }
    return x;
}

void dfs(int node,vector<int>&length,vector<int>&vis,vector<int>&nums){
    vis[node] = 1;
    if(!vis[nums[node]]) dfs(nums[node],length,vis,nums);
    length[node] = length[nums[node]]+1;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;
    vector<int>nums(n+1,-1);
    vector<vector<int>>dp(n+1,vector<int>(19,-1));
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    vector<int>length(n+1,0);
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
        dp[i][0] = nums[i];
        if(!vis[i]){
            dfs(i,length,vis,nums);
        }
    }
    for(int i=1;i<=18;i++){
        for(int j=1;j<=n;j++){
            dp[j][i] = dp[dp[j][i-1]][i-1];
        }
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        int cyclestart = getdist(a,length[a],dp);
        int ans = -1;
        if(getdist(a,length[a]-length[b],dp)==b) ans = length[a]-length[b];
        else if((getdist(cyclestart,length[cyclestart]-length[b],dp)==b)) ans = length[cyclestart]-length[b]+length[a];
        cout<<ans<<'\n';
    }
    return 0;
}