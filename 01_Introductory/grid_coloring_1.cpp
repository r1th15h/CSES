#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    vector<char>choice = {'A','B','C','D'};
    vector<vector<int>>dir = {{0,-1},{-1,0}};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char curr = grid[i][j];
            bool yes = true;
            for(auto it1:choice){
                bool ok = true;
                for(auto it2:dir){
                    int r = i+it2[0];
                    int c = j+it2[1];
                    if(r>=0 && c>=0 && r<n && c<m){
                        if(grid[r][c]==it1){
                            ok = false;
                            break;
                        }
                    }
                }
                if(ok && curr!=it1){
                    yes = false;
                    grid[i][j] = it1;
                    break;
                }
            }
            if(yes){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    return 0;
}