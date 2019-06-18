#include<iostream>
#include<vector>
using namespace std;

#define ll long long int

static ll fact[1001];

ll factorial(int n){
    if(fact[n] != 0) return fact[n];
    
    ll ans = n*factorial(n-1);
    fact[n] = ans;
    
    return ans;
}
int factoSum(vector<int> &v){
    ll sum = 0;
    for(int i: v){
        if(i<107) sum+=factorial(i)%107;
    }
    
    return sum;
}
int main() {
	int in, n;
	cin>>n;
	
	fact[0] = 1;
	
	vector<int> v;
	for(int i=0; i<n; i++){
	    cin>>in;
	    v.push_back(in);
	}
	
    cout<<factoSum(v);
}