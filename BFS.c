//bfs c code
#include<stdio.h>
int q[30],f=0,r=-1;
void enqueue(int item)
{
	q[++r]=item;
}
int dequeue()
{
	return q[f++];
}
void bfs(int a[][10],int n,int start)
{
	int visit[n],i,d;
	for(i=0;i<n;i++)
	 visit[i]=0;
	 
	enqueue(start);
	visit[start]=1;
	while(r>=f)
	{
		d=dequeue();
		printf("\t%d",d);
		for(i=0;i<n;i++)
		{
			if(a[d][i]==1 && visit[i]==0)
			{
				enqueue(i);
				visit[i]=1;
			}
		}
	}
}
int main()
{
	int a[10][10],n,i,j,start;
	printf("Enter no of vertices:");
	scanf("%d",&n);
	printf("\nEnter adjacency matrix:");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter start vertex:");
	scanf("%d",&start);
	bfs(a,n,start);
}
