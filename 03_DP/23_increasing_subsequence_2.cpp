#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9+7;

class Fenwick{
    private:
        int n;
        vector<ll>bit;
    public:
        Fenwick(int n){
            this->n = n;
            bit.resize(n+1,0);
        }
        void update(ll val,int ind){
            while(ind<=n){
                bit[ind] = (bit[ind]+val)%MOD;
                ind += (ind & -ind);
            }
        }
        ll query(int ind){
            ll sum = 0;
            while(ind>0){
                sum+=bit[ind];
                ind-= (ind & -ind);
            }
            return sum;
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vector<int>vals = nums;
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    Fenwick ft(vals.size());
    ll ans = 0;
    for(auto elem:nums){
        int rank = lower_bound(vals.begin(),vals.end(),elem)-vals.begin()+1;
        ll dp = (1+ft.query(rank-1))%MOD;
        ft.update(dp,rank);
        ans = (ans+dp)%MOD;
    }
    cout<<ans<<'\n';
    return 0;
}