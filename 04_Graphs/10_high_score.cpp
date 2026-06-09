#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(vector<vector<int>>&adjlist,vector<int>&vis,int node){
    vis[node] = 1;
    for(auto it:adjlist[node]){
        if(!vis[it]){
            dfs(adjlist,vis,it);
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<ll>>edges;
    vector<vector<int>>adjlist(n);
    for(int i=0;i<m;i++){
        int a,b,x;
        cin>>a>>b>>x;
        edges.push_back({a-1,b-1,-x});
        adjlist[b-1].push_back(a-1);
    }
    vector<ll>dist(n,1e18);
    vector<int>vis(n,0);
    dfs(adjlist,vis,n-1);
    dist[0] = 0;
    for(int i=0;i<n-1;i++){
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int weight = it[2];
            if(dist[u]!=1e18 && dist[u]+weight<dist[v]){
                dist[v] = dist[u]+weight;
            }
        }
    }
    for(auto it:edges){
        int u = it[0];
        int v = it[1];
        int weight = it[2];
        if(dist[u]!=1e18 && dist[v]>dist[u]+weight && vis[v]){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<-(dist[n-1])<<endl;
    return 0;
}