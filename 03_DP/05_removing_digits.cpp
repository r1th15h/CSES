#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int minidig=INT_MIN;
        int temp = i;
        while(temp>0){
            int dig = temp%10;
            minidig = max(minidig,dig);
            temp/=10;
        }
        dp[i] = 1+dp[i-minidig];
    }
    cout<<dp[n]<<endl;
    return 0;
}