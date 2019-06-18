#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<long long int> &v, int n, int painter, int boards){
    long long int curr_painter = 1;
    long long int curr_board = 0;

    for(auto i: v){
        curr_board += i;
        if(curr_board > boards){
            curr_painter++;    
            curr_board = i;
            if(curr_painter > painter) return false;
        }
    }

    //if(curr_painter = painter) return true;

    return true;
}

int divide(vector<long long int> &v, int n, int m){
    long long int high=0, low=0, ans;
    for(auto i: v) {
        high+=i;
        low = max(low, v[i]);
    }
    
    while(high>=low){
        long long int mid = (high+low)/2;
        if(isValid(v, n, m, mid)){
            ans = mid;
            high = mid -1;
        }
        else low = mid + 1;
    }

    return ans;
}

int main() {
	long long int t, n, m; 
	long long int in;
	vector<long long int> v, ans;
	cin>>t;
	
	for(int i=0; i<t; i++){
        cin>>n;
        cin>>m;
        v.clear();
        for(int j = 0; j<n; j++){
            cin>>in;
            v.push_back(in);
        }
        
        ans.push_back(divide(v, n, m));
	}
	
	for(int k=0; k<ans.size(); k++){
	    cout<<ans[k]<<"\n";
	}
	return 0;
}