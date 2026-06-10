#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();
    unordered_map<char,int>mpp;
    int oddc = 0;
    int l=0,r=n-1;
    for(auto it:s){
        mpp[it]++;
    }
    for(auto it:mpp){
        if(it.second%2!=0) oddc++;
    }
    if(oddc>1){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    else{
        for(auto it:mpp){
            char val = it.first;
            int count = it.second;
            if(count%2!=0){
                s[n/2] = it.first;
                count--;
            }
            while(count>0){
                s[l] = val;
                s[r] = val;
                count-=2;
                l++;
                r--;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}