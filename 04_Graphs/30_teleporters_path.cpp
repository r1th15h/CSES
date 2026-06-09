#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<int>indeg(n,0);
    vector<int>outdeg(n,0);
    vector<vector<int>>adjlist(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adjlist[a-1].push_back(b-1);
        indeg[b-1]++;
        outdeg[a-1]++;
    }
    if((outdeg[0]-indeg[0]!=1) || (indeg[n-1]-outdeg[n-1]!=1)){
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    for(int i=1;i<n-1;i++){
        if(indeg[i]-outdeg[i]!=0){
            cout<<"IMPOSSIBLE"<<'\n';
            return 0;
        }
    }
    stack<int>st;
    st.push(0);
    vector<int>path;
    while(!st.empty()){
        int curr = st.top();
        if(!adjlist[curr].empty()){
            st.push(adjlist[curr].back());
            adjlist[curr].pop_back();
        }
        else{
            path.push_back(curr+1);
            st.pop();
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