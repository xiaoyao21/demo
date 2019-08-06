#include<stdio.h>  //精挑细选
int main(void)
{
	int a,b,c,q=0,w=0,e=0;
	int n,m,i,j;
	scanf("%d",&n);
	while(n--)
	{
		q=0,w=0,e=0;
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&a,&b,&c); //长度 直径 编码 
			if((a>q)||(a==q&&b<w)||(a==q)&&(b==w)&&c>e)
			{
				q=a;
				w=b;
				e=c;
			}
		}
		printf("%d\n",e);
	}
		return 0;
} 
