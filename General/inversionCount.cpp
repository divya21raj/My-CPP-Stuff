#include <iostream>
using namespace std;
int merge(int *a,int s,int e){
    int mid = (s+e)/2;
    int temp[100];

    int i=s;
    int j=mid+1;
    int k=s;
    int cross_inv = 0;

    while(i<=mid and j<=e){
        if(a[i]<a[j]){
            temp[k] = a[i];
            i++;
            k++;
        }
        else{
            temp[k] = a[j];
            cross_inv += (mid-i+1);
            j++;
            k++;
        }
    }
    //copy the remainig elements if second part is terminate
    while(i<=mid){
        temp[k] = a[i];
        i++; k++;
    }
    //copy the remaining if first part is terminate
    while(j<=e){
        temp[k] = a[j];
        j++; k++;
    }
    //finally....
    //copy the elements back to the original array
    for(int i=s;i<=e;i++){
        a[i] = temp[i]; 
    }
    return cross_inv;
}

int mergeSort(int arr[],int s,int e){
    //base case
    if(s>=e){
        return 0;
    }
    //rec case
    int mid = (s+e)/2;
    int x = mergeSort(arr,s,mid);
    int y = mergeSort(arr,mid+1,e);

    int ans = x + y + merge(arr,s,e);
    return ans;
}

int main() {
    int arr[] = {6,2,1,0,5,4};
    int n = sizeof(arr)/sizeof(int);

    cout<<mergeSort(arr,0,n-1)<<endl; 

}
