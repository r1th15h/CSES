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
    vector<vector<int>>tasks(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        tasks[i] = {a,b};
    }
    sort(tasks.begin(),tasks.end(),comp);
    ll ans = 0;
    ll time = 0;
    for(auto it:tasks){
        time+=it[0];
        ans+= it[1]-time;
    }
    cout<<ans<<endl;
    return 0;
}