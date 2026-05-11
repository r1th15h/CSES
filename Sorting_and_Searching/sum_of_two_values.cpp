#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        int elem;
        cin>>elem;
        int target = x-elem;
        if(mpp.find(target)!=mpp.end()){
            cout<<mpp[target]<<" "<<i+1<<endl;
            return 0;
        } 
        mpp[elem] = i+1;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}