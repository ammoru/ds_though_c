#include<stdio.h>
int main()
{
	int rows,space,i,j,k;
	printf("enter number of rows:\n");
	scanf("%d",rows);
	for(i=0;i<rows;i++)
	{
		for(space=1;space<=rows-i;space++)
		printf("  ");
		for(j=0;j<=i;j++)
		{
			if(j==0||i==0)
			k=1;
			else
			k=k*(i-j+1)/j;
			printf("%d",k);
		}
		printf("\n");
	}
}