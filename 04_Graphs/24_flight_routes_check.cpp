#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int node,vector<vector<int>>&adjlsit,vector<int>&vis,stack<int>&st){
    vis[node] = 1;
    for(auto it:adjlsit[node]){
        if(!vis[it]) dfs(it,adjlsit,vis,st);
    }
    st.push(node);
}

void dfsnew(int node,vector<vector<int>>&adjlsit,vector<int>&vis){
    vis[node] = 1;
    for(auto it:adjlsit[node]){
        if(!vis[it]) dfsnew(it,adjlsit,vis);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>adjlist(n);
    vector<vector<int>>revadjlist(n);
    vector<int>vis(n,0);
    vector<int>visnew(n,0);
    stack<int>st;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adjlist[a-1].push_back(b-1);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(i,adjlist,vis,st);
    }
    for(int i=0;i<n;i++){
        for(auto it:adjlist[i]){
            revadjlist[it].push_back(i);
        }
    }
    int first = -1;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visnew[node]){
            if(first==-1){
                first = node;
                dfsnew(node,revadjlist,visnew);
            }
            else{
                cout<<"NO"<<'\n';
                cout<<node+1<<" "<<first+1<<"\n";
                return 0;
            }
        }
    }
    cout<<"YES"<<'\n';
    return 0;
}