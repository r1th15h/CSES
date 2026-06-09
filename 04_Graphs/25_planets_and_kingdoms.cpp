#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs1(int node,vector<vector<int>>&adjlsit,vector<int>&vis,stack<int>&st){
    vis[node] = 1;
    for(auto it:adjlsit[node]){
        if(!vis[it]) dfs1(it,adjlsit,vis,st);
    }
    st.push(node);
}

void dfs2(int node,vector<vector<int>>&adjlsit,vector<int>&vis,vector<int>&scc){
    vis[node] = 1;
    scc.push_back(node);
    for(auto it:adjlsit[node]){
        if(!vis[it]) dfs2(it,adjlsit,vis,scc);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>adjlist(n);
    vector<vector<int>>revadjlist(n);
    vector<int>vis1(n,0);
    vector<int>vis2(n,0);
    stack<int>st;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adjlist[a-1].push_back(b-1);
        revadjlist[b-1].push_back(a-1);
    }
    for(int i=0;i<n;i++){
        if(!vis1[i]) dfs1(i,adjlist,vis1,st);
    }
    vector<int>kingdoms(n);
    int comp = 0;
    while(!st.empty()){
        int i = st.top();
        st.pop();
        if(!vis2[i]){
            comp++;
            vector<int>scc;
            dfs2(i,revadjlist,vis2,scc);
            for(auto it:scc){
                kingdoms[it] = comp;
            }
        }
    }
    cout<<comp<<'\n';
    for(auto it:kingdoms) cout<<it<<" ";
    return 0;
}