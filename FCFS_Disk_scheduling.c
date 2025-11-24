#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	printf("\nEnter the length of request string: ");
	scanf("%d", &n);
	int req[n];
	int head;
	int dist;
	printf("\nEnter the position of head: ");
	scanf("%d", &head);
	printf("\nEnter the request string: ");
	for(int i=0; i<n; i++)
		scanf("%d", &req[i]);
	printf("\n");
	printf(" %d", head);
	for(int i=0; i<n; i++)
	{	
		printf(" -> %d", req[i]);
		dist+=abs(req[i]-head);
		head=req[i];
	}
	printf("\nTotal distance travelled: %d", dist);
	return 0;
}
