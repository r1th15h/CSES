#include<bits/stdc++.h>
using namespace std;

using ll = long long;

bool dfs(int node,vector<int>&vis,vector<int>&pathvis,vector<vector<int>>&adjlist,vector<int>&path){
    vis[node] = 1;
    pathvis[node] = 1;
    for(auto it:adjlist[node]){
        if(!vis[it]){
            if(dfs(it,vis,pathvis,adjlist,path)) return true;
        }
        else if(pathvis[it]==1) return true;
    }
    pathvis[node] = 0;
    path.push_back(node+1);
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
    vector<int>path;
    vector<int>vis(n,0);
    vector<int>pathvis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i,vis,pathvis,adjlist,path)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    reverse(path.begin(),path.end());
    for(auto it:path) cout<<it<<" ";
    // vector<int>indegree(n,0);
    // queue<int>q;
    // int count = 0;
    // for(int i=0;i<n;i++){
    //     for(auto it:adjlist[i]){
    //         indegree[it]++;
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     if(indegree[i]==0) q.push(i);
    // }
    // while(!q.empty()){
    //     int u = q.front();
    //     q.pop();
    //     count++;
    //     path.push_back(u+1);
    //     for(auto it:adjlist[u]){
    //         indegree[it]--;
    //         if(indegree[it]==0) q.push(it);
    //     }
    // }
    // if(count!=n) cout<<"IMPOSSIBLE"<<endl;
    // else{
    //     for(auto it:path) cout<<it<<" ";
    // }
    return 0;
}