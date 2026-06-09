#include<bits/stdc++.h>
using namespace std;

using ll = long long;

bool dfs(vector<vector<int>>&adjlist,vector<int>&vis,int node,vector<int>&parent,int prev,int &start,int &end){
    vis[node] = 1;
    for(auto it:adjlist[node]){
        if(!vis[it]){
            parent[it] = node;
            if(dfs(adjlist,vis,it,parent,node,start,end)) return true;
        }
        else if(prev!=it){
            start = it;
            end = node;
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>adjlist(n);
    vector<int>vis(n,0);
    vector<int>parent(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adjlist[a-1].push_back(b-1);
        adjlist[b-1].push_back(a-1);
    }
    int start=-1,end=-1;
    bool y = false;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(adjlist,vis,i,parent,-1,start,end)){
                y=true;
                break;
            }
        }
    }
    if(!y){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int>path;
    int ind = end;
    path.push_back(start);
    while(ind!=start){
        path.push_back(ind);
        ind = parent[ind];
    }
    path.push_back(start);
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(auto it:path) cout<<it+1<<" "; 
    return 0;
}