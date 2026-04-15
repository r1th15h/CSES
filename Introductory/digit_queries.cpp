#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin>>q;
    for(int t=0;t<q;t++){
        long long k;
        cin>>k;
        long long digrange = 9;
        long long totbits = 9;
        long long prevrange = 0;
        int digc = 1;
        while(digc<19){
            if(k<=totbits){
                long long currsetbits = k-prevrange-1;
                long long start = pow(10,digc-1);
                long long num = start+(currsetbits/digc);
                long long reqdig = currsetbits%digc;
                string nums = to_string(num);
                cout<<nums[reqdig]<<endl;
                break;
            }
            else{
                prevrange = totbits;
                digrange*=10;
                digc++;
                totbits += digrange*digc;
            }
        }
    }
    return 0;
}