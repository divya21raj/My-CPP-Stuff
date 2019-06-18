#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Uber{
    public: 
        string name;
        int x, y;
        float d;
        
        Uber(){}

        Uber(int x, int y, string s){
            this->x = x;
            this->y = y;
            name = s;
            d = sqrt(pow(x, 2) + pow(y, 2));
        }

        bool static compare(Uber a, Uber b){
            return a.d<b.d;
        }

        Uber operator+(Uber b){
            Uber temp;
            temp.x = x + b.x;
            temp.y = y + b.y;
            return temp;
        }
};

int main() {
    vector<Uber> carList;
    carList.reserve(1000);
    carList.push_back(Uber(20, 12, "A"));
    carList.push_back(Uber(1, 20, "B"));
    carList.push_back(Uber(-20, 10, "C"));
    carList.push_back(Uber(30, 0, "D"));
    carList.push_back(Uber(10, -10, "E"));

    sort(carList.begin(), carList.end(), Uber::compare);

    // for(auto car: carList){
    //     cout<<car.name<<" "<<car.d<<endl;
    // } 

    cout<<(Uber(20,10,"") + Uber(10, 12, "")).x;
}
