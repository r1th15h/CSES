#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    int ind = 0;
    ordered_set<int>s;
    for(int i=1;i<=n;i++) s.insert(i);
    while(!s.empty()){
        int newn = s.size();
        ind = (ind+k)%newn;
        auto val = s.find_by_order(ind);
        cout<<*val<<" ";
        s.erase(val);
    }
    return 0;
}