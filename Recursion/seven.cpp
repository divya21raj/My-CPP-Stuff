#include <iostream>
#include <vector>
using namespace std;

struct Ans{
    int f = -1, l = -1;
};

int lastSeven(vector<int> &v, int i, bool hasFirst, int ans){
    if(i >= v.size()) return ans;
    
    if(v[i] == 7 && !hasFirst) hasFirst = true;
    else if(v[i] == 7 && hasFirst) ans = i;
    return lastSeven(v, ++i, hasFirst, ans);
}

int firstSeven(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        if(v[i] == 7) return i;
    }
    return -1;
}


int main(){
    int n, in; vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>in;
        v.push_back(in);
    }
    
    cout<<"\nFirst-> "<<firstSeven(v);
    cout<<"\nLast-> "<<lastSeven(v, 0, false, -1);
   
    return 0;
}