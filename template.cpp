#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

ll placeCows(vector<ll> &v){
    
}

int main() {
	ll t, n, c; 
	ll in;
	vector<ll> v, ans;
	cin>>t;
	
	for(ll i=0; i<t; i++){
        cin>>n>>c;
        v.clear();
        for(ll j = 0; j<n; j++){
            cin>>in;
            v.push_back(in);
        }
        
        ans.push_back(placeCows(v));
	}
	
	for(ll k=0; k<ans.size(); k++){
	    cout<<ans[k]<<"\n";
	}
	return 0;
}