#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	printf("\nEnter the length of request string: ");
	scanf("%d", &n);
	int req[n];
	int done[n];
	int head;
	int dist=0;
	printf("\nEnter the position of head: ");
	scanf("%d", &head);
	printf("\nEnter the request string: ");
	for(int i=0; i<n; i++)
		scanf("%d", &req[i]);
	for(int i=0; i<n; i++)
		done[i]=0;
	printf("\n");
	printf(" %d", head);
	for(int r=0; r<n; r++)
	{	
		int index = -1;
		int min = 9999;
		for(int i=0; i<n; i++)
		{
			if(!done[i])
			{
				int diff = abs(req[i]-head);
				if(diff < min)
				{
					min = diff;
					index = i;	
				}
			}
		}
		printf(" -> %d", req[index]);
		dist+=abs(req[index]-head);
		head=req[index];
		done[index]=1;
	}
	printf("\nTotal distance travelled: %d", dist);
	return 0;
}
