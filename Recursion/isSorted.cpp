#include<iostream>
#include<vector>
using namespace std;

#define ll long long int

bool isSorted(vector<int> &v, int i){
    if(v.size() == 0) return false;
    if(i == v.size() - 1) return true;
    
    if(v[i] < v[i+1] && isSorted(v, i+1)) return true;
    else return false;
}
int main() {
	int in, n;
	cin>>n;
	
	vector<int> v;
	for(int i=0; i<n; i++){
	    cin>>in;
	    v.push_back(in);
	}
	
	if(isSorted(v, 0)) cout<<"true";
    else cout<<"false";
}