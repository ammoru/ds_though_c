//passing of structer to functin is call by value
#include<stdio.h>
#include<string.h>
 struct point {
    int x;
    int y;
};
void modify(struct point p)
{
    p.x=10;
    p.y= 20;
}
int main()
{
 struct point p1;
 p1.x=4;
 p1.y=5;
 printf("before modifuication %d %d",p1.x,p1.y);
 modify(p1);//call by value
  printf("\nafter modifuication %d %d",p1.x,p1.y);
}
    