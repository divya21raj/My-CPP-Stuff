#include<iostream>
using namespace std;
#define ll long long int 

ll divisible(ll n){
    ll ans;
    
    return ans;
}

int main() {
    int t;
    ll n, ans;
    
    int primes[] = {2,3,5};
    cin>>n;

    int size = sizeof(primes)/sizeof(int);
    
    // for(int i=0; i<t;i++){
    //     cin>>n;
    //     cout<<divisible(n);
    // }

    for(int i=1; i<(1<<size); i++){
        int denom = 1;
        int no_of_bits = __builtin_popcount(i);

        int j=0; // go over primes

        int temp = i;
        while(temp >0){
            int lastBit = (temp&1);

            if(lastBit == 1)
                denom *= primes[j++];
            
            temp = (temp>>1);
        }

        if(no_of_bits&1){
            //odd number in intersection
            ans += n/denom;
        }else ans -= n/denom;
    }

    cout<<ans;
    return 0;
}