#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long sum=0;
    for(int i=0;i<n-1;i++){
        long long temp;
        cin>>temp;
        sum+=temp;
    }
    long long need = (n*(n+1))/2;
    cout<<need-sum<<endl;
    return 0;
}