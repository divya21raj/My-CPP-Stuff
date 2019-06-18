#include <iostream>
using namespace std;

int ld[100]={0},rd[100]={0},col[100]={0};

int count_nqueen(int n,int i){
    //base case
    if(i==n){
        return 1;
    }
    //rec case
    int ans=0;
    for(int j=0;j<n;j++){
        if(col[j]!=1 and rd[i+j]!=1 and ld[i-j+n-1]!=1){
            col[j] = rd[i+j] = ld[i-j+n-1] = 1;
            ans += count_nqueen(n,i+1);
            col[j] = rd[i+j] = ld[i-j+n-1] = 0;
        }
    }
    return ans;
}

int main() {
    int n;
    cout<<count_nqueen(8,0)<<endl;
}
