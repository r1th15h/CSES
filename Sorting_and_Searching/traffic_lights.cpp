#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x,n;
    cin>>x>>n;
    vector<int>lights(n);
    for(int i=0;i<n;i++) cin>>lights[i];
    multiset<int>segments;
    set<int>placements;
    placements.insert(0);
    placements.insert(x);
    segments.insert(x);
    for(auto it:lights){
        auto right = placements.lower_bound(it); 
        auto left = prev(right);
        int l = *left;
        int r = *right;
        int segmentlen = r-l;
        segments.erase(segments.find(segmentlen));
        segments.insert(it-l);
        segments.insert(r-it);
        placements.insert(it);
        cout<<*(--segments.end())<<endl;
    }
    return 0;
}