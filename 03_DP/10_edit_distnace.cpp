#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int recursivesolve(string &s1,string &s2,int n1,int n2){
    if(n1<0 && n2>=0) return n2+1;
    if(n2<0 && n1>=0) return n1+1;
    if(s1[n1]==s2[n2]) return recursivesolve(s1,s2,n1-1,n2-1);
    else{
        return 1+min({recursivesolve(s1,s2,n1-1,n2-1),recursivesolve(s1,s2,n1,n2-1),recursivesolve(s1,s2,n1-1,n2)});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++) dp[i][0] = i;
    for(int i=1;i<=m;i++) dp[0][i] = i;
    for(int n1=1;n1<=n;n1++){
        for(int n2=1;n2<=m;n2++){
            if(s1[n1-1]==s2[n2-1]) dp[n1][n2] = dp[n1-1][n2-1];
            else dp[n1][n2] = 1+min({dp[n1-1][n2-1],dp[n1-1][n2],dp[n1][n2-1]});
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}