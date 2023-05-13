//nearest 2 pow
#include <stdio.h>
#include<math.h>
int main() {
    int n,x=1,j,d;
    printf("enter n number");
    scanf("%d",&n);
    while(x*2<n)
    {
        x=x*2;
    }
      d=n-x;
      j=2*d+1;
      printf("%d",j);
      
  }
    
    
    
    