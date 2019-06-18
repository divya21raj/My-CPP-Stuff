#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int

ll isValid(vector<ll> trees, ll n, ll total, ll h){
    for(auto treeH: trees){
        if(treeH <= h) break;
        total -= (treeH-h);
        if(total <= 0) return true;
    }
    return false;
} 

ll EKO(vector<ll> &v, ll n, ll m){
    long long int high=0, low=0, ans = 0;
    
    sort(v.begin(), v.end(), greater<int>());
    high = v[0];
    
    while(high>=low){
        long long int mid = (high+low)/2;
        if(isValid(v, n, m, mid)){
            ans = mid;
            low = mid + 1;
        }
        else high = mid -1;
    }

    return ans;
}

int main() {
	ll n, m; 
	ll in;
	vector<ll> v, ans;
	
	for(ll i=0; i<1; i++){
        cin>>n>>m;
        v.clear();
        for(ll j = 0; j<n; j++){
            cin>>in;
            v.push_back(in);
        }
        
        ans.push_back(EKO(v, n, m));
	}
	
	for(ll k=0; k<ans.size(); k++){
	    cout<<ans[k]<<"\n";
	}
	return 0;
}