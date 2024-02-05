#include<stdio.h>
int a[30], b[30];
void merge(int a[], int lb, int mid, int ub){
    int i, j, k;
    for(i=lb;i<=ub;i++)
    b[i]=a[i];
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid && j<= ub){
        if(b[i]>b[j]){
            a[k]=b[j];
            j++;
            k++;
        }
        else{
            a[k]=b[i];
            i++; k++;
        }
    }
    while(i<=mid){
        a[k]=b[i];
        k++;i++;
    }
    while(j<=ub){
        a[k]=b[j];
        j++; k++;
    }
}
void divide(int a[], int min, int max){
    int mid;
    if(max>min){
        mid=(min+max)/2;
        divide(a, min, mid);
        divide(a, mid+1, max);
        merge(a, min, mid, max);
    }
}
int main(){
    int n,i;
    printf("Enter the no of elements: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    scanf("%d", &a[i]);
    divide(a,0,n-1);
    for(i=0;i<n;i++)
    printf("%d\t", a[i]);
}
