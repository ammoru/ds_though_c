#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, maxIndex, temp;
    
    for (i = n-1; i >= 0; i--) {
        maxIndex = i;
        for (j = i-1; j >= 0; j--) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}

int main()
{
	int arr[100],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	selectionSort(arr,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
