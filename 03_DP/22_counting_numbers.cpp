#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[20][10][2][2];

ll getans(string num,int n,int last,bool leadzero,bool tight){
    if(n==0) return 1;
    if(dp[n][last][leadzero][tight]!=-1) return dp[n][last][leadzero][tight]; 
    int lb = 0;
    int tightdig = num[num.size()-n]-'0';
    int ub = tight ? tightdig: 9;
    ll ans = 0;
    for(int dig=lb;dig<=ub;dig++){
        if(!leadzero && dig==last) continue;
        ans += getans(num,n-1,dig,(leadzero && (dig==0)),(tight && dig==tightdig));
    }
    return dp[n][last][leadzero][tight] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll a,b;
    cin>>a>>b;
    string n1 = to_string(b);
    string n2 = to_string(a-1);
    memset(dp,-1,sizeof dp);
    ll ans1 = getans(n1,n1.size(),-1,1,1);
    memset(dp,-1,sizeof dp);
    ll ans2 = getans(n2,n2.size(),-1,1,1);
    cout<<ans1-ans2<<'\n';
    
    return 0;
}