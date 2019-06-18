#include<iostream>
using namespace std;

void towerOfHanoi(int n, char s, char i, char d){
    if(n == 0) return;
    towerOfHanoi(n-1, s, d, i);
    cout<<"\nDisk "<<n<<" moved from "<<s<<" to "<<d<<".";
    towerOfHanoi(n-1, i, s, d);
}

int main(){
    int n;
    cin>>n;

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}