#include<iostream>
#include<vector>
using namespace std;

#define ll long long int

void missing(vector<ll> &v, ll m){
    for(int i=0; i<v.size(); i++){
        if(v[i] == m){
            cout<<i;
            break;
        }
    }
}

int main() {
	int n, t;
	ll in, m;
	
	cin>>t;
	
	while(t>0){
		t--;
		cin>>n;
		vector<ll> v;
		for(int i=0; i<n; i++){
			cin>>in;
			v.push_back(in);
		}
		cin>>m;
		missing(v, m);
	}
}