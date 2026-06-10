#include<bits/stdc++.h>
using namespace std;

using ll = long long;

class SegmentTree{
    private:
        int n;
        vector<int>seg;
    public:
        SegmentTree(int n){
            seg.resize(4*n,0);
            this->n = n;
        }
        void update(int tl,int th,int segind,int pos,int val){  
            if(tl==th){
                seg[segind] = val;
                return;
            }
            int mid = tl+(th-tl)/2;
            if(pos<=mid) update(tl,mid,2*segind+1,pos,val);
            else update(mid+1,th,2*segind+2,pos,val);
            seg[segind] = max(seg[2*segind+1],seg[2*segind+2]);
        }
        int query(int tl,int th,int l,int h,int segind){
            if(th<l || tl>h) return 0;
            if(th<=h && tl>=l) return seg[segind];
            int mid = tl+(th-tl)/2;
            return max(query(tl,mid,l,h,2*segind+1),query(mid+1,th,l,h,2*segind+2));
        }
};

void getnge(vector<int>&nge,vector<int>&heights){
    stack<int>st;
    int n = heights.size();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && heights[st.top()]<heights[i]){
            st.pop();
        }
        if(st.empty()) nge[i] = n;
        else nge[i] = st.top();
        st.push(i);
    }
}
void getpge(vector<int>&pge,vector<int>&heights){
    stack<int>st;
    int n = heights.size();
    for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()]<heights[i]){
            st.pop();
        }
        if(st.empty()) pge[i] = -1;
        else pge[i] = st.top();
        st.push(i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>heights(n);
    vector<pair<int,int>>order;
    for(int i=0;i<n;i++){
        cin>>heights[i];
        order.push_back({heights[i],i});
    }
    vector<int>nge(n);
    vector<int>pge(n);
    getnge(nge,heights);
    getpge(pge,heights);
    sort(order.begin(),order.end());
    SegmentTree seg(n);
    vector<int>dp(n,1);
    int ans = 1;
    for(int i=0;i<n;i++){
        int j = i;
        while(j<n && order[i].first==order[j].first) j++;
        vector<pair<int,int>>pending;
        for(int k=i;k<j;k++){
            int ind = order[k].second;
            int best = seg.query(0,n-1,pge[ind]+1,nge[ind]-1,0);
            dp[ind] = best+1;
            pending.push_back({ind,dp[ind]});
            ans = max(ans,dp[ind]);
        }
        for(auto [ind,val]:pending){
            seg.update(0,n-1,0,ind,val);
        }
        i = j-1;
    }
    cout<<ans<<'\n';
    return 0;
}