#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    if(n==1){
        cout<<10<<'\n';
        return 0;
    }
    unordered_map<string,vector<pair<string,char>>>adjlist;
    for(int mask=0;mask<(1<<(n-1));mask++){
        string currnum = "";
        for(int bit=(n-2);bit>=0;bit--){
            if(mask & (1<<bit)) currnum+='1';
            else currnum+='0';
        }
        adjlist[currnum].push_back({currnum.substr(1)+'0','0'});
        adjlist[currnum].push_back({currnum.substr(1)+'1','1'});
    }
    string init(n-1,'0');
    string ans = "";
    stack<pair<string,char>>st;
    st.push({init,'#'});
    while(!st.empty()){
        string curr = st.top().first;
        if(!adjlist[curr].empty()){
            st.push(adjlist[curr].back());
            adjlist[curr].pop_back();
        }
        else{
            auto [currstr,currchar] = st.top();
            st.pop();
            if(currchar!='#') ans+= currchar;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<init<<ans<<'\n';
    return 0;
}