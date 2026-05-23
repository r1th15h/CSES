#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v1;
    vector<int>v2;
    long long sum = (n*(n+1))/2;
    if(sum&1){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    int l=1;
    int r=n;
    if(n&1){
        v2.push_back(r);
        r--;
    }
    bool alternate = true;
    for(int i=0;i<n/2;i++){
        if(alternate){
            v1.push_back(l);
            v1.push_back(r);
        }
        else{
            v2.push_back(l);
            v2.push_back(r);
        }        
        alternate = !alternate;
        r--;
        l++;
    }
    cout<<v1.size()<<endl;
    for(auto it:v1) cout<<it<<" ";
    cout<<endl;
    cout<<v2.size()<<endl;
    for(auto it:v2) cout<<it<<" ";
    cout<<endl;
    return 0;
}