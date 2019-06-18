#include <iostream>
using namespace std;

void generate(string curr, int n){
    if(n==0) {
        cout<<curr<<endl;
        return;
    }
    generate(curr + "(", n-1);
    generate(curr + ")", n-1);
}

void generateBal(string curr, int n, int i, int open, int close){
    if(i==n){
        cout<<curr<<endl;
        return;
    }

    if(open < n/2) generateBal(curr + "(", n, i+1, open+1, close);

    if(close<open) generateBal(curr + ")", n, i+1, open, close+1);
}

int main(){

    int n;
    cin>>n;
    
    //generate("", 2*n);
    generateBal("", 2*n, 0, 0, 0);

    return 0;
}