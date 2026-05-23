#include<bits/stdc++.h>
using namespace std;

void dfs(int ind,int row,int col,long long &ans,vector<int>&delrow,vector<int>&delcol,vector<char>&dir,vector<vector<int>>&vis,string &s){
    if(ind==48){
        if(row==6 && col==0) ans++;
        return;
    }
    if(row==6 && col==0) return;
    if(((row-1<0 || vis[row-1][col]) && (row+1>=7 || vis[row+1][col]) ) && (col-1>=0 && !vis[row][col-1] && col+1<7 && !vis[row][col+1])) return;
    if(((col-1<0 || vis[row][col-1]) && (col+1>=7 || vis[row][col+1]) ) && (row-1>=0 && !vis[row-1][col] && row+1<7 && !vis[row+1][col])) return;
    for(int i=0;i<4;i++){ 
        int r = row+delrow[i];
        int c = col+delcol[i];
        char direction = dir[i];
        if(r>=0 && c>=0 && c<7 && r<7 && vis[r][c]==0 && (s[ind]=='?' || s[ind]==direction)){
            vis[r][c] = 1;
            dfs(ind+1,r,c,ans,delrow,delcol,dir,vis,s);
            vis[r][c] = 0;
        }
    }
    return;
}   

int main(){
    string s;
    cin>>s;
    long long ans = 0;
    vector<int>delrow = {0,0,-1,1};
    vector<int>delcol = {1,-1,0,0};
    vector<char>dir = {'R','L','U','D'};
    vector<vector<int>>vis(7,vector<int>(7,0));
    vis[0][0] = 1;
    dfs(0,0,0,ans,delrow,delcol,dir,vis,s);
    cout<<ans<<endl;
    return 0;
}