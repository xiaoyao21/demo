#include<stdio.h> //���䰲�� 
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
			for(i=b;i<b+c;i++) //˼�� �����ڼ�¼��������±��У� 
			a1[i]+=a; 
			
			if(min>b)   //��¼ �����С������ 
			min=b;
			if(max<(b+c-1))
			max=(b+c-1);
		}
		for(i=min+1;i<=max;i++)
		{
		if(a1[min]<a1[i])
		a1[min]=a1[i];
		a1[i]=0;     //����� 0 
	    }
		printf("%d\n",a1[min]);  
		a1[min]=0;   //�� 0 
	}
	return 0;
} 
