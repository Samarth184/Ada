#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void mergesort(int a[],int low,int high);
void merge(int a[],int low,int mid,int high);
 
int main()
{
clock_t start , end;
srand(time(NULL));
int a[50000],n,i;
printf("Enter no of elements:");
scanf("%d",&n);
printf("Enter array elements:");
for(i=0;i<n;i++)
a[i] = rand()%10000;
start = clock();
mergesort(a,0,n-1);
printf("\nSorted array is :");
end = clock();
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\nThe time elapsed in sorting %d elements is %lf", n, ((double)(end-start)/CLOCKS_PER_SEC));
return 0;
}
 
void mergesort(int a[],int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
mergesort(a,low,mid); 
mergesort(a,mid+1,high); 
merge(a,low,mid,high); 
}
}
 
void merge(int a[],int low,int mid,int high)
{
int temp[50000]; 
int i,j,k;
i=low; 
j=mid+1; 
k=0;
while(i<=mid && j<=high) 
{
if(a[i]<a[j])
temp[k++]=a[i++];
else
temp[k++]=a[j++];
}
while(i<=mid) 
temp[k++]=a[i++];
while(j<=high) 
temp[k++]=a[j++];

for(i=low,j=0;i<=high;i++,j++)
a[i]=temp[j];
}