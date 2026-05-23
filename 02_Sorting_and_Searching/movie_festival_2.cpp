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

    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>times(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        times[i] = {a,b};
    }
    int c = 1;
    sort(times.begin(),times.end(),comp);
    multiset<int>s;
    s.insert(times[0].second);
    k--;
    for(int i=1;i<n;i++){
        auto lb = s.upper_bound(times[i].first);
        if(lb!=s.begin()){
            auto endval = --lb;
            s.erase(endval);
            s.insert(times[i].second);
            c++;
        }
        else{
            if(k>0){
                s.insert(times[i].second);
                k--;
                c++;
            }
        }
    }
    cout<<c<<endl;
    return 0;
}