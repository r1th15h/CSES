#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9+7;

//check for DP approach*****

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
    vector<ll>ways(n,0);
    ways[0] = 1;
    dfs(0,vis,adjlist,st);
    while(!st.empty()){
        int u = st.top();
        st.pop();
        for(auto it:adjlist[u]){
            if(ways[it]==0) ways[it] = ways[u];
            else ways[it] = (ways[it]+ways[u])%MOD;
        }
    }
    cout<<ways[n-1]<<endl;
    return 0;
}