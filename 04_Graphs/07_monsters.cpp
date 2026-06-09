#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void bfs(vector<vector<int>>&vis,vector<vector<char>>&grid,vector<vector<int>>&cost,vector<vector<pair<int,int>>>&parent,vector<vector<char>>&direction,int i,int j,int n,int m){
    queue<pair<int,int>>q;
    vector<int>delrow = {0,0,1,-1};
    vector<int>delcol = {1,-1,0,0};
    vector<char>dir = {'R','L','D','U'};
    q.push({i,j});
    cost[i][j] = 0;
    vis[i][j] = 1;
    while(!q.empty()){
        auto [row,col] = q.front();
        q.pop();
        for(int x=0;x<4;x++){  
            int r = row+delrow[x];
            int c = col+delcol[x];
            if(r>=0 && c>=0 && r<n && c<m && vis[r][c]==0 && grid[r][c]!='#' && grid[r][c]!='M'){
                cost[r][c] = cost[row][col]+1;
                vis[r][c] = 1;
                parent[r][c] = {row,col};
                direction[r][c] = dir[x];
                q.push({r,c});
            }
        }
    }
    return;
}
void bfsmonst(vector<vector<int>>&vis,vector<vector<char>>&grid,vector<vector<int>>&cost,queue<pair<int,int>>&q,int n,int m){
    vector<int>delrow = {0,0,1,-1};
    vector<int>delcol = {1,-1,0,0};
    while(!q.empty()){
        auto [row,col] = q.front();
        q.pop();
        for(int x=0;x<4;x++){  
            int r = row+delrow[x];
            int c = col+delcol[x];
            if(r>=0 && c>=0 && r<n && c<m && vis[r][c]==0 && grid[r][c]!='#'){
                cost[r][c] = cost[row][col]+1;
                q.push({r,c});
                vis[r][c] = 1;
            }
        }
    }
    return;
}

int getpath(vector<vector<pair<int,int>>>&parent,vector<vector<char>>&direction,int r,int c,pair<int,int>coord){
    string ans = "";
    while(r!=coord.first || c!=coord.second){
        ans+=direction[r][c];
        int newr = parent[r][c].first;
        int newc = parent[r][c].second;
        r = newr;
        c = newc;
    }
    reverse(ans.begin(),ans.end());
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    cout<<ans<<endl;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        if(grid[i][0]=='A' || grid[i][m-1]=='A'){
            cout<<"YES"<<endl;
            cout<<0<<endl;
            return 0;
        }
    }
    for(int i=0;i<m;i++){
        if(grid[0][i]=='A' || grid[n-1][i]=='A'){
            cout<<"YES"<<endl;
            cout<<0<<endl;
            return 0;
        }
    }
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>monstvis(n,vector<int>(m,0));
    vector<vector<int>>humancost(n,vector<int>(m,1e9));
    vector<vector<int>>monstcost(n,vector<int>(m,1e9));
    vector<vector<pair<int,int>>>parent(n,vector<pair<int,int>>(m,{-1,-1}));
    vector<vector<char>>direction(n,vector<char>(m));
    queue<pair<int,int>>q;
    pair<int,int>coord;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.' || grid[i][j] == '#') continue;
            else if(grid[i][j]=='A'){
                bfs(vis,grid,humancost,parent,direction,i,j,n,m);
                coord = {i,j};
            }
            else{
                q.push({i,j});
                monstcost[i][j] = 0;
                monstvis[i][j] = 1;
            }
        }
    }
    bfsmonst(monstvis,grid,monstcost,q,n,m);
    for(int i=0;i<n;i++){
        if(grid[i][0]=='.' && humancost[i][0]<monstcost[i][0]) return getpath(parent,direction,i,0,coord);
        else if(grid[i][m-1]=='.' && humancost[i][m-1]<monstcost[i][m-1]) return getpath(parent,direction,i,m-1,coord);
        
    }
    for(int i=0;i<m;i++){
        if(grid[0][i]=='.' && humancost[0][i]<monstcost[0][i]) return getpath(parent,direction,0,i,coord);
        else if(grid[n-1][i]=='.' && humancost[n-1][i]<monstcost[n-1][i]) return getpath(parent,direction,n-1,i,coord);
    }
    cout<<"NO"<<endl;
    return 0;
}