#include<iostream>
using namespace std;

#define ll long long int

int binarySearch(int*, int, int, int);

int main(int argc, char const *argv[])
{
    ll *arr = new ll[10000];
    ll element;
    string input;
    ll i=0;
    ll n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>input;
        *(arr+i) = stoi(input);
    }
    
    cin>>element;
    ll pos = binarySearch(arr, element, 0, i);
    cout<<pos;

    return 0;
}

ll binarySearch(ll *arr, ll element, ll low, ll high){
    if(low>= high) return -1;
    ll mid = (high-low)/2;
    ll midElemnt = *(arr +mid);
    if(midElemnt == element)
        return mid;
    else if(midElemnt > element)
        return binarySearch(arr, element, low, mid-1);
    else
        return binarySearch(arr, element, mid+1, high);
}

