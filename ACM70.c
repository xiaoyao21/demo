//功能就是找出在字符串str1中第一次出项字符串str2的位置
//(也就是说字符串sr1中要包含有字符串str2)，找到就返回该字符串位置的指针
//(也就是返回字符串str2在字符串str1中的地址的位置)，找不到就返回空指针(就是 null)。
/*#include<stdio.h>   //超时 
#include<string.h>  //strstr 函数在这个头文件中包含
	int main(void)
	{
		char a[10];
		int i,j,k,n,m,o,p;
		o=0;
		while(scanf("%d %d",&n,&m)!=EOF)
		{  
			o++;
			p=k=0;
			for(i=n;i<m;i++)
			{
				sprintf(a,"%d",i);
				if((strstr(a,"1")!=NULL)&&(strstr(a,"5")!=NULL)&&(strstr(a,"2")!=NULL))
				k++;
				if(strstr(a,"521")!=NULL)
				p++;
			}
		printf("Case %d:%d %d\n",o,k,p);
		}
	return 0;
}*/ 

#include <stdio.h>
#include <string.h>
	int num[1000001] = { 0 };
	int num2[1000001] = { 0 };
	char temp[20];
	int i; 
	int main() 
	{
	for (i=125;i<=1000000;i++) 
	{
		sprintf(temp,"%d",i);
		if (strstr(temp,"521")!=NULL) 
		{
			num2[i]=num2[i-1]+1;
		}
		else num2[i]=num2[i-1];
		if (strchr(temp,'5')==NULL||strchr(temp,'2')==NULL||strchr(temp,'1') ==NULL)
		{
			num[i]=num[i-1];
			continue;
		}
		num[i]=num[i-1]+1;
	}

	int x, y;
	int caseNum = 1;
	while (~scanf("%d%d", &x, &y)) {
		printf("Case %d:%d %d\n",caseNum,num[y]-num[x-1],num2[y]-num2[x-1]);
		caseNum++;
	}
}
