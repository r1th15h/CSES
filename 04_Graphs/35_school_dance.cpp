#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll dfs(int node,int end,ll flow,vector<int>&vis,vector<vector<ll>>&adjmat){
    if(node==end) return flow;
    vis[node] = 1;
    for(int i=0;i<=end;i++){
        if(!vis[i] && adjmat[node][i]>0){
            ll flowval = dfs(i,end,min(flow,adjmat[node][i]),vis,adjmat);
            if(flowval){
                adjmat[node][i] -= flowval;
                adjmat[i][node] += flowval;
                return flowval;
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>>adjmat(n+m+2,vector<ll>(n+m+2));
    for(int i=1;i<=n;i++){
        adjmat[0][i] = 1;
    }
    for(int i=0;i<k;i++){
        ll a,b;
        cin>>a>>b;
        adjmat[a][n+b] = 1;
    }
    for(int i=n+1;i<=n+m;i++){
        adjmat[i][n+m+1] = 1;
    }
    ll ans = 0;
    while(true){
        vector<int>vis(n+m+2,0);
        ll flow = dfs(0,n+m+1,1e9,vis,adjmat);
        if(!flow) break;
        ans+=flow;
    }
    cout<<ans<<'\n';
    for(int boy=1;boy<=n;boy++){
        for(int girl=n+1;girl<=n+m;girl++){
            if(adjmat[girl][boy]>0){
                cout<<boy<<" "<<girl-n<<'\n';
            }
        }
    }
    return 0;
}