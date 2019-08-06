#include<stdio.h> //a letter and a number
#include<string.h>
int main() 
{
	int t,i;
	scanf("%d", &t);
	getchar();
	while(t--) 
	{
	char m;
	int n;
	char a[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char b[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	scanf("%c",&m);
	scanf("%d",&n);
	getchar();
		for(i=0;i<26;i++) 
		{	
			if(m==a[i])
			printf("%d\n",i+n+1);
			if(m==b[i])
			printf("%d\n",-i+n-1);
		}
	}
	return 0; 
} 
