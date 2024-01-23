//dfs c code
#include<stdio.h>
int s[30],top=-1;
void push(int item)
{
	s[++top]=item;
}
int pop()
{
	return s[top--];
}
void dfs(int a[][10],int n,int start)
{
	int visit[n],i,d;
	for(i=0;i<n;i++)
	 visit[i]=0;
	 
	push(start);
	visit[start]=1;
	while(top!=-1)
	{
		d=pop();
		printf("\t%d",d);
		for(i=0;i<n;i++)
		{
			if(a[d][i]==1 && visit[i]==0)
			{
				push(i);
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
	dfs(a,n,start);
}
