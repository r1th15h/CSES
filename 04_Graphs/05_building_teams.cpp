#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int bfs(vector<vector<int>>&adjlist,vector<int>&vis,int node){
    queue<int>q;
    q.push(node);
    vis[node] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adjlist[node]){
            if(vis[it]==0){
                vis[it] = vis[node]==1 ? 2 : 1;
                q.push(it);
            }
            else if(vis[it]==vis[node]){
                return 0;
            }
        }
    }
    return 1;
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
        adjlist[b-1].push_back(a-1);
    }
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            if(!bfs(adjlist,vis,i)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(auto it:vis) cout<<it<<" ";
    return 0;
}