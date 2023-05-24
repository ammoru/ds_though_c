#include<stdio.h>
int linear_rec(int *arr,int n,int i,int key)
{
	if(i==n)
	 {
	 	return -1;
	 }
    if( arr[i]==key)
    {
    	return i;
	}
	linear_rec(arr,n,i+1,key);
}
int main()
{
int arr[100];
int n,i,res,key;
scanf("%d",&n);
printf(" enter elements ");
 for(i=0;i<n;i++)
 {
 	scanf("%d",&arr[i]);
 }
 
 scanf("%d",&key);
  res = linear_rec(arr,0,n,key);
  printf("%d",res);
}