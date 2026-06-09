#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adjlist(n);
    vector<int>deg(n,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adjlist[a-1].push_back({b-1,i});
        adjlist[b-1].push_back({a-1,i});
        deg[a-1]++;
        deg[b-1]++;
    }
    for(int i=0;i<n;i++){
        if(deg[i] & 1){
            cout<<"IMPOSSIBLE"<<'\n';
            return 0;
        }
    }
    vector<int>used(m,0);
    vector<int>path;
    stack<int>st;
    st.push(0);
    while(!st.empty()){
        int node = st.top();
        while(!adjlist[node].empty() && used[adjlist[node].back().second]) adjlist[node].pop_back();
        if(adjlist[node].empty()){
            st.pop();
            path.push_back(node+1);
        }
        else{
            auto [v,ind] = adjlist[node].back();
            adjlist[node].pop_back();
            st.push(v);
            used[ind] = 1; 
        }
    }
    if((int)path.size()!=m+1){
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    reverse(path.begin(),path.end());
    for(auto it:path) cout<<it<<" ";
    return 0;
}