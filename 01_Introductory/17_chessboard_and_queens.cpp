#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<vector<char>>&board,int row,int col){
    int tempr = row;
    int tempc = col-1;
    while(tempc>=0){
        if(board[tempr][tempc]=='q') return false;
        tempc--;
    }    
    tempr = row-1;
    tempc = col-1;
    while(tempr>=0 && tempc>=0){
        if(board[tempr][tempc]=='q') return false;
        tempr--;
        tempc--;
    }

    tempr = row+1;
    tempc = col-1;
    while(tempr<8 && tempc>=0){
        if(board[tempr][tempc]=='q') return false;
        tempr++;
        tempc--;
    }
    return true;
}

int getcount(vector<vector<char>>&board,int col){
    if(col==8){
        return 1;
    }
    int count = 0;
    for(int i=0;i<8;i++){
        if(board[i][col]!='*' && board[i][col]!='q'){
            if(isPossible(board,i,col)){
                board[i][col] = 'q';
                count += getcount(board,col+1);
                board[i][col] = '.';
            }
        }
    }
    return count;
}

int main(){
    vector<vector<char>>board(8,vector<char>(8));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>board[i][j];
        }
    }
    int ans = getcount(board,0);
    cout<<ans<<endl;
    return 0;
}