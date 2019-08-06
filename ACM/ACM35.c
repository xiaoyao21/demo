#include<stdio.h> //房间安排 
int main(void)
{
	int a,b,c,n,m,i,min,max;
	int a1[190]={0};
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		min=180,max=1;
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			for(i=b;i<b+c;i++) //思想 （日期记录在数组的下表中） 
			a1[i]+=a; 
			
			if(min>b)   //记录 最大最小的日期 
			min=b;
			if(max<(b+c-1))
			max=(b+c-1);
		}
		for(i=min+1;i<=max;i++)
		{
		if(a1[min]<a1[i])
		a1[min]=a1[i];
		a1[i]=0;     //最后清 0 
	    }
		printf("%d\n",a1[min]);  
		a1[min]=0;   //清 0 
	}
	return 0;
} 
