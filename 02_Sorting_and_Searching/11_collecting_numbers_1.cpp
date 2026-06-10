#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>nums(n+1);
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        nums[val] = i+1;
    }
    int c = 1;
    for(int i=2;i<=n;i++){
        if(nums[i]<nums[i-1]) c++;
    }
    cout<<c<<endl;
    return 0;
}