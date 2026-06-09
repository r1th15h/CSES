#include<bits/stdc++.h>
using namespace std;

using ll = long long;

bool dfs(int node,vector<int>&vis,vector<int>&pathvis,vector<vector<int>>&adjlist,int &startnode,int& endnode,vector<int>&parent){
    vis[node] = 1;
    pathvis[node] = 1;
    for(auto it:adjlist[node]){
        if(!vis[it]){
            parent[it] = node;
            if(dfs(it,vis,pathvis,adjlist,startnode,endnode,parent)) return true;
        }
        else if(pathvis[it]==1){
            startnode = it;
            endnode = node;
            return true;
        }
    }
    pathvis[node] = 0;
    return false;
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
    int start = -1;
    int end = -1;
    vector<int>vis(n,0);
    vector<int>pathvis(n,0);
    vector<int>parent(n,-1);
    vector<int>path;
    for(int i=0;i<n;i++){
        if(!vis[i] && start==-1) dfs(i,vis,pathvis,adjlist,start,end,parent);
    }
    if(start==-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    path.push_back(start);
    while(end!=start){
        path.push_back(end);
        end = parent[end];
    }
    path.push_back(start);
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(auto it:path) cout<<it+1<<" ";
    return 0;
}