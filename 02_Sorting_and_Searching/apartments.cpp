#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;
    vector<int>desire(n);
    vector<int>apartment(m);
    for(int i=0;i<n;i++) cin>>desire[i];
    for(int i=0;i<m;i++) cin>>apartment[i];
    sort(apartment.begin(),apartment.end());
    sort(desire.begin(),desire.end());
    int ans = 0;
    int people = 0;
    int space = 0;
    while(space<m){
        if(people>=n) break;
        if(desire[people]-k > apartment[space]) space++;
        else if(desire[people]+k < apartment[space]) people++;
        else{
            ans++;
            space++;
            people++;
        }
    }
    cout<<ans<<endl;
    return 0;
}