#include<bits/stdc++.h>
using namespace std;

using ll = long long;

class DSU{
    private:
        vector<int>size;
        vector<int>parent;
        int maxsize = 1;
        int componenets;
    public:
        DSU(int n){
            size.resize(n,1);
            parent.resize(n);
            componenets = n;
            for(int i=0;i<n;i++) parent[i] = i;
        }
        int findparent(int node){
            if(parent[node]==node) return node;
            parent[node] = findparent(parent[node]);
            return parent[node];
        }
        void uniongraph(int u,int v){
            int ultu = findparent(u);
            int ultv = findparent(v);
            if(ultu==ultv) return;
            if(size[ultu]>size[ultv]){
                size[ultu]+=size[ultv];
                parent[ultv] = ultu;
                maxsize = max(maxsize,size[ultu]);
            }
            else{
                size[ultv]+=size[ultu];
                parent[ultu] = ultv;
                maxsize = max(maxsize,size[ultv]);
            }
            componenets -= 1;
        }
        int getcomponents() {return componenets;}
        int getmaxsize() {return maxsize;}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        dsu.uniongraph(a,b);
        cout<<dsu.getcomponents()<<" "<<dsu.getmaxsize()<<"\n";
    }
    return 0;
}