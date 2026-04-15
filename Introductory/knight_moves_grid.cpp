#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>moves = {
        {-1,2},
        {-1,-2},
        {1,2},
        {1,-2},
        {-2,-1},
        {-2,1},
        {2,-1},
        {2,1},
    };
    queue<vector<int>>pq;
    vector<vector<int>>dist(n,vector<int>(n,-1));
    dist[0][0] = 0;
    for(auto it:moves){
        int r = it[0];
        int c = it[1];
        if(r>=0 && c>=0 && r<n && c<n){
            dist[r][c] = 1;
            pq.push({1,r,c});
        }
    }
    while(!pq.empty()){
        auto curr = pq.front();
        pq.pop();
        int val = curr[0];
        int r = curr[1];
        int c = curr[2];
        for(auto it:moves){
            int nr = r+it[0];
            int nc = c+it[1];
            if(nr>=0 && nc>=0 && nr<n && nc<n && (dist[nr][nc]==-1 || dist[nr][nc]>1+val)){
                dist[nr][nc] = 1+val;
                pq.push({1+val,nr,nc});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}