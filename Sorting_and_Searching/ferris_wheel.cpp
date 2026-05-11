#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<int>weight(n);
    for(int i=0;i<n;i++) cin>>weight[i];
    sort(weight.begin(),weight.end());
    int ans = 0;
    int l=0;
    int r = n-1;
    while(l<=r){
        if(weight[l]+weight[r]<=x){
            l++;
            r--;
        }
        else r--;
        ans+=1;
    }
    cout<<ans<<endl;
    return 0;
}