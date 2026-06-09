#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<pair<ll,ll>>>adjlist(n);
    vector<vector<ll>>dist(n,vector<ll>(n,1e18));
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjlist[a-1].push_back({b-1,c});
        adjlist[b-1].push_back({a-1,c});
        dist[a-1][b-1] = min(dist[a-1][b-1],(ll)c);
        dist[b-1][a-1] = min(dist[b-1][a-1],(ll)c);
    }
    for(int i=0;i<n;i++) dist[i][i] = 0;
    for(int via=0;via<n;via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = min(dist[i][j],dist[i][via]+dist[via][j]);
            }
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(dist[a-1][b-1]==1e18) cout<<-1<<endl;
        else cout<<dist[a-1][b-1]<<endl;
    }
    return 0;
}