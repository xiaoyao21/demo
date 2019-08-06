#include"library.h"

student *creat_student(student *h1,book *h);   //学生注册  编号不能重复 
student *change_passworld_student(student *p1);  //学生修改密码 
void print_student(student *h1);  //链表的输出
void return_book(student *p1,book *h); //还书  （ 说找学生链表的节点 书籍信息的头节点 ）
void borrow_book(student *p1,book *h); //借书
student *Open_student(); //从文件中将信息加入链表中 
student *student_check(student *h1); //学生登陆端
void password_password_add(char password[]); //密码加密
void password_password_pass(char password[]); //密码解密 
void Save_student(student *h1);  //存储学生信息在文件中 
void find_student(book *h,int m); //学生查找图书 按书名 编号 类型 作者 (书籍信息的头节点)选项四项 
void student_mine(student *p1,book *h); //查看自己的借阅情况  (传入学生的信息，和书信息的头节点)

 student *creat_student(student *h1,book *h)   //学生注册  编号不能重复 
{
	system("cls");
	student *p,*q;
	int i=1,k=2,n,j=1,r;
	char a[20],b[20];
	book *p1;
	p1=h->next; 
	q=h1->next;
	p=(student *)malloc(sizeof(student));
	printf("\n\n\t\t\t---------- 欢迎来到注册界面 ----------\n\n"); 
	printf("\t\t\t姓名：");
	scanf("%s",p->name);
	printf("\t\t\t学号：");
	scanf("%s",p->number);
	while(q)
	{
		if(strcmp(q->number,p->number)==0)    
		{
		printf("\t\t\t该学号已被注册~~"); 
		i=0;
		break;
		}
		else q=q->next;	
	}
	if(i)
	{
	printf("\t\t\t你的密码：");
	manager_password(a);
	loop:printf("\n\t\t\t再次输入：");   //加个 goto 语句方便！！ 
	manager_password(b);
	if(strcmp(a,b)==0) 
	strcpy(p->password,a);
	else 
	j=0;
		if(j)
		{
			printf("\n\t\t\t注册日期：");
			scanf("%s",p->bookdate);
			loo:printf("\t\t\t数量：");
			scanf("%d",&p->many);
			if(p->many>5)
			{
				printf("\t\t\tDear 做多借5本呦~\n\n"); 
				goto loo; 
			}
			
			for(r=0;r<p->many;r++)
			{
				printf("\t\t\t书号：");    
				scanf("%s",p->count[r]);
				p1=h->next; 
				while(p1)
				{
					if(strcmp(p->count[r],p1->number)==0)
					break;
					else p1=p1->next;
				} 
				if(p1==NULL)
				{
						printf("\t\t\t···");
						Sleep(1000);
						printf("\n\t\t\tSorry 该书不存在！");
						printf("\n\t\t\t请重新输入正确书号.\n\n");
						r-=1;   //书不存在得多输入一次 
				}
				else if(p1->amount==0)
				{
					printf("\n\t\t\tSorry 该书库存不足！"); 
					printf("\n\t\t\t请重新录入书号.\n\n");
					r-=1;
				}
				else
				{
					p1->borrow+=1;  //直接在注册的时候改变库存 
					p1->amount-=1;
				}	
			}
			
			p->next=h1->next;
			h1->next=p;	
			printf("\n\t\t\t请稍等，正在注册···\n");
			Sleep(1000);
			printf("\t\t\t···\n");
			Sleep(1000);
			printf("\t\t\t···\n");
			Sleep(1000);
			printf("\t\t\tDear %s注册成功~",p->name);
			printf("\n\n\n\t\t\t按任意键返回后请重新登陆~");
			getch();
			return h1;	
		}
		else if(k) 
		{
			printf("\n\t\t\t(两次输入的密码不相同 您还可以输入%d次)",k--);
			j=1;
			if(k+1) goto loop;
		} 
	    if(k==0)
		{
		printf("\n\n\t\t非常抱歉 输入超时 我们即将退出此页面 您可以选择重新注册");
		printf("\n\t\t\t请稍等，正在退出···\n");
			Sleep(1000);
			printf("\t\t\t···\n");
			Sleep(1000);
			printf("\t\t\t···\n");
			Sleep(1000);
		screen_student();
		}
	}
	else
	{
	printf("\n\t\t\t按任意键后请重新选择~");getch();screen_student();	
	}
}
 
student *change_passworld_student(student *p1)//修改密码 
{
    char a[20],b[20]; //将文件信息加入链表中          //查找到与信息同样的链表 ！！！p指针没有在链表 h中 
	printf("\n\t\t\t请输入新密码：");    //从文件中读取了两次 所以两次链表被赋予的头指针不同 
    looi:manager_password(a);
	if(strcmp(a,p1->password)==0)
	{
		printf("\n\t\t\tSorry 新密码不能与旧密码相同！");
		printf("\n\t\t\t请重新输入\n"); 
		printf("\n\t\t\t不同的新密码：");
		goto looi;
	}
	
	printf("\n\t\t\t再次输入密码：");
	manager_password(b);
	if(strcmp(a,b)==0)
	{
		strcpy((p1->password),a);   // 
		printf("\n\t\t\t修改密码成功！");
		printf("请重新登陆！");
		Sleep(1000);
			printf("\n\t\t\t···\n");
			Sleep(1000);
			printf("\t\t\t···\n");
			Sleep(1000);
		return p1;
	}
		else 
		{
		printf("\n\t\t\t两次输入的密码不相同 修改失败！");
		printf("\n\t\t\t按任意键后请重新选择~");getch();screen_student_book();
		}	
}
 
void print_student(student *h1)  //链表的输出 
{
	student *p;
	int i;
	p=h1->next;
	printf("\n\n\t\t\t======================================================\n");
	printf("\n\t\t\t姓名\t学号\t\t注册日期\t数量\t书号\t\n");
	while(p)
	{
		if((p->many)!=0)
		{
			printf("\t\t\t%s",p->name);
	printf("\t%s",p->number);
	printf("\t%s",p->bookdate);
	printf("\t%d",p->many);
	for(i=0;i<p->many;i++)
	{ 
		printf("\t%s",p->count[i]);
	}
	printf("\n");
		p=p->next;
	}
		}
	printf("\n\t\t\t======================================================\n");
}
 
 void return_book(student *p1,book *h)//还书  （ 说找学生链表的节点 书籍信息的头节点 ） 
 {
 	system("cls");
 	student_mine(p1,h);
 	char a[20];
    int i,j=1;
 	book *q=h->next;
 	if(p1->many==0)
 	;
 	else
 	{
 	 	printf("\t\t\t请输入还书编号：");
 		scanf("%s",a);
 		while(q)
 			{
 			if(strcmp(a,q->number)==0)
 			break;
 			q=q->next;
 			}
 		if(q==NULL)
 		printf("\n\t\t\t编号错误！ 没有该书~");
 		else
 			{  
 			q=h->next;
 			for(i=0;i<p1->many;i++)
 			{
 				if(strcmp(a,p1->count[i])==0)
 				{
 				for(i;i<p1->many;i++)
 				strcpy(p1->count[i],p1->count[i+1]);
 				p1->many-=1;
 				while(q)
 				{
 					if(strcmp(a,q->number)!=0)
 					q=q->next;
 					else 
					 {
					 	q->amount+=1;
 						q->borrow-=1;
 						break;
					 }
 				}
 					printf("\n\t\t\t请稍等，正在办理中···\n");
					Sleep(1000);
					printf("\t\t\t···\n");
					Sleep(1000);
					printf("\t\t\t···\n");
					Sleep(1000);
 					printf("\n\t\t\tHellow 还书成功！");
 				j=0;
 				break;
 				}
 			}
 			if(j)
 			printf("\n\t\t\t抱歉 您并未借过此书~~");
 		}		
 	}

 printf("\n\n\t\t\t按任意键返回~"); getch();screen_student_book();
 }
 
void borrow_book(student *p1,book *h)//借书 
 {
 	system("cls");
 h=book_sore_number(h);
 book_print(h); 
 	char a[20];
 	int i;
 	book *q=h->next;
 	if((p1->many)>=5)
 	{
 		printf("\t\t\tDear 你已经达到最大借额 您可以选择还书后再借~");
 	}
 	else
 	{	printf("\n\t\t\t Dear %s 已借%d本 可借%d本 ",p1->name,p1->many,(5-p1->many));
 		printf("\t\t\t请输入借书编号：");
 		scanf("%s",a);
 		while(q)
 		{
 			if(strcmp(a,q->number)==0)
 			break;
 			q=q->next;
 		}
  	 	if(q==NULL)
 		printf("\n\t\t\tSorry编号错误！ 没有该书~");
 		
 		else
 		{
 			if(q->amount<=0)
 			printf("\n\t\t\tSorry 该书的库存已为0 暂时无法借阅. . .");
 			else{
 			 i=p1->many;
 			 strcpy((p1->count[i]),a);
 			 p1->many+=1;
 			 q->amount-=1;
 			 q->borrow+=1;
 			 printf("\n\t\t\t请稍等，正在办理中···\n");
			 Sleep(1000);
			 printf("\t\t\t···\n");
			 Sleep(1000);
			 printf("\t\t\t···\n");
			 Sleep(1000);
 			 printf("\t\t\tDear 成功借书！"); 
 			}
 		}
	}
	printf("\n\n\t\t\t按任意键返回~"); 
	getch();screen_student_book();
}
	

 student *Open_student() //从文件中将信息加入链表中 
{
	FILE *fp;
	student *h1,*p,*p1;
	int i;
	if((fp=fopen("student.txt","rt"))==NULL){
		printf("\t\t打开失败\n");
		getch();
		exit(1);
	}
	h1=(student*)malloc(sizeof(student));
	h1->next=NULL;
	p1=h1;
	while(!feof(fp))  //文件流指向空为停止寻找 
	{
		p=(student*)malloc(sizeof(student));
		fscanf(fp,"%s",p->name);
		fscanf(fp,"%s",p->number);
		fscanf(fp,"%s",p->password);
		fscanf(fp,"%d",&p->many);
		password_password_pass(p->password);
		for(i=0;i<p->many;i++)
		{
			fscanf(fp,"%s",p->count[i]);  //记录借书的编号 
		}
			fscanf(fp,"%s",p->bookdate);
		p1->next=p;
		p1=p;
	}
		p1->next=NULL;
	fclose(fp);
	return h1;
}

student *student_check(student *h1) //学生登陆端 
{
	char a[20],b[20];
	int n,r;
	student *p1; 
	p1=h1->next;
	printf("\n\n\t\t\t账户：");
	scanf("%s",a);
	 r=1;
	 while(p1)
	 {
	 if((strcmp(a,(p1->number))!=0))	
	 p1=p1->next;
	 else 
	 {
		n=3;
		r=0;
		while(n)
		{
			
		printf("\t\t\t密码：");
		manager_password(b);
		if(strcmp(b,p1->password)==0)  // 
		{
			printf("\n\t\t\t请稍等，正在登陆···\n");
			Sleep(1000);
			printf("\t\t\t···\n");
			Sleep(1000);
			printf("\t\t\t···\n");
			Sleep(1000);
			printf("\n\t\t\t亲爱的%s 登陆成功！",p1->name);
			printf("\t\t按任意键进入~");
			getch();
			n=0;
			return p1;
		}
		else
		{
			if(n!=1)
			printf("\n\t\t\t(密码错误 您还可以输入%d次)~\n\n",n-1);
			else 
			{
				printf("\n\n\t\t\t登陆失败！!"); 
				printf("\t\t请按任意键重新选择~~");
				getch(); 
				screen_student();
			}
			n--;
		}
	    }
	    break;   //判断账户是否失败 
	  }
    }
    if(r) 
    {
    printf("\t\t\t用户名错误~"); //返回的是登陆学生的节点
	printf("\n\n\t\t\t请重新选择~~");
	Sleep(3000);
	screen_student(); 
    }
}

void password_password_add(char password[])//密码加密 
{
	int k,i;
	k=strlen(password);
	for(i=0;i<k;i++)
	{
		password[i]=password[i]+21;
	}
}

void password_password_pass(char password[])//密码解密 
{
	int k,i;
	k=strlen(password);
	for(i=0;i<k;i++)
	{
		password[i]=password[i]-21;
	}
}

void Save_student(student *h1) //存储学生信息在文件中 
{
	FILE *fp;
	int i;
	student *t=h1->next;
	if((fp=fopen("student.txt","wt"))==NULL)
	{
		printf("\t\t打开失败\n");
		getch();
		exit(1);
	}
	while(t->next)
	{   password_password_add(t->password); 
		fprintf(fp,"%s ",t->name);
		fprintf(fp,"%s ",t->number);
		fprintf(fp,"%s ",t->password); ///// 
		fprintf(fp,"%d ",t->many);
		for(i=0;i<t->many;i++)
		{
			fprintf(fp,"%s ",t->count[i]);  //记录借书的编号 
		}
		fprintf(fp,"%s\n",t->bookdate);
		t=t->next;
	}
	    password_password_add(t->password);
	    fprintf(fp,"%s ",t->name);
		fprintf(fp,"%s ",t->number);
		fprintf(fp,"%s ",t->password);
		fprintf(fp,"%d ",t->many);
		for(i=0;i<t->many;i++)
		{
			fprintf(fp,"%s ",t->count[i]);  //记录借书的编号 
		}
		fprintf(fp,"%s",t->bookdate);                   //读到最后有多余的字符造成一大堆乱码
		t=t->next; 
	fclose(fp);
}

void find_student(book *h,int m)//学生查找图书 按书名 编号 类型 作者 (书籍信息的头节点)选项四项 
{
	book *p;
	int i=0;
	p=h->next;
	char a[20];
	char b[20];
	if(m==1) 
	{
		printf("\n\t\t\t请输入要查找的书名：");
		scanf("%s",&a); 
	}
	else if(m==2) 
	{
		printf("\n\t\t\t请输入要查找的编号：");
		scanf("%s",&a);
	}
	else if(m==3) 
	{
		printf("\n\t\t\t请输入要查找的类型：");
		scanf("%s",&a); 
	}
	else if(m==4) 
	{
		printf("\n\t\t\t请输入要查找的作者：");
		scanf("%s",&a);
	}
	while(p)
	{
		if((strcmp(p->name,a)==0)||(strcmp(p->number,a)==0)||(strcmp(p->sore,a)==0)||(strcmp(p->author,a)==0))
		{
			i=1;
			break;
		}
		p=p->next;
	}
	if(i==1)
	{
		p=h->next;
	printf("\n\t\t\t --------------------------- Welcome 你的查阅结果  --------------------------\n\n"); 
	printf("\t\t\t   编号   书名\t\t作者\t单价\t进书日期\t类别\t库存\t已借\n\n");
	while(p!=NULL)
	{
		if((strcmp(p->name,a)==0)||(strcmp(p->number,a)==0)||(strcmp(p->sore,a)==0)||(strcmp(p->author,a)==0))
		{
			printf("\t\t\t   %s\t",p->number);
			printf("%s\t",p->name);
			printf("%s\t",p->author);
			printf("%.2lf\t",p->price);
			printf("%s\t",p->date);
			printf("%s\t",p->sore);
			printf("%d\t",p->amount);
			printf("%d\t\n",p->borrow);	
		}
			p=p->next;		
	}
    }
    else printf("\n\t\t\t非常抱歉 没有此种书籍~"); 
}

void student_mine(student *p1,book *h)//查看自己的借阅情况  (传入学生的信息，和书信息的头节点)
{
	book *q;
	int i;
	q=h->next;
	if(p1->many==0)
	printf("\n\n\t\t\tdear 您目前没有借书哟~~");
	else
	{
		system("cls");
		printf("\n\n\t\t\t( 此表按书的借阅时间排列 )\n\n");
		printf("\n\n\t\t ———————————————%s同学 你的借阅情况 ————————————————— \n",p1->name);
		printf("\t\t |                                                                                    |\n");
		printf("\t\t |                                                                                     |\n");
	printf("\t\t |   编号       书名\t       作者    单价\t进书日期\t类别\t库存\t已借  |\n");
	printf("\t\t |                                                                                     |\n");
		for(i=0;i<(p1->many);i++)
		{
			q=h->next;
			while(q)
			{
			if(strcmp(q->number,p1->count[i])==0)
			{
	printf("\t\t |   %s\t",q->number);
	printf("%s\t",q->name);
	printf("%s\t",q->author);
	printf("%.2lf\t",q->price);
	printf("%s\t",q->date);
	printf("%s\t",q->sore);
	printf("%d\t",q->amount);
	printf("%d     |\n",q->borrow);
		printf("\t\t |                                                                                     |\n");
			break;
			}
	    	q=q->next; 
			}
		}
	printf("\t\t |                                                                                    |\n");
	 printf("\t\t |                                                               (>已借%d本 可借%d本)    |\n",p1->many,(5-p1->many));
		printf("\t\t ——————————————> Welcome To KuangTu Library <—————————————— \n\n\n");
	}
}

