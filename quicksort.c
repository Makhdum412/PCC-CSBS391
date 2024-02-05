//quick sort
#include<stdio.h>
int partition(int a[],int min,int max)
{
	int pivot=min,t;
	while(max>min)
	{
		while(a[min]<=a[pivot])min++;
		while(a[max]>a[pivot])max--;
		if(max>min)
		{
			t=a[min];a[min]=a[max];a[max]=t;
		}
	}
	t=a[max];
	a[max]=a[pivot];
	a[pivot]=t;
	return max;
}
void qsort(int a[],int min,int max)
{
	int p;
	if(max>min)
	{
		 p=partition(a,min,max);
		 qsort(a,min,p-1);
		 qsort(a,p+1,max);
	}
}
int main()
{
	int a[30],n,i;
	printf("Enter no of elemets:");
	scanf("%d",&n);
	printf("\nEnter %d elements",n);
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	qsort(a,0,n-1);
	printf("\nAfter soting:");
	for(i=0;i<n;i++)
	  printf("\t%d",a[i]);
		
}
