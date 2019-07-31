#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> permutations(string s, int i){
    vector<string> v;
    if(i == s.length()) {
        v.push_back(s);
        return v;
    }

    vector<string> v1;
    for(int j=i; j != s.length(); j++){
        swap(s[i], s[j]);
        v1 = permutations(s, i+1);
        swap(s[i], s[j]);
        for(auto s1: v1) v.push_back(s1);
    }

    return v;
}

int main(){
    string s;
    cin>>s;

    vector<string> ans = permutations(s, 0);

    cout<<ans.size()<<"\n";
    for(auto s: ans) cout<<s<<endl;

    return 0;
}