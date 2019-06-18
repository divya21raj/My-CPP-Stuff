#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<long long int> &ranks, int p, int chefs, int maxTime){
    long long int curr_chef = 1;
    
    for(auto rank: ranks){
        int time = 0, i=0;
        while(time + (i+1)*rank < maxTime) {
            i++;
            time += (i)*rank;
            p--;
            if(p <= 0) return true;
        }
        curr_chef++;
    }

    //if(curr_chef = chef) return true;
    
    return false;
}

int divide(vector<long long int> &ranks, int p, int l){
    long long int high=__INT_MAX__, low = 0, max, time=0;
    
    // Getting search space of answers
    while(high>=low){
        long long int mid = (high+low)/2;
        if(isValid(ranks, p, l, mid)){
            max = mid;
            high = mid -1;
        }
        else low = mid + 1;
    }

    for(auto rank: ranks){
            int i=0;
            while(time + (i+1)*rank < max) {
                i++;
                time += (i)*rank;
                p--;
                if(p <= 0) break;
            }
        }

    return time;
}

int main() {
	long long int t, p, l; 
	long long int in;
	vector<long long int> v, ans;
	cin>>t;
	
	for(int i=0; i<1; i++){
        cin>>p;
        cin>>l;
        v.clear();
        for(int j = 0; j<l; j++){
            cin>>in;
            v.push_back(in);
        }
        
        ans.push_back(divide(v, p, l));
	}
	
	for(int k=0; k<ans.size(); k++){
	    cout<<ans[k]<<"\n";
	}
	return 0;
}