#include <iostream>
using namespace std;

#define INT_MAX 999999

int n=4;
int dp[16][4];

// Adj Matrix which defines the graph
int dist[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};

//If all cities have been visited
int VISITED_ALL = (1<<n) - 1;

int tsp(int mask,int pos){
    //base case
    if(mask==VISITED_ALL){
        return dist[pos][0];
    }

    //rec case
    int ans = INT_MAX;

    for(int city=0;city<n;city++){
        if((mask&(1<<city))==0){
            int newAns = dist[pos][city] + tsp((mask|(1<<city)),city);
            ans = min(ans,newAns);
        }
    }   
    return ans;
}

int main() {
    cout<<"Min weight hamiltonian path costs "<<tsp(1,0)<<endl;
    return 0;
}
