    #include <bits/stdc++.h>
    using namespace std;

    using ll = long long;

    int getMax(vector<int>&nums,int start,int end,int turn,vector<vector<vector<int>>>&dp){
        if(start>end) return 0;
        if(dp[start][end][turn]!=-1) return dp[start][end][turn];
        int pickf=0,pickl=0;
        if(turn==0){
            pickf = nums[start]+getMax(nums,start+1,end,1,dp);
            pickl = nums[end]+getMax(nums,start,end-1,1,dp);

        }
        if(turn==1){
            pickf = getMax(nums,start+1,end,0,dp);
            pickl = getMax(nums,start,end-1,0,dp);
        }
        if(turn==0) return dp[start][end][turn] = max(pickf,pickl);
        return dp[start][end][turn] = min(pickf,pickl);
    }

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        // cout<<getMax(nums,0,n-1,0,dp)<<endl;
        vector<vector<ll>>dp(n,vector<ll>(n,0));
        for(int i=0;i<n;i++) dp[i][i] = nums[i];
        for(int len=2;len<=n;len++){
            for(int l=0;l+len-1<n;l++){
                int r = l+len-1;
                ll pickleft = nums[l]-dp[l+1][r];
                ll pickright = nums[r]-dp[l][r-1];
                dp[l][r] = max(pickleft,pickright);
            }
        }
        ll total = accumulate(nums.begin(),nums.end(),0LL);
        ll diff = dp[0][n-1];
        ll ans = (total+diff)/2;
        cout<<ans<<endl;
        return 0;
    }