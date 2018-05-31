#include<stdio.h>  //Coin Test 
int main(void)
{
	char a[100000];
	int i,n,k=1,u=0,v=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='S')
		{
			k=0;
		}
		if(a[i]=='U')
		u++;
		else if(a[i]=='V')
		v++;
	}
	if(k=0)
	printf("Bingo");
	else if(((u/(1.0*(u+v)))<0.003)||((u/(1.0*(u+v)))>0.5))
	printf("Fail");
	return 0;
} 
