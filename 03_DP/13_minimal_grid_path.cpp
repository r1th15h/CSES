#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    string ans = "";
    ans+=grid[0][0];
    vector<pair<int,int>>current;
    current.push_back({0,0});
    vector<vector<int>>seen(n,vector<int>(n,-1));
    for(int i=1;i<(2*n-1);i++){
        char best = 'Z';
        for(auto [r,c]:current){
            if(r+1<n) best = min(best,grid[r+1][c]);
            if(c+1<n) best = min(best,grid[r][c+1]);
        }
        vector<pair<int,int>>next;
        for(auto [r,c]:current){
            if(r+1<n && grid[r+1][c]==best){
                if(seen[r+1][c]!=i){
                    seen[r+1][c] = i;
                    next.push_back({r+1,c});
                }
            }
            if(c+1<n && grid[r][c+1]==best) {
                if(seen[r][c+1]!=i){
                    seen[r][c+1] = i;
                    next.push_back({r,c+1});
                }
            }
        }
        ans+=best;
        current = next;
    }
    cout<<ans<<endl;
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;
// struct Node{
//     char c;
//     int chilrank;
//     int x;
//     int y;
// };
// bool comp(Node a,Node b){
//     if(a.c==b.c) return a.chilrank<b.chilrank;
//     return a.c<b.c;
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin>>n;
//     vector<string>grid(n);
//     for(int i=0;i<n;i++) cin>>grid[i];
//     vector<vector<int>>ord(n,vector<int>(n));
//     ord[n-1][n-1]=0;
//     for(int d=(2*n)-3;d>=0;d--){
//         vector<Node>level;
//         for(int i=0;i<n;i++){
//             int j = d-i;
//             if(j<0 || j>=n) continue;
//             int bestchildrank;
//             if(i==n-1) bestchildrank = ord[i][j+1];
//             else if(j==n-1) bestchildrank = ord[i+1][j];
//             else bestchildrank = min(ord[i+1][j],ord[i][j+1]);
//             Node curr;
//             curr.c = grid[i][j];
//             curr.chilrank = bestchildrank;
//             curr.x = i;
//             curr.y = j;
//             level.push_back(curr);
//         }
//         sort(level.begin(),level.end(),comp);
//         int rank = 0;
//         for(int i=0;i<(int)level.size();i++){
//             if(i>0){
//                 int diff = (level[i].c != level[i-1].c || level[i].chilrank!=level[i-1].chilrank);
//                 if(diff) rank++;
//             }
//             ord[level[i].x][level[i].y] = rank;
//         }
//     }
//     string ans = "";
//     int x = 0;
//     int y = 0;
//     while(true){
//         ans+=grid[x][y];
//         if(x==n-1 && y==n-1) break;
//         else if(x==n-1) y++;
//         else if(y==n-1) x++;
//         else{
//             if(ord[x+1][y]<ord[x][y+1]) x++;
//             else y++;
//         }
//     }
//     cout<<ans<<'\n';
//     return 0;
// }