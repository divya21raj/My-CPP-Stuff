#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &v, int i, int j){
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
}
void bubbling(vector<int> &v, int i){
    if(i == v.size()-1) return;
    if(v[i] > v[i+1]) swap(v, i, i+1);
    bubbling(v, ++i);
}

void bubbleSort(vector<int> &v, int size){
    if(size==1) return;
    
    bubbling(v, 0);

    bubbleSort(v, size-1);
}

int main(){
    int n, in; vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>in;
        v.push_back(in);
    }

    bubbleSort(v, v.size());

    for(auto i: v) cout<<i<<" ";
   
    return 0;
}