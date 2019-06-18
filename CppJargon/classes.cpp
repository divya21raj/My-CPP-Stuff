#include <iostream>
using namespace std;

class ComplexNo{
public:
    int real;
    int img;
public:
    ComplexNo(){
        real = img = 0;
    }
    ComplexNo(int r,int i){
        real = r;
        img = i;
    }
    ComplexNo(ComplexNo& x){
        cout<<"In copy construtor";
        real = x.real;
        img = x.img;
    }
    void print(){
        cout<<real<<" + "<<img<<"i"<<endl;
    }
    void operator=(ComplexNo &C){
        real = C.real;
        img = C.img;
    }
    ComplexNo operator+(ComplexNo b){
        ComplexNo temp;
        temp.real = real  + b.real;
        temp.img = img + b.img;
        return temp;
    }
    int operator[](char ch){
        if(ch=='r'){
            return real;
        }
        else{
            return img;
        }
    }
    int operator[](int ch){
        if(ch==0){
            return real;
        }
        else{
            return img;
        }
    }
};

ostream& operator<<(ostream &a, ComplexNo &b){
    b.print();
    return a;
}
istream& operator>>(istream&a, ComplexNo &b){
    a>>b.real>>b.img;
    return a;
}

int main() {
   ComplexNo c1(1,2);
   ComplexNo c2(3,4);
    cin>>c1>>c2;
    cout<<c1<<c2;

   cout<<c1['r']<<endl;
   cout<<c1[1]<<endl;


}
