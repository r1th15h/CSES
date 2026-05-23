#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool comp(vector<int>a,vector<int>b){
    if(a[0]==b[0]) return a[1]>b[1];
    return a[0]<b[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>>ranges;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        ranges.push_back({a,b,i});
    }
    vector<int>mine(n,0);
    vector<int>other(n,0);

    sort(ranges.begin(),ranges.end(),comp);
    int maxiright = INT_MIN;
    int miniright = INT_MAX;
    for(int i=0;i<n;i++){
        int r = ranges[i][1];
        if(r<=maxiright) other[ranges[i][2]] = 1;
        maxiright = max(maxiright,r);
    }
    for(int i=n-1;i>=0;i--){
        int r = ranges[i][1];
        if(r>=miniright) mine[ranges[i][2]] = 1;
        miniright = min(miniright,r);
    }
    for(auto it:mine) cout<<it<<" ";
    cout<<endl;
    for(auto it:other) cout<<it<<" ";
    return 0;
}