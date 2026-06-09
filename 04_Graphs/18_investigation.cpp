#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adjlist(n);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjlist[a-1].push_back({b-1,c});
    }
    //{cost,node}
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    vector<ll>dist(n,1e18);
    vector<ll>minw(n,0);
    vector<ll>maxw(n,0);
    vector<ll>ways(n,0);
    dist[0] = 0;
    ways[0] = 1;
    maxw[0] = 0;
    minw[0] = 0;
    pq.push({0,0});
    while(!pq.empty()){
        auto [w,u] = pq.top();
        pq.pop();
        if(dist[u]<w) continue;
        for(auto it:adjlist[u]){
            auto [v,cost] = it;
            if(dist[v]>w+cost){
                ways[v] = ways[u];
                dist[v] = w+cost;
                maxw[v] = maxw[u]+1;
                minw[v] = minw[u]+1;
                pq.push({dist[v],v});
            }
            else if(dist[v]==w+cost){
                ways[v] = (ways[v]+ways[u])%MOD;
                minw[v] = min(minw[v],minw[u]+1);
                maxw[v] = max(maxw[v],maxw[u]+1);
            }
        }
    }
    cout<<dist[n-1]<<" "<<ways[n-1]<<" "<<minw[n-1]<<" "<<maxw[n-1]<<endl;
    return 0;
}