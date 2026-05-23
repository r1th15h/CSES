    #include<bits/stdc++.h>
    using namespace std;

    using ll = long long;

    bool comp(vector<int>a,vector<int>b){
        if(a[0]==b[0] && a[1]==b[1]) return a[2]>b[2];
        else if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }

    ll getMaxReward(int n,vector<vector<int>>&days,int ind,vector<ll>&dp,vector<int>&start){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        ll p = 0;
        ll np = getMaxReward(n,days,ind+1,dp,start);
        int nexind = upper_bound(start.begin(),start.end(),days[ind][1])-start.begin();
        p = days[ind][2] + getMaxReward(n,days,nexind,dp,start);
        return dp[ind] = max(p,np);
    }

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin>>n;
        vector<vector<int>>days(n);
        vector<int>start(n);
        for(int i=0;i<n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            days[i] = {a,b,c};
        }
        sort(days.begin(),days.end(),comp);
        for(int i=0;i<n;i++) start[i] = days[i][0];
        vector<ll>dp(n,-1);
        cout<<getMaxReward(n,days,0,dp,start)<<endl;
        return 0;
    }