#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    if(s.size()==0){
        cout<<0<<endl;
        return 0;
    }
    char prev=s[0];
    int maxi = 1;
    int tempc = 1;
    for(int i=1;i<n;i++){
        if(s[i]==prev){
            tempc++;
            maxi = max(maxi,tempc);
        }
        else{
            tempc = 1;
            prev = s[i];
        }
    }
    cout<<maxi<<endl;
    return 0;
}