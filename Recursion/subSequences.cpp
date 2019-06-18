#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> fasterSubString(string s, int i){
    
}

vector<string> subStrings(string s, int i){
    vector<string> v;
    v.push_back("");
    if(i == s.length()) return v;

    vector<string> v1 = subStrings(s, i+1);
    
    for(auto c: v1){
        if(c != "") v.push_back(c);
        v.push_back(s[i] + c);
    }

    return v;
}

int main(){
    string s;
    cin>>s;

    vector<string> ans = subStrings(s, 0);

    cout<<ans.size()<<"\n";
    for(auto s: ans) cout<<s<<" ";

    return 0;
}