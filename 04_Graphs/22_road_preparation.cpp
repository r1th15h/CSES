#include<bits/stdc++.h>
using namespace std;

using ll = long long;

class DSU{
    private:
        vector<int>size;
        vector<int>parent;
    public:
        DSU(int n){
            size.resize(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++) parent[i] = i;
        }
        int findparent(int node){
            if(parent[node]==node) return node;
            parent[node] = findparent(parent[node]);
            return parent[node];
        }
        void uniongraph(int u,int v){
            int ultu = findparent(u);
            int ultv = findparent(v);
            if(ultu==ultv) return;
            if(size[ultu]>size[ultv]){
                size[ultu]+=size[ultv];
                parent[ultv] = ultu;
            }
            else{
                size[ultv]+=size[ultu];
                parent[ultu] = ultv;
            }
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    // vector<vector<pair<int,int>>>adjlist(n);
    // vector<int>vis(n,0);
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    // for(int i=0;i<m;i++){
    //     int a,b,c;
    //     cin>>a>>b>>c;
    //     adjlist[a-1].push_back({b-1,c});
    //     adjlist[b-1].push_back({a-1,c});
    // }
    // pq.push({0,0});
    // ll cost = 0;
    // int count = 0;
    // while(!pq.empty()){
    //     auto [w,u] = pq.top();
    //     pq.pop();
    //     if(vis[u]) continue;
    //     vis[u] = 1;
    //     cost+=w;
    //     count++;
    //     for(auto it:adjlist[u]){
    //         auto [v,weight] = it;
    //         if(!vis[v]){
    //             pq.push({weight,v});
    //         }
    //     }
    // }
    // if(count!=n) cout<<"IMPOSSIBLE"<<'\n';
    // else cout<<cost<<'\n';
    
    vector<vector<int>>edges(m);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges[i] = {c,a-1,b-1};
    }
    sort(edges.begin(),edges.end());
    DSU dsu(n);
    ll cost = 0;
    int count = 0;
    for(auto &it:edges){
        int c = it[0];
        int u = it[1];
        int v = it[2];
        if(dsu.findparent(u)!=dsu.findparent(v)){
            dsu.uniongraph(u,v);
            cost+=c;
            count++;
        }
    }
    if(count!=n-1) cout<<"IMPOSSIBLE"<<'\n';
    else cout<<cost<<'\n';
    return 0;
}