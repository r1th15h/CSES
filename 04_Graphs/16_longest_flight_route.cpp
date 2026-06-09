#include<bits/stdc++.h>
using namespace std;

using ll = long long;

//dp apprach there check it*****

void dfs(int node,vector<int>&vis,vector<vector<int>>&adjlist,stack<int>&st){
    vis[node] = 1;
    for(auto it:adjlist[node]){
        if(!vis[it]){
            dfs(it,vis,adjlist,st);
        }
    }
    st.push(node);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>adjlist(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adjlist[a-1].push_back(b-1);
    }
    vector<int>vis(n,0);
    stack<int>st;
    vector<int>dist(n,-1e9);
    dfs(0,vis,adjlist,st);
    dist[0] = 0;
    vector<int>parent(n,-1);
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(dist[u]==-1e9) continue;
        for(auto it:adjlist[u]){
            if(dist[it]>=dist[u]+1) continue;
            parent[it] = u;
            dist[it] = dist[u]+1;
        }
    }
    if(dist[n-1]==-1e9){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int>path;
    int newp = n-1;
    while(parent[newp]!=-1){
        path.push_back(newp+1);
        newp = parent[newp];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(auto it:path) cout<<it<<" ";
    return 0;
}