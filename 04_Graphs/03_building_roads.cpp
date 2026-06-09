#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int node,vector<vector<int>>&adjlist,vector<int>&vis){
    vis[node] = 1;
    for(auto it:adjlist[node]){
        if(!vis[it]){
            dfs(it,adjlist,vis);
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>adjlist(n);
    vector<int>vis(n,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adjlist[a-1].push_back(b-1);
        adjlist[b-1].push_back(a-1);
    }
    int count = 0;
    vector<pair<int,int>>ans;
    dfs(0,adjlist,vis);
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        count++;
        ans.push_back({i,i+1});
        dfs(i,adjlist,vis);
    }
    cout<<count<<endl;
    for(auto it:ans){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}