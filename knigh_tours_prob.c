//Knights Tour Problem
#include<stdio.h>
#define n 8
void printsol(int sol[n][n])
{
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%2d ",sol[i][j]);
		printf("\n");
	}
}
int isSafe(int x,int y,int sol[n][n])
{
	return ((x>=0 && x<n)&&(y>=0 && y<n)&&(sol[x][y]==-1));
} 
int solveKTuntil(int,int,int,int [][n],int [],int []);
int solveKT();
int main()
{
	int t=solveKT();
	return 0;
}
int solveKT()
{
	int sol[n][n],i,j;
	int xMove[8]={2,2,1,-1,-2,-2,-1,1};		// 8 combinations of move of knight around x and y coordinate
	int yMove[8]={1,-1,-2,-2,-1,1,2,2};
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			sol[i][j]=-1;			//initializing each block with -1
	sol[0][0]=0;			//starting from 0,0
	//Starts from 0,0 and explores all the positions using solveKTuntil()
	// solveKTuntil(present_x,present_y,next_place,sol,xMove,yMove);
	if(solveKTuntil(0,0,1,sol,xMove,yMove)==0)
	{
		printf("Solution doesnt exists !!");
		return 0;
	}
	else
		printsol(sol);
	return 1;
}
int solveKTuntil(int x,int y,int movei,int sol[n][n],int xMove[n],int yMove[n])
{
	int k,next_x,next_y;
	if(movei==n*n)
		return 1;
	for(k=0;k<8;k++)
	{
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if(isSafe(next_x,next_y,sol))
		{
			sol[next_x][next_y]=movei;
			if(solveKTuntil(next_x,next_y,movei+1,sol,xMove,yMove)==1)
				return 1;
			else
				sol[next_x][next_y]=-1;		//backtracking
		}
	}
	return 0;
}
