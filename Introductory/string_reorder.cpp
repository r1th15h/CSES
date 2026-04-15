#include<bits/stdc++.h>
using namespace std;

bool ispossible(vector<int>&hash,int rem){
    int mode = 0;
    for(int i=0;i<26;i++){
        if(hash[i]>mode){
            mode = hash[i];
        }
    }
    return (mode<=((rem+1)/2));
}

int main(){
    string s;
    cin>>s;
    int n = s.size();
    string ans = "";
    char last = '#';
    vector<int>hash(26,0);
    for(auto it:s){
        hash[it-'A']++;
    }
    for(int i=0;i<n;i++){
        bool place = false;
        for(int ch='A';ch<='Z';ch++){
            if(last==ch || hash[ch-'A']==0) continue;
            hash[ch-'A']--;
            if(ispossible(hash,n-i-1)){
                place = true;
                ans.push_back(ch);
                last = ch;
                break;
            }
            hash[ch-'A']++;
        }
        if(!place){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}