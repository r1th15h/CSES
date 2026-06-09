#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs1(int node,vector<vector<int>>&adjlsit,vector<int>&vis,stack<int>&st){
    vis[node] = 1;
    for(auto it:adjlsit[node]){
        if(!vis[it]) dfs1(it,adjlsit,vis,st);
    }
    st.push(node);
}

void dfs2(int node,vector<vector<int>>&adjlsit,vector<int>&vis,vector<int>&scc,int compno){
    vis[node] = 1;
    scc[node] = compno;
    for(auto it:adjlsit[node]){
        if(!vis[it]) dfs2(it,adjlsit,vis,scc,compno);
    }
}

int negateval(int x,int m){
    return 2*m-x+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    int N = 2*m;
    vector<vector<int>>adjlist(N+1);
    vector<vector<int>>revadjlist(N+1);
    vector<int>vis1(N+1,0);
    vector<int>vis2(N+1,0);
    vector<int>scc(N+1);
    stack<int>st;
    int compno = 0;
    for(int i=0;i<n;i++){
        char s1,s2;
        int x1,x2;
        cin>>s1>>x1>>s2>>x2;
        int n1,n2;
        if(s1=='-') n1 = negateval(x1,m);
        else n1 = x1;
        if(s2=='-') n2 = negateval(x2,m);
        else n2 = x2;
        adjlist[negateval(n1,m)].push_back(n2);
        adjlist[negateval(n2,m)].push_back(n1);
        revadjlist[n2].push_back(negateval(n1,m));
        revadjlist[n1].push_back(negateval(n2,m));
    }
    for(int i=1;i<=N;i++){
        if(!vis1[i]) dfs1(i,adjlist,vis1,st);
    }
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        if(!vis2[curr]){
            compno++;
            dfs2(curr,revadjlist,vis2,scc,compno);
        }
    }
    vector<char>ans(m+1);
    for(int i=1;i<=m;i++){
        if(scc[i]==scc[negateval(i,m)]){
            cout<<"IMPOSSIBLE"<<'\n';
            return 0;
        }
        ans[i] = scc[i]>scc[negateval(i,m)] ? '+' : '-';
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
    return 0;
}