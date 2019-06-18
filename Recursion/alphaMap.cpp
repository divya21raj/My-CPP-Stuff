#include<iostream>
#include<string>
using namespace std;

string generate(string n, int i, string curr){
    if(n.length()==i){
        cout<<curr<<endl; return "";
    }
    curr = char('a' + (n[i] - '0')-1) + generate(n, i+1, curr);
    if(i!=n.length() - 1) {
        curr = char('a' + 10*(n[i] - '0')+(n[i+1] - '0')-1) + generate(n, i+2, curr);
    }
}

int main(){
    string n;
    cin>>n;

    generate(n, 0, "");

    return 0;
}