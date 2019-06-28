//GFG
#include<bits/stdc++.h>
using namespace std;
class SortedStack{

public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("");
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        SortedStack *ss = new SortedStack();
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
        int k;
        cin>>k;
        ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);
    }
}

/*This is a function problem.You only need to complete the function given below*/
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   stack<int> r;
   
   while(!s.empty()){
       int t = s.top();
       s.pop();
       
       while(!r.empty() && t> r.top()){
           s.push(r.top());
           r.pop();
       }
       
       r.push(t);
   }
   
   while(!r.empty()){
       s.push(r.top());
       r.pop();
   }
}