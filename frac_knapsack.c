/* Fractional Knapsack (Greedy Method)
   Soumil Bose
*/
#include<stdio.h>
typedef struct Item{
	float wt,profit;
	float ratio;	//profit:wt
}item;
void sort(item arr[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr[i].ratio<arr[i+1].ratio)
			{
				item swap = arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=swap;
			}
			else if(arr[i].ratio==arr[i+1].ratio)
			{
				if(arr[i].profit<arr[i+1].profit)
				{
					item swap = arr[i];
					arr[i]=arr[i+1];
					arr[i+1]=swap;
				}
			}
			else
				continue;	
		}
	}
			
}
float calc(int W, item arr[], int n)
{
	int i;
	float Profit;
	for(i=0;i<n;i++)
	{
		if(arr[i].wt>W)
		{
			Profit=Profit+(W/arr[i].wt)*arr[i].profit;
			W=W-(W/arr[i].wt)*arr[i].wt;
		}
		else
		{
			Profit+=arr[i].profit;
			W-=arr[i].wt;
		}
	}
	return Profit;
}
int main()
{
	int n,W;
	printf("\nEnter the no of objects - ");
	scanf("%d",&n);
	printf("\nEnter the max weight of the knapsack - ");
	scanf("%d",&W);
	item arr[n];
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter weight and value of object - %d - ",i+1);
		scanf("%f%f",&arr[i].wt,&arr[i].profit);
		arr[i].ratio=(arr[i].profit/arr[i].wt);
	}
	sort(arr,n);
	float Profit = calc(W,arr,n);
	printf("Max profit of the knapsack is %f",Profit);
	return 0;
}












		
