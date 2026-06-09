#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis,vector<int>&delrow,vector<int>&delcol,int n,int m){
    vis[i][j] = 1;
    for(int k=0;k<4;k++){
        int r = i+delrow[k];
        int c = j+delcol[k];
        if(r>=0 && c>=0 && r<n && c<m && vis[r][c]==0 && grid[r][c]=='.'){
            dfs(r,c,grid,vis,delrow,delcol,n,m);
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<int>delrow = {0,0,1,-1};
    vector<int>delcol = {1,-1,0,0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.' && vis[i][j]==0){
                dfs(i,j,grid,vis,delrow,delcol,n,m);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}