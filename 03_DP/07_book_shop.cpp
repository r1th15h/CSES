#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int getMaxPages(vector<int>&price,vector<int>&page,int n,int x,int ind,vector<vector<int>>&dp){
    if(ind<0) return 0;
    if(dp[ind][x]!=-1) return dp[ind][x];
    int pick = 0;
    if(price[ind]<=x) pick = page[ind]+getMaxPages(price,page,n,x-price[ind],ind-1,dp);
    int notpick = getMaxPages(price,page,n,x,ind-1,dp); 
    return dp[ind][x] = max(pick,notpick);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<int>price(n);
    vector<int>page(n);
    for(int i=0;i<n;i++) cin>>price[i];
    for(int i=0;i<n;i++) cin>>page[i];
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    for(int ind=1;ind<=n;ind++){
        for(int cost=0;cost<=x;cost++){
            int pick = 0;
            if(price[ind-1]<=cost) pick = page[ind-1]+dp[ind-1][cost-price[ind-1]];
            int notpick = dp[ind-1][cost]; 
            dp[ind][cost] = max(pick,notpick);
        }
    }
    cout<<dp[n][x]<<endl;
    return 0;
}