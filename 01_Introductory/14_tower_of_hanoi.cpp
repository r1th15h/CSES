#include<bits/stdc++.h>
using namespace std;

void solve(int n,int src,int helper,int dest,vector<vector<int>>&ans){
    if(n==1){
        ans.push_back({src,dest});
        return;
    }
    solve(n-1,src,dest,helper,ans);
    ans.push_back({src,dest});
    solve(n-1,helper,src,dest,ans);
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>ans;
    solve(n,1,2,3,ans);
    cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    return 0;
}