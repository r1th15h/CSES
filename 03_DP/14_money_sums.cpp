#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>coins(n);
    int c = 0;
    for(int i=0;i<n;i++){
        cin>>coins[i];
        c+=coins[i];
    }
    vector<bool>dp(c+1,false);
    dp[0] = true;
    for(auto it:coins){
        for(int i=c;i>=it;i--){
            if(dp[i-it]) dp[i] = true;
        }
    }
    vector<int>ans;
    int count = 0;
    for(int i=1;i<=c;i++){
        if(dp[i]){
            count++;
            ans.push_back(i);
        }
    }
    cout<<count<<endl;
    for(auto it:ans) cout<<it<<" ";
    return 0;
}