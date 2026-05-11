#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    multiset<int>s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        auto possible = s.upper_bound(x);
        if(possible==s.begin()) cout<<-1<<endl;
        else{
            --possible;
            cout<<*possible<<endl;
            s.erase(possible);
        }
    }
    return 0;
}