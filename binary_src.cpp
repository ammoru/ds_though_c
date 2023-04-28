#include<stdio.h>
int binary_src(int *arr,int size, int se)
{
	int l=0,h,m;
	h=size-1;

	 while(l<=h)
	 {
	 	m=(l+h)/2;
	 	if (arr[m]==se)
	 	{
	 		return m;
		 }
		 else if (arr[m]<se)
		 {
		     l=m+1;
		 }
		  else if (arr[m]>se)
		  {
		      h=m-1; 
	      }
	 }
	 return -1;
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
  res = binary_src(arr,n,key);
 printf("%d",res);
}