#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_multiset = tree<
    pair<T,int>,
    null_type,
    less<pair<T,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

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
    ordered_multiset<int>s;
    for(int i=0;i<n;i++){
        int r = ranges[i][1];
        int n = s.size();
        int lb = s.order_of_key({r, -1});
        other[ranges[i][2]] = n-lb;
        s.insert({r, i});
    }
    s.clear();
    for(int i=n-1;i>=0;i--){
        int r = ranges[i][1];
        int ub = s.order_of_key({r, INT_MAX});
        mine[ranges[i][2]] = ub;
        s.insert({r, i});
    }
    for(auto it:mine) cout<<it<<" ";
    cout<<endl;
    for(auto it:other) cout<<it<<" ";
    return 0;
}