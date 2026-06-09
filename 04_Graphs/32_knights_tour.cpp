#include<bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int>delrow = {1,1,-1,-1,2,2,-2,-2};
vector<int>delcol = {2,-2,2,-2,1,-1,1,-1};
vector<vector<int>>board(8,vector<int>(8,0));

bool isvalid(int a,int b){
    return (a>=0 && b>=0 && a<8 && b<8 && board[a][b]==0);
}

int getdegree(int r,int c){
    int count = 0;
    for(int i=0;i<8;i++){
        int newr = r+delrow[i];
        int newc = c+delcol[i];
        if(isvalid(newr,newc)) count++;
    }
    return count;
}

bool dfs(int r,int c,int moveno){
    board[r][c] = moveno;
    if(moveno==64) return true;
    vector<vector<int>>dfsorder;
    for(int i=0;i<8;i++){
        int newr = r+delrow[i];
        int newc = c+delcol[i];
        if(isvalid(newr,newc)) dfsorder.push_back({getdegree(newr,newc),newr,newc});
    }
    sort(dfsorder.begin(),dfsorder.end());
    for(auto &it:dfsorder){
        int newr = it[1];
        int newc = it[2];
        if(dfs(newr,newc,moveno+1)) return true;
    }
    board[r][c] = 0;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x,y;
    cin>>x>>y;
    x--;
    y--;
    dfs(y,x,1);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}