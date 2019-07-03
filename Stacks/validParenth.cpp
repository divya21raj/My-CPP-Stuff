#include <iostream>
#include <stack>
using namespace std;

bool equal(char c1, char c2){
    // switch(c1){
    //     case '{': 
    //         if(c2=='}') return true;
    //         break;
    //     case '[':
    //         if(c2==']') return true;
    //         break;
    //     case '(':
    //         if(c2==')') return true;
    //         break;
    // }
    
    if(c2-c1 == 2 || c2-c1==1) return true;
    
    return false;
}

string solve(string s){
    stack<char> st;
    for(char c: s){
        if(st.empty()){
          st.push(c);
          continue;
        } 
        bool e = equal(st.top(), c);
        if(!e && (c =='}' ||c ==']' ||c ==')' )) return "not balanced";
        if(e) st.pop();
        else st.push(c);
    }
    
    if(st.empty()) return "balanced";
    else return "not balanced";
}
int main() {
	//code
	int t;
	cin>>t;
	while(t>0){
	    string s;
	    cin>>s;
	    cout<<solve(s)<<endl;
	    t--;
	}
	return 0;
}