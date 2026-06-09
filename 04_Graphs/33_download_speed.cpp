#include<bits/stdc++.h>
using namespace std;

using ll = long long;

//4 algo dfs,bfs,dincic,scalabilty

bool dfs(int node,int end,vector<vector<ll>>&adjmat,vector<int>&vis,vector<int>&path,ll threshold){
    vis[node] = 1;
    if(node==end){
        path.push_back(node);
        return true;
    }
    for(int i=1;i<=end;i++){
        if(adjmat[node][i]==-1) continue;
        if(vis[i]) continue;
        if(adjmat[node][i]<threshold) continue;
        if(dfs(i,end,adjmat,vis,path,threshold)){
            path.push_back(node);
            return true;
        }
    }
    return false;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    ll sum = 0;
    vector<vector<ll>>adjmat(n+1,vector<ll>(n+1,-1));
    for(int i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        if(adjmat[a][b]==-1) adjmat[a][b]=0;
        if(adjmat[b][a]==-1) adjmat[b][a]=0;
        adjmat[a][b] +=c;
        sum+=c;
    }
    ll ans = 0;
    while(sum>0){
        vector<int>path;
        vector<int>vis(n+1,0);
        bool flow = dfs(1,n,adjmat,vis,path,sum);
        if(flow){
            reverse(path.begin(),path.end());
            int sizepath = path.size();
            ll minedgew = LLONG_MAX;
            for(ll i=0;i<sizepath-1;i++){
                minedgew = min(minedgew,adjmat[path[i]][path[i+1]]);
            }
            ans+=minedgew;
            for(ll i=0;i<sizepath-1;i++){
                adjmat[path[i]][path[i+1]] -= minedgew;
                adjmat[path[i+1]][path[i]] += minedgew;
            }
        }
        else{
            sum/=2;
        }
    }
    cout<<ans<<'\n';
    return 0;
}