#include<stdio.h>  //The Famous Clock 
#include<string.h>
int main() {
char s[5];
int t = 1;
	while(scanf("%s", s)!=EOF) 
	{
	printf("Case %d: ", t++);
		if(strcmp(s, "I") == 0) printf("1\n");
		else if(strcmp(s, "II") == 0) printf("2\n");
		else if(strcmp(s, "III") == 0) printf("3\n");
		else if(strcmp(s, "IV") == 0) printf("4\n");
		else if(strcmp(s, "V") == 0) printf("5\n");
		else if(strcmp(s, "VI") == 0) printf("6\n");
		else if(strcmp(s, "VII") == 0) printf("7\n");
		else if(strcmp(s, "VIII") == 0) printf("8\n");
		else if(strcmp(s, "IX") == 0) printf("9\n");
		else if(strcmp(s, "X") == 0) printf("10\n");
		else if(strcmp(s, "XI") == 0) printf("11\n");
		else printf("12\n");
	}
	return 0;
}
