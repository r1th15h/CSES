#include<bits/stdc++.h>
using namespace std;

int main(){
    const int mod = 1000000000+7;
    int n;
    cin>>n;
    long long ans = 1;
    long long base = 2;
    long long x = n;
    while(x>0){
        if(x&1){
            ans = (ans*base)%mod;
        }
        x/=2;
        base = (base*base)%mod;
    }
    cout<<(ans%mod)<<endl;
    return 0;
}