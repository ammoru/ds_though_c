/*
postfix evalution

if i is operend:
  push to stack

if i is operator:
    pop  top  two val from stack 
       
  then apply opertor as op2 op op1 and store in result 
   then push (result ) into stack 
      4 5 2 3 * - * 2 3 * +  
      ans =2
*/
#include<stdio.h>
int perform_oper(int op2,char op,int op1)
{
 switch(op)
    {
    	case '+': return op2+op1;
    	case '-': return op2-op1;
        case '*': return op2*op1;
		case '/': return op2/op1;
		case '^': return op2^op1;	
		}	
}
int isoper(char ch)
{
	switch(ch)
	{
	  case '+':
	  case '-':
	  case '*':
	  case '/':
	  case '^':
	       return 1;
	  defualt: return 0;	   	
    }
}
int post_eval(char * post)
{
	int i,val=0,st[100],top=-1,op1,op2,res;
	for(i=0;post[i]!='\0';i++)
	{
		if(isoper(post[i]))
		{
			op1=st[top--];
			op2=st[top--];
			res=perform_oper(op2,post[i],op1);
			st[++top]=res;
		}
		else
		{
		  	if (post[i]>=48 && post[i]<=57)
		  	{
		  		val=val*10+post[i]-'0';
			}
			else if(post[i]==' ' && val!=0)
			{
				st[++top]=val;
				val=0;
			}
		}
	}
	return st[0];
}
int main()
{
	char post[100];
	int res;
	scanf("%[^\n]s",post);
	res=post_eval(post);
	printf("%d",res);
}
