#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>adjlist(n);
    vector<ll>dist(n,1e18);
    dist[0] = 0;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjlist[a-1].push_back({b-1,c});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto [weight,u] = pq.top();
        pq.pop();
        if(weight>dist[u]) continue;
        for(auto it:adjlist[u]){
            auto [v,newc] = it;
            if(dist[u]+newc<dist[v]){
                dist[v] = dist[u]+newc;
                pq.push({dist[v],v});
            }
        }
    }
    for(auto it:dist) cout<<it<<" ";
    return 0;
}