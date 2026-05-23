    #include<bits/stdc++.h>
    using namespace std;

    using ll = long long;

    int getLIS(vector<int>&nums,int n,int ind,int prev,vector<vector<int>>&dp){
        if(ind>=n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int p = 0;
        int np = getLIS(nums,n,ind+1,prev,dp);
        if(prev==-1 || nums[prev]<nums[ind]) p = 1+getLIS(nums,n,ind+1,ind,dp);
        return dp[ind][prev+1] = max(p,np);
    }

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        vector<int>temp;
        temp.push_back(nums[0]);
        int ans = 1;
        // int maxi = 1;
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // cout<<getLIS(nums,n,0,-1,dp)<<endl;
        // for(int ind=n-1;ind>=0;ind--){
        //     for(int prev=ind-1;prev>=-1;prev--){
        //         int p = 0;
        //         int np = dp[ind+1][prev+1];
        //         if(prev==-1 || nums[prev]<nums[ind]) p = 1+dp[ind+1][ind+1];
        //         dp[ind][prev+1] = max(p,np);
        //     }
        // }
        // cout<<dp[0][0]<<endl;
        // vector<int>dp(n,1);
        // for(int i=1;i<n;i++){
        //     for(int prev=0;prev<i;prev++){
        //         if(nums[prev]<nums[i]){
        //             dp[i] = max(dp[i],1+dp[prev]);
        //         }
        //     }
        //     maxi = max(maxi,dp[i]);
        // }
        // cout<<maxi<<endl;
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                ans++;
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind] = nums[i];
            }
        }
        cout<<ans<<endl;
        return 0;
    }