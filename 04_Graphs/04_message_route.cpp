#include<bits/stdc++.h>
using namespace std;

using ll = long long;

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
    vector<int>parent(n);
    for(int i=0;i<n;i++) parent[i] = i;
    queue<int>q;
    q.push(0);
    vis[0] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it:adjlist[node]){
            if(!vis[it]){
                parent[it] = node;
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    if(vis[n-1]==1){
        vector<int>path;
        int ind = n-1;
        while(parent[ind]!=ind){
            path.push_back(ind);
            ind = parent[ind];
        }
        path.push_back(0);
        reverse(path.begin(),path.end());
        cout<<path.size()<<endl;
        for(auto it:path) cout<<it+1<<" ";
    }
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}