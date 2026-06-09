#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs1(int node,vector<int>&vis,vector<vector<int>>&adjlist,stack<int>&st){
    vis[node] = 1;
    for(auto it:adjlist[node]){
        if(!vis[it]) dfs1(it,vis,adjlist,st);
    }
    st.push(node);
}

void dfs2(int node,vector<int>&vis,vector<vector<int>>&adjlist,vector<int>&scc,int compno){
    vis[node] = 1;
    scc[node] = compno;
    for(auto it:adjlist[node]){
        if(!vis[it]) dfs2(it,vis,adjlist,scc,compno);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    vector<vector<int>>adjlist(n);
    vector<vector<int>>revadjlist(n);
    vector<pair<int,int>>edges(m);
    vector<int>vis1(n,0);
    vector<int>vis2(n,0);
    stack<int>st;
    int compno = 0;
    vector<int>scc(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adjlist[a-1].push_back(b-1);
        revadjlist[b-1].push_back(a-1);
        edges[i] = {a-1,b-1};
    }
    for(int i=0;i<n;i++){
        if(!vis1[i]) dfs1(i,vis1,adjlist,st);
    }
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        if(!vis2[curr]){
            dfs2(curr,vis2,revadjlist,scc,compno);
            compno++;
        }
    }
    vector<ll>newnodes(compno);
    int newn = newnodes.size();
    for(int i=0;i<(int)scc.size();i++){
        newnodes[scc[i]] += coins[i];
    }
    vector<int>vis3(newn,0);
    vector<vector<int>>newadjlist(newn);
    stack<int>st2;
    for(auto [u,v]:edges){
        if(scc[u]!=scc[v]){
            newadjlist[scc[u]].push_back(scc[v]);
        }
    }
    for(int i=0;i<newn;i++){
        if(!vis3[i]) dfs1(i,vis3,newadjlist,st2);
    }
    vector<ll>maxval(newn);
    for(int i=0;i<newn;i++) maxval[i] = newnodes[i];
    while(!st2.empty()){
        int u = st2.top();
        st2.pop();
        for(auto it:newadjlist[u]){
            maxval[it] = max(maxval[it],maxval[u]+newnodes[it]);
        }
    }
    ll ans = 0;
    for(auto it:maxval) ans = max(ans,it);
    cout<<ans<<'\n';
    return 0;
}