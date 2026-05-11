#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>times(n);
    ll timen=0;
    ll sum = 0;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        sum+=a;
        timen = max(timen,a);
    }
    cout<<max(2*timen,sum)<<endl;
    return 0;
}