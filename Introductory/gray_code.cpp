#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);i++){
        int prev = 0;
        string s = "";
        for(int j=n-1;j>=0;j--){
            int currbit = (i>>j)&1;
            int graybit = currbit^prev;
            s+= to_string(graybit);
            prev = currbit;
        }
        cout<<s<<endl;
    }
    return 0;
}