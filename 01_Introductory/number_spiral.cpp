#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x,y;
    cin>>y>>x;
    long long colval,rowval;
    if(x&1){
        colval = 1LL*x*x;  
    }
    else{
        colval = 1LL*(x-1)*(x-1);  
        colval++;
    }
    if(!(y&1)){
        rowval = 1LL*y*y;  
    }
    else{
        rowval = 1LL*(y-1)*(y-1);  
        rowval++;
    }
    if(x>y){
        if(x&1) colval-=(y-1);
        else colval+=(y-1);
        cout<<colval<<endl;
    }
    else{
        if(y&1) rowval+=(x-1);
        else rowval-=(x-1);
        cout<<rowval<<endl;
    }
    return;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++) solve();
    return 0;
}