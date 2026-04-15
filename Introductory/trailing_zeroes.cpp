#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long div = 5;
    long long count = 0;
    while((n/div)>0){
        count+= (n/div);
        div*=5;
    }
    cout<<count<<endl;
    return 0;
}