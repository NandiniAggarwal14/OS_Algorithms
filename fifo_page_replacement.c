#include<stdio.h>
int main()
{
	int f, p;
	printf("\nEnter the length of reference string: ");
	scanf("%d", &p);
	int pages[p];
	printf("\nEnter the number of freames: ");
	scanf("%d", &f);
	int frames[f];
	printf("\nEnter the reference string:\n");
	for(int i=0; i<p; i++)
		scanf("%d", &pages[i]);
	int page_faults=0;
	for(int i=0; i<f; i++)
		frames[i]=-1;
	int index=0;
	for(int i=0; i<p; i++)
	{	
		int flag=0;
		for(int j=0; j<f; j++)
		{
			if(pages[i]==frames[j])
			{	
				flag = 1;
				break;
			}
		}
		if(flag==0)
		{
			frames[index]=pages[i];
			index=(index+1)%f;
			page_faults++;
		}
		for(int k=0; k<f; k++)
		{		
			if(frames[k]!=-1)
				printf("%d ", frames[k]);
			else
				printf("- ");
		}
printf("\n");
	}
	printf("\nPage faults: %d", page_faults);
	return 0;
}
