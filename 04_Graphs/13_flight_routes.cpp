#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<ll,ll>>>adjlist(n);
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        adjlist[a-1].push_back({b-1,c});
    }
    vector<priority_queue<ll>>maxheap(n);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0,0});
    maxheap[0].push(0);
    while(!pq.empty()){
        auto [w,u] = pq.top();
        pq.pop();
        if(w>maxheap[u].top()) continue;
        for(auto it:adjlist[u]){
            auto [v,cost] = it;
            ll newcost = cost+w;
            if((int)maxheap[v].size()<k){
                maxheap[v].push(newcost);
                pq.push({newcost,v});
            }
            else if(newcost<maxheap[v].top()){
                maxheap[v].pop();
                maxheap[v].push(newcost);
                pq.push({newcost,v});
            }
        }
    }
    vector<ll>ans;
    while(!maxheap[n-1].empty()){
        ans.push_back(maxheap[n-1].top());
        maxheap[n-1].pop();
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans) cout<<it<<" ";
    return 0;
}