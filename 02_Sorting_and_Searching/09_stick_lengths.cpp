#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>sticks(n);
    for(int i=0;i<n;i++) cin>>sticks[i];
    sort(sticks.begin(),sticks.end());
    int median = sticks[n/2];
    long long ans = 0;
    for(auto it:sticks){
        ans+=abs(it-median);
    }
    cout<<ans;
    return 0;
}