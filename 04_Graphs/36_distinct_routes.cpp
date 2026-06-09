#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll dfs(int node,int end,ll flow,vector<int>&vis,vector<vector<ll>>&adjmat){
    if(node==end) return flow;
    vis[node] = 1;
    for(int i=0;i<=end;i++){
        if(!vis[i] && adjmat[node][i]>0){
            ll flowval = dfs(i,end,min(flow,adjmat[node][i]),vis,adjmat);
            if(flowval){
                adjmat[node][i] -= flowval;
                adjmat[i][node] += flowval;
                return flowval;
            }
        }
    }
    return 0;
}

bool getPath(int u,int sink,vector<vector<int>>& flowgraph,vector<int>& path){
    path.push_back(u);
    if(u==sink) return true;
    while(!flowgraph[u].empty()){
        int v = flowgraph[u].back();
        flowgraph[u].pop_back();
        if(getPath(v,sink,flowgraph,path)) return true;
    }
    path.pop_back();
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<ll>>adjmat(n+1,vector<ll>(n+1,0));    
    vector<vector<ll>>orgadjmat(n+1,vector<ll>(n+1,0));    
    for(int i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        adjmat[a][b] = 1;
        orgadjmat[a][b] = 1;
    }
    vector<vector<int>>ans;
    while(true){
        vector<int>vis(n+1,0);
        ll flow = dfs(1,n,1e9,vis,adjmat);
        if(!flow) break;
    }
    vector<vector<int>>flowgraph(n+1);
    for(int u=1;u<=n;u++){
        for(int v=1;v<=n;v++){
            if(orgadjmat[u][v]>0 && adjmat[u][v]==0){
                flowgraph[u].push_back(v);
            }
        }
    }
    while(true){
        vector<int> path;
        if(!getPath(1,n,flowgraph,path)) break;
        ans.push_back(path);
    }
    cout << ans.size() << '\n';
    for(auto &p:ans){
        cout<<p.size()<<'\n';
        for(int x:p) cout<<x<<' ';
        cout<<'\n';
    }
    return 0;
}