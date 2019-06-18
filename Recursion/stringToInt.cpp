#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int toInt(string s, int index){
    if(index >= s.size()) return 0;
    
    return pow(10, s.size()-1-index)*(s[index]-'0') + toInt(s, index+1);
}

int main(){
    string s;
    
    cin>>s;
    
    cout<<toInt(s, 0);
   
    return 0;
}