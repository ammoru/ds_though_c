/*
quick sort
merge sort
*/
void swap(int *arr,int i,int j)
{
	int temp;
	 temp=arr[i];
	 arr[i]=arr[j];
	 arr[j]=temp;
}
int partition(int *arr,int L,int H)
{
	int p=H,i,j,temp;
	for(i=L,j=L;i<p;i++)
	{
		if(arr[i]<arr[p])
		{
			swap(arr,i,j);
			j++;
		}
	}
	swap(arr,j,p);
	return j;
}
void quicksort(int *arr,int L,int H)
{
	if(L<H)
	{
		int par;
		par=partition(arr,L,H);
		printf("%d",par);
		quicksort(arr,L,par-1);
		quicksort(arr,par+1,H);	
	}
	
}
}
int main()
{
	int arr[100],z,i;
	scanf("%d",z);
	for(i=0;i<z;i++)
	{
		scanf("%d",&arr[i]);
	}
	res=quicksort(arr,0,z)
	printf("%d",res);
}
