#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<ll>>edges;
    vector<ll>dist(n,0);
    vector<int>parent(n,-1);
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a-1,b-1,c});
    }
    for(int i=0;i<n-1;i++){
        for(auto it:edges){
            int u = it[0];
            int v =it[1];
            ll cost = it[2];
            if(dist[u]+cost<dist[v]){
                parent[v] = u;
                dist[v] = dist[u]+cost;
            }
        }
    }
    int start = -1;
    for(auto it:edges){
        int u = it[0];
        int v =it[1];
        ll cost = it[2];
        if(dist[u]+cost<dist[v]){
            dist[v] = dist[u]+cost;
            parent[v] = u;
            start = v;
        }
    }
    if(start==-1) cout<<"NO"<<endl;
    else{
        for(int i=0;i<n;i++) start = parent[start];
        vector<int>cycleord;
        cycleord.push_back(start);
        int curr = parent[start];
        while(curr!=start){
            cycleord.push_back(curr);
            curr = parent[curr];
        }
        cycleord.push_back(start);
        cout<<"YES"<<endl;
        reverse(cycleord.begin(),cycleord.end());
        for(auto it:cycleord) cout<<it+1<<" ";    
        cout<<endl;
    }
    return 0;
}