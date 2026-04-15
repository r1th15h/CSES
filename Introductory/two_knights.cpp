#include<bits/stdc++.h>
using namespace std;

void solve(int n){
    long long blocks = n*n;
    long long total = (blocks*(blocks-1))/2;
    if(n<=1){
        cout<<0<<endl;
        return;
    }
    int h = n-1;
    int w = n-2;
    long long ans = total-(4*w*h);
    cout<<ans<<endl;
    return;    
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) solve(i);
    return 0;
}