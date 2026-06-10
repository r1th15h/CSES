#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    if(a+b>n){
        cout<<"NO"<<endl;
        return;
    }
    if((a==0 || b==0) && a+b!=0){
        cout<<"NO"<<endl;
        return;
    }
    if(a==0 && b==0){
        cout<<"YES"<<endl;
        for(int k=0;k<=1;k++){
            for(int i=1;i<=n;i++){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++) cout<<i<<" ";
    cout<<endl;
    for(int i=a+1;i<=a+b;i++) cout<<i<<" ";
    for(int i=1;i<=a;i++) cout<<i<<" ";
    for(int i=a+b+1;i<=n;i++) cout<<i<<" ";
    cout<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++) solve();
    return 0;
}