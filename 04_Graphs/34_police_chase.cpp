#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int dfs(int node,int end,int flow,vector<int>&vis,vector<vector<int>>&cap){
    if(node==end) return flow;
    vis[node] = 1;
    for(int i=1;i<=end;i++){
        if(!vis[i] && cap[node][i]!=0){
            int flowval = dfs(i,end,min(flow,cap[node][i]),vis,cap);
            if(flowval){
                cap[node][i] -= flowval;
                cap[i][node] += flowval;
                return flowval;
            }
        }
    }
    return 0;
}

void mark(int node,int end,vector<int>&vis,vector<vector<int>>&cap){
    vis[node] = 1;
    for(int i=1;i<=end;i++){
        if(!vis[i] && cap[node][i]!=0){
            mark(i,end,vis,cap);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>cap(n+1,vector<int>(n+1,0));
    vector<pair<int,int>>edges;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        cap[a][b] = 1;
        cap[b][a] = 1;
        edges.push_back({a,b});
    }
    int maxflow = 0;
    while(true){
        vector<int>vis(n+1,0);
        int flowval = dfs(1,n,1e9,vis,cap);
        if(!flowval) break;
        maxflow+=flowval;   
    }
    cout<<maxflow<<'\n';
    vector<int>vis(n+1,0);
    mark(1,n,vis,cap);
    for(auto [u,v]:edges){
        if(vis[u] && !vis[v]) cout<<u<<" "<<v<<'\n';
        else if(!vis[u] && vis[v]) cout<<v<<" "<<u<<'\n';
    }
    return 0;
}