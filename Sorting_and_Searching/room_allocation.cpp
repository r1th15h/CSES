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
    vector<vector<int>>times(n);
    vector<vector<int>>orders;
    vector<int>answers(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        times[i] = {a,b};
        orders.push_back({a,1,i});
        orders.push_back({b,-1,i});
    }
    ll c=0;
    ll maxc=0;
    set<int>s;
    ll prev = 0;
    sort(orders.begin(),orders.end(),comp);
    for(auto it:orders){
        if(it[1]==1){
            if(s.size()==0){
                answers[it[2]] = (prev+1);
                prev++;
            }
            else{
                answers[it[2]] = (*(s.begin()));
                s.erase(s.begin());
            }
        }
        else{
            s.insert(answers[it[2]]);
        }
        c+=it[1];
        maxc = max(maxc,c);
    }
    cout<<maxc<<endl;
    for(auto it:answers) cout<<it<<" ";
    return 0;
}