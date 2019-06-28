#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

ll solve(vector<ll> &v){
    return v.size();
}

int main() {
	ll t, n; 
	ll in;
	vector<ll> v, ans;
	cin>>t;
	
	for(ll i=0; i<t; i++){
        cin>>n;
        v.clear();
        for(ll j = 0; j<n; j++){
            cin>>in;
            v.push_back(in);
        }
        
        cout<<solve(v)<<endl;
	}
	
	return 0;
}