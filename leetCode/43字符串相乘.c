#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * multiply(char * num1, char * num2){   //2 3
	
	if(num1[0]=='0'||num2[0]=='0'){
//		char *p = (char*)malloc(2*(sizeof(char)));//动态申请内存
		char p[2];
		p[0]='0';
		p[1]='\0';
		return p;
	}
	int m,n,x,y,i,j;
	int data[100000]={0};
	m=strlen(num1);  //记录的是长的 
	x=m-1;
	n=strlen(num2);  //短的字符串 
	y=n-1;

	char *mm = (char*)malloc(m*(sizeof(char)));
	char *nn = (char*)malloc(n*(sizeof(char)));
	
	i=0;
	while(x>=0){
		mm[i]=num1[x];
		i++;
		x--;
	}
	
	i=0;
	while(y>=0){
		nn[i]=num2[y];
		i++;
		y--;
	}
	
	for(i=0;i<n;i++){  //num2
		for(j=0;j<m;j++){  //num1

			data[j+i]+=((nn[i]-48)*(mm[j]-48)%10);
			data[j+i+1]+=((nn[i]-48)*(mm[j]-48)/10);
		}
	}

	for(i=0;i<=n*m;i++){
		data[i+1]+=data[i]/10;
		data[i]=data[i]%10;
	}
	
	int s=n*m;

	while(data[s]==0){
		s--;
	}
	
	i=0;
	char *p = (char*)malloc(s*(sizeof(char)));//动态申请内存
	while(s>=0){

		p[i]=(data[s]+48);
		i++;
		s--;
	}
	p[i]='\0';
	return p;
}

int main(void) {
	char a[110];
	char b[110];
	char *ap = a;
	char *bp = b;
	ap = strcpy(a, "0");
	bp = strcpy(b, "0");
	printf("%s",multiply(ap,bp));
}



//	=================================================================  未知错误====== 
//	==31==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x602000000091 at pc 0x000000402779 bp 0x7ffe863aa770 sp 0x7ffe863aa768
//	WRITE of size 1 at 0x602000000091 thread T0
//	#2 0x7fcaf35e92e0 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x202e0)
//	
//	0x602000000091 is located 0 bytes to the right of 1-byte region [0x602000000090,0x602000000091)
//	allocated by thread T0 here:
//	#0 0x7fcaf4a732b0 in malloc (/usr/local/lib64/libasan.so.5+0xe82b0)
//	#3 0x7fcaf35e92e0 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x202e0)

