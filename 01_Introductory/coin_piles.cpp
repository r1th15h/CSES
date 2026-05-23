#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,b;
    cin>>a>>b;
    if(a>2*b || b>2*a){
        cout<<"NO"<<endl;
    }
    else{
        if((a+b)%3==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++) solve();
    return 0;
}