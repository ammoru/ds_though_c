/*i
0   1  2  3  4 
10 20 30 40 50


j
0 1 2  3  4  5  6  7  8 
2 4 7 11 15 30 46 60 300

k
0 1 2 3 4 5 6 7 8 9 0 1 2 3
0 0 0 0 0 0 0 0 0 0 0 0 0 0
if arr1[i]>arr2[j]-->res[k]=arr1[j]--->k++,j++
else arr2[j]>arr1[i]-->res[k]=arr2[i]-->k++,i++
while j<m
res[k]=arr2[j]
j++
k++
while i<n
res[k]=arr1[i]
i++
k++

_______________________________________________________
*/
#include<stdio.h>
void mergesort(int *arr1,int n,int *arr2,int m)
{
	int res[100]={0},i=0,j=0,k=0;
	while(i<n && j<m)
	{
		if(arr1[i]>arr2[j])
		{
		  res[k]=arr2[j];
		  j++;
		  k++;
		}
		else
		{
			res[k]=arr1[i];
			i++;
			k++;
		}
	}
	while(j<m)
	{
		res[k]=arr2[j];
		j++;
		k++;
	}
	while(i<n)
	{
		res[k]=arr1[i];
		i++;
		k++;
		
	}
	for(i=0;i<m+n;i++){
	printf("%d ",res[i]);}
	
}
int main()
{
	int n,m,i,j,res,arr1[100],arr2[100];
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr1[i]);
		
	}
	for(j=0;j<m;j++)
    {
	scanf("%d",&arr2[j]);
    }
	mergesort(arr1,n,arr2,m);

}
