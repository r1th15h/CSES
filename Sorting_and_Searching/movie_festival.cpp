#include <bits/stdc++.h>
using namespace std;

using ll = long long;


bool comp(pair<int,int>a,pair<int,int>b){
    if(a.second==b.second) return a.first>b.first;
    return a.second<b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int,int>>times(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        times[i] = {a,b};
    }
    int c = 1;
    sort(times.begin(),times.end(),comp);
    int prev = times[0].second;
    for(int i=1;i<n;i++){
        if(times[i].first>=prev){
            c++;
            prev = times[i].second;
        }
    }
    cout<<c<<endl;
    return 0;
}