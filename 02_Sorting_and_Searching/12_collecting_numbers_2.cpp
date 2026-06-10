#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,c;
    cin>>n>>m;
    vector<int>nums(n+1);
    vector<int>items(n+1);
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        nums[val] = i+1;
        items[i+1] = val;
    }
    c = 1;
    for(int i=2;i<=n;i++){
        if(nums[i]<nums[i-1]) c++;
    }
    for(int k=0;k<m;k++){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        int x = items[a];
        int y = items[b];
        if(nums[x+1]>a && nums[x+1]<b) c++;
        if(nums[x-1]>a && nums[x-1]<b) c--;
        if(nums[y+1]>a && nums[y+1]<b) c--;
        if(nums[y-1]>a && nums[y-1]<b) c++;
        if(x==(y+1)) c--;
        if(x==(y-1)) c++;
        cout<<c<<endl;
        swap(items[a],items[b]);
        swap(nums[x],nums[y]);
    }
    return 0;
}