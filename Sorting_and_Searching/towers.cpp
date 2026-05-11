#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>cubes(n);
    multiset<int>s;
    for(int i=0;i<n;i++){
        cin>>cubes[i];
    }
    for(auto it:cubes){
        auto ans = s.upper_bound(it);
        if(ans!=s.end()) s.erase(ans);
        s.insert(it);
    }
    cout<<s.size()<<endl;
    return 0;
}