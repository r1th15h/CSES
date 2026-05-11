#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,a,b;
    cin>>n>>a>>b;
    vector<ll>nums(n+1,0);
    for(int i=1;i<=n;i++) cin>>nums[i];
    vector<ll>pref(n+1,0);
    multiset<ll>s;
    ll maxi = LLONG_MIN;
    for(int i=1;i<=n;i++){
        pref[i] = pref[i-1] + nums[i];
        if(i<a) continue;
        s.insert(pref[i-a]);
        if(i>b) s.erase(s.find(pref[i-b-1]));
        ll ans = pref[i]-(*(s.begin()));
        maxi = max(maxi,ans);
    }
    cout<<maxi<<endl;
    return 0;
}