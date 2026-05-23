#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool comp(pair<int,int>a,pair<int,int>b){
    return a.first<b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int,int>>times;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        times.push_back({a,1});
        times.push_back({b,-1});
    }
    sort(times.begin(),times.end(),comp);
    int maxc = 0;
    int c = 0;
    for(auto it:times){
        c+=it.second;
        maxc = max(maxc,c);
    }
    cout<<maxc<<endl;
    return 0;
}