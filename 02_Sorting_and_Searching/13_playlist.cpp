#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>songs(n);
    for(int i=0;i<n;i++) cin>>songs[i];
    int l=0;
    int ans = 0;
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        if(mpp.find(songs[i])!=mpp.end() && mpp[songs[i]]>=l){
            l = mpp[songs[i]]+1;
        }
        mpp[songs[i]] = i;
        ans = max(ans,i-l+1);
    }
    cout<<ans<<endl;
    return 0;
}