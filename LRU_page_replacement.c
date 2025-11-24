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
	int time[f];
	for(int i=0; i<f; i++)
	{
		frames[i]=-1;
		time[i]=-1;
	}
	int t=0;
	int index=0;
	for(int i=0; i<p; i++)
	{	
		int flag=0;
		t++;
		for(int j=0; j<f; j++)
		{
			if(pages[i]==frames[j])
			{	
				flag = 1;
				time[j]=t;
				break;
			}
		}
		if(flag==0)
		{
			int empty = -1;
			for(int j=0; j<f; j++)
            		{
                		if(frames[j] == -1)
                		{
                    			empty = j;
                    			break;
                		}
            		}
			if(empty!=-1)
				index = empty;
			else
			{
			int min = time[0];
			index=0;
			for(int j=1; j<f; j++)
			{
				if(time[j] < min)
				{
					min = time[j];
					index = j;
				}
			}
			}
			frames[index]=pages[i];
			time[index]=t;
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
