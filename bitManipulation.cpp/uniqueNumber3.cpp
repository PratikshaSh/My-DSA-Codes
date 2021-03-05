#include<iostream>
#include<cmath>
using namespace std;

//all no.s are occuring thrice except 1
//7
//1 1 1 2 2 2 3
// ans = 3
int main(){
    int n;
    cin>>n;
    int no;

    //Array of fixed size - O(1) space
    int bSum[64] = {0};
    
    for(int i=0; i<n; i++){
        cin>>no;
        int j =0;
        while(no>0){
            
            int last_bit = (no&1);
            bSum[j] += last_bit;
            j++;
            no = no>>1;

        }
    }
    int ans = 0;
    int p = 1;
    for(int i=0; i<64; i++){
        bSum[i] = bSum[i]%3;
        ans += (bSum[i]*p);
        p = p<<1;
    }
    cout<<ans ;


    return 0;
}