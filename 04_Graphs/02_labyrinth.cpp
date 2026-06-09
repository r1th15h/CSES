#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void bfs(vector<vector<char>>&grid,vector<vector<char>>&vis,int i,int j,vector<int>&delrow,vector<int>&delcol,vector<char>&dir,vector<vector<pair<int,int>>>&parent,int n,int m){
    queue<pair<int,int>>q;
    q.push({i,j});
    vis[i][j] = 'S';
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int r = curr.first;
        int c = curr.second;
        for(int x=0;x<4;x++){
            int row = r+delrow[x];
            int col = c+delcol[x];
            if(row>=0 && col>=0 && row<n && col<m && vis[row][col]=='0' && ((grid[row][col]=='.')||(grid[row][col]=='B'))){
                q.push({row,col});
                vis[row][col] = dir[x];
                parent[row][col] = {r,c};
            }
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
    vector<vector<char>>vis(n,vector<char>(m,'0'));
    vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m,{-1,-1}));
    vector<int>delrow = {0,0,1,-1};
    vector<int>delcol = {1,-1,0,0,};
    vector<char>dir = {'R','L','D','U'};
    pair<int,int> start,end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A') start = {i,j};
            else if(grid[i][j]=='B') end = {i,j};
        }
    }
    string ans = "";
    bfs(grid,vis,start.first,start.second,delrow,delcol,dir,parent,n,m);
    if(vis[end.first][end.second]=='0') cout<<"NO"<<endl;
    else{
        int sr = end.first,sc = end.second;
        while(vis[sr][sc]!='S'){
            ans+= vis[sr][sc];
            int newr = parent[sr][sc].first;
            int newc = parent[sr][sc].second;
            sr = newr;
            sc = newc;
        }
        reverse(ans.begin(),ans.end());
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }
    return 0;
}