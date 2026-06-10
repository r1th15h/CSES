#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

void generatemasks(int mask,int i,int nextmask,int n,vector<int>&nextmasks){
    if(i==n){
        nextmasks.push_back(nextmask);
        return;
    }
    if((mask & (1<<i))!=0) generatemasks(mask,i+1,nextmask,n,nextmasks);
    if(i!=n-1){
        if((mask&(1<<i))==0 && (mask&(1<<(i+1)))==0){
            generatemasks(mask,i+2,nextmask,n,nextmasks);
        }
    }
    if((mask&(1<<i))==0){
        generatemasks(mask,i+1,nextmask+(1<<i),n,nextmasks);
    }
}

int getans(int col,int mask,vector<vector<int>>&dp,int n,int m){
    if(col==m){
        if(mask==0) return 1;
        return 0;
    }
    if(dp[col][mask]!=-1) return dp[col][mask];
    int ans = 0;    
    vector<int>nextmasks;
    generatemasks(mask,0,0,n,nextmasks);
    for(auto newmask:nextmasks){
        ans = (ans+getans(col+1,newmask,dp,n,m))%MOD;
    }
    return dp[col][mask] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>dp(m,vector<int>((1<<n),-1));
    cout<<getans(0,0,dp,n,m)<<'\n';
    return 0;
}