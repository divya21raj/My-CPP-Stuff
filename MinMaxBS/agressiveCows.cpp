#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int

bool isValid(vector<ll> &v, ll n, ll c, ll min){
    ll placed_cow = 1;
    ll pos = v[0];

    for(auto i: v){
        if(i - pos >= min){
            placed_cow++;
            pos = i;
            if(placed_cow >= c) return true;
        }
    }
    
    return false;
}

ll placeCows(vector<ll> &v, ll n, ll c){
    ll s= 0, ans;
    sort(v.begin(), v.end());
    ll e = v[v.size()] - v[0];

    while(e>=s){
        ll mid = (s+e)/2;
        if(isValid(v, n, c, mid)){
            ans = mid;
            s = mid + 1;
        }
        else e = mid -1;
    }

    return ans;
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
        
        ans.push_back(placeCows(v, n, c));
	}
	
	for(ll k=0; k<ans.size(); k++){
	    cout<<ans[k]<<"\n";
	}
	return 0;
}