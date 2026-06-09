#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int node,vector<int>&len,vector<int>&vis,vector<int>&nums,vector<int>&path,vector<int>&pos){
    vis[node] = 1;
    pos[node] = path.size();
    path.push_back(node);
    if(vis[nums[node]]==0){
        dfs(nums[node],len,vis,nums,path,pos);
    }
    else if(vis[nums[node]]==1){
        int cyclesize = path.size()-pos[nums[node]];
        for(int i=pos[nums[node]];i<(int)path.size();i++){
            len[path[i]] = cyclesize;
        }
    }
    if(len[node]==0){
        len[node] = len[nums[node]]+1;
    }
    vis[node] = 2;
    path.pop_back();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        nums[i] = a-1;
    }
    vector<int>len(n,0);
    vector<int>vis(n,0);
    vector<int>pos(n,-1);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vector<int>path;
            dfs(i,len,vis,nums,path,pos);
        }
    }
    for(auto it:len) cout<<it<<" ";
    return 0;
}