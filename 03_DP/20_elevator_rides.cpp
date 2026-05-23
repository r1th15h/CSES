#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<int>weights(n);
    for(int i=0;i<n;i++) cin>>weights[i];
    vector<pair<int,int>>dp(1<<n,{n+1,0});
    dp[0] = {1,0};
    for(int mask=1;mask<(1<<n);mask++){
        for(int j=0;j<n;j++){
            int prevmask = mask ^ (1<<j);
            auto [ride,lastweight] = dp[prevmask];
            if(lastweight+weights[j]<=x) lastweight+=weights[j];
            else{
                ride++;
                lastweight = weights[j];
            }
            dp[mask] = min(dp[mask],{ride,lastweight});
        }
    }
    cout<<dp[(1<<n)-1].first<<endl;
    return 0;
}