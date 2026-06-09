#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>adjlist(n);
    vector<vector<ll>>dist(n,vector<ll>(2,1e18));
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adjlist[a-1].push_back({b-1,c});
    }
    //{cost,node,state}
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq;
    dist[0][1] = 0;
    pq.push({0,0,1});
    while(!pq.empty()){
        auto curr = pq.top();
        pq.pop();
        ll cost = curr[0];
        ll u = curr[1];
        ll state = curr[2];
        if(cost>dist[u][state]) continue;
        for(auto it:adjlist[u]){
            ll weight = it.second;
            int v = it.first;
            if(cost+weight<dist[v][state]){
                dist[v][state] = cost+weight;
                pq.push({dist[v][state],v,state});
            }
            if(state==1){
                ll newcost = cost + weight/2;
                if(newcost<dist[v][0]){
                    dist[v][0] = newcost;
                    pq.push({newcost,v,0});
                }
            }
        }
    }
    cout<<dist[n-1][0]<<endl;
    return 0;
}