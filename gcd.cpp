#include<iostream>

using namespace std;

int gcd(int, int);

int main(int argc, char const *argv[])
{
    int a, b;
    cin>>a>>b;
    
    cout<<gcd(a, b)<<endl;
    return 0;
}

int gcd(int a, int b){
    if(a == 0)
        return b;
    else if (b == 0)
        return a;
    else return gcd(b, a%b);
}
