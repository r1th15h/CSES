#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    set<long long>s;
    for(auto it:nums){
        s.insert(it);
    }
    cout<<s.size()<<endl;
    return 0;
}