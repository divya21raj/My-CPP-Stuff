#include <iostream>

using namespace std;

class Fun{
    public:
        void operator()(){
            cout<<"Functor"<<endl;
        }

        void operator()(string s){
            cout<<"Functor "<<s<<endl;
        }
};

int main() {
    Fun f;
    f();
    f("Romeo");
}
