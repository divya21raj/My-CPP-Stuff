#include <iostream>
using namespace std;

bool ratmaze(char maze[][5],int sol[][4],int n,int m,int i,int j)
{
	if(i==n-1 && j==m-1)
	{
		sol[i][j]=1;
		for(int k=0;k<n;k++)
		{
			cout<<endl;
			for(int l=0;l<m;l++)
				cout<<sol[k][l];
		}
		cout<<endl;
		return true;
	}

	sol[i][j]=1;

	 if( j+1<m && maze[i][j+1]!='X')
	{
		bool right_rasta=ratmaze(maze,sol,n,m,i,j+1);
		  if(right_rasta==true)
		  	return true;
	}
      if( i+1<n && maze[i+1][j]!='X')
	{
		bool neeche_rasta=ratmaze(maze,sol,n,m,i+1,j);
		  if(neeche_rasta==true)
		  	return true;
	}
	sol[i][j]=0;
	return false;

}

int main(int argc, char const *argv[])
{
	char maze[][5]={"0000",
					"00XX",
					"0000",
					"XX00"};
	int sol[4][4]={0};
	bool ans=ratmaze(maze,sol,4,4,0,0);

	return 0;
}