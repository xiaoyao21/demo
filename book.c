#include"library.h"
void book_print(book *h);  //链表的输出
book *book_add(book *h);  //上架图书 
book *book_cut(book *h);  //下架图书
book *book_sore_number(book *h);  //按书的编号排序  不带输出 
void book_sore_borrow(book *h); //冒泡排序 图书借阅排行  不带输出 
book *book_ni(book *h);  //逆置图书信息 
void Save_book(book *h); //存储图书信息在文件中
book *Open_book(); //从文件中将信息加入链表中
void find_student_name(student *h1,int m); //学生借阅信息 学号查询 (学生信息链表的头节点) 选择 1.  2.
void find_student_borrow_book(book *h); //查询所有借出去的书 (传入书籍信息的头节点) 

void book_print(book *h)  //链表的输出 
{
	system("cls");
	book *p;
	p=h->next;
		printf("\n\n\t\t ============================== 狂兔 Library 书单表 ================================== \n");
		printf("\t\t |                                                                                   |\n");
		printf("\t\t |                                                                                    |\n");
	printf("\t\t |   编号       书名\t        作者    单价\t进书日期\t类别\t库存\t已借 |\n");
	printf("\t\t |                                                                                    |\n");
	while(p)
	{
	printf("\t\t |   %s\t",p->number);
	printf("%s\t",p->name);
	printf("%s\t",p->author);
	printf("%.2lf\t",p->price);
	printf("%s\t",p->date);
	printf("%s\t",p->sore);
	printf("%d\t",p->amount);
	printf("%d    |\n",p->borrow);
		printf("\t\t |                                                                                    |\n");
		p=p->next;
	}
	 printf("\t\t |                                                                                   |\n");
		printf("\t\t ===================================================================================== \n\n\n");
 } 
 
book *book_add(book *h)  //上架图书 
{
	system("cls");
	book *p,*q,*p1;
	int m,i;
	q=h; 
	printf("\n\n\t\t\t(每次最多上架10本书，Thinks~)");
	printf("\n\n\t\t\t请输入要上书的个数：");
	scanf("%d",&m);
	printf("\n");
	if(m<=0||m>=10)
	{
	printf("\n\t\t\t嗯..Dear 你点错了吧~\n\n"); 
	}
	else
	{
		for(i=0;i<m;i++)  //向其后插入 (p->next->num!=n //向其前面插)
	{
	p=(book *)malloc(sizeof(book));
	printf("\t\t\t--------------- 请输入要上架的第%d本书：---------------\n\n",i+1);
	loop:printf("\t\t\t编号："); 
	scanf("%s",p->number);
	p1=h->next;
	while(p1)
	{
		if(strcmp(p1->number,p->number)!=0)
		p1=p1->next;
		else break;
	}
	if(p1!=NULL)
	{
		printf("\t\t\t该书编号已存在 请重新输入~\n\n");
	goto loop;	
	}
	printf("\t\t\t书名：");
	scanf("%s",p->name);
	printf("\t\t\t作者：");
	scanf("%s",p->author);
	printf("\t\t\t单价：");
	scanf("%lf",&p->price);
	printf("\t\t\t年份："); 
	scanf("%s",p->date);
	printf("\t\t\t类别："); 
	scanf("%s",p->sore);
	printf("\t\t\t库存："); 
	scanf("%d",&p->amount);
	printf("\t\t\t借出："); 
	scanf("%d",&p->borrow);
	 p->next=q->next;
	 q->next=p;
	} 
	printf("\t\t\t-------------------------------------------------------\n",i+1);
	printf("\n\n\t\t\t请稍等，正在处理中···\n");
			Sleep(1000);
			printf("\t\t\t···\n");
			Sleep(1000);
			printf("\t\t\t···\n");
			Sleep(1000);
	printf("\n\t\t\tdear manager 已成功上架图书！");
}
	 return h;
} 

book *book_cut(book *h)  //下架图书 
{
	char n[20];
	book *p,*q;
	p=q=h; //开始的时候都等于 h 删除第一个才可以跟上在while循环里面可以改变先后的值 
	printf("\t\t\t请输入要下架书的编号：");
	scanf("%s",n);
	
	while(p)
	{
		if((strcmp(p->number,n)!=0))
		{
		q=p; 
		p=p->next;	
		}
		else break;
	}
	if(p!=NULL) 
	{
		if(p->borrow!=0)
		{
			printf("\n\t\t\t该书有%d本已借出 请所有归还完后再下架！\n",p->borrow);
			printf("\n\t\t\t按任意键后重新选择. . .");getch();screen_manager_book();
		}
		
		else
		{
		q->next=p->next;
		free(p);
		printf("\n\n\t\t\t请稍等，正在处理中···\n");
			Sleep(1000);
			printf("\t\t\t···\n");
			Sleep(1000);
			printf("\t\t\t···\n");
			Sleep(1000);	
		printf("\n\t\t\t%s号书已成功下架!"); 
		printf("\t按任意键后重新选择~~~~");getch();screen_manager_book();
		}	
	}
	
	else 
	{
	 printf("\n\t\t\t图书编号输入错误~");
	 printf("\n\n\t\t\t正在退出 您也继续可以重新选择 ~~~~\n");
	        Sleep(1000);
			printf("\t\t\t···\n");
			Sleep(1000);
			printf("\t\t\t···\n");
			Sleep(1000);	
			;screen_manager_book();	
	}
	return h;
}

book *book_sore_number(book *h)   //按书的编号排序  不带输出 
{
	book *q1,*q2,*p3,*end,*t; 
	end=NULL;
	q1=h;
	while((h->next)!=end)
	{
		for(q1=h,q2=q1->next,p3=q2->next;p3!=end;q1=q1->next,q2=q2->next,p3=p3->next)
		{
			if(strcmp(q2->number,p3->number)>0)
			{
				q1->next=p3;
				q2->next=p3->next;
				p3->next=q2;
				t=p3;
				p3=q2;
				q2=t;
			}
		}
		end=q2;
	}
	return h;
}

void book_sore_borrow(book *h) //冒泡排序 图书借阅排行  不带输出 
{
	book *q1,*q2,*p3,*end,*t,*p;
	int i,j;
	i=j=1;
	end=NULL;
	q1=h;
	while((h->next)!=end)
	{
		for(q1=h,q2=q1->next,p3=q2->next;p3!=end;q1=q1->next,q2=q2->next,p3=p3->next)
		{
			if(q2->borrow<p3->borrow)
			{
				q1->next=p3;
				q2->next=p3->next;
				p3->next=q2;
				t=p3;
				p3=q2;
				q2=t;
			}
		}
		end=q2;
	}
	p=q1=h->next;
	system("cls");
		printf("\n\n\t\t ================================ 书单排行榜 ========================================= \n");
		printf("\t\t |                                                                                   |\n");
		printf("\t\t |                                                                                    |\n");
	printf("\t\t | 排名\t编号      书名\t        作者    单价\t进书日期\t类别\t库存\t已借 |\n");
	printf("\t\t |                                                                                    |\n");
	while(p)
	{
	if(p->borrow!=q1->borrow)   //还可以有并列的名次 
		i=j;     
		j++;
	printf("\t\t |   %d\t",i); 
	printf("%s\t",p->number);
	printf("%s\t",p->name);
	printf("%s\t",p->author);
	printf("%.2lf\t",p->price);
	printf("%s\t",p->date);
	printf("%s\t",p->sore);
	printf("%d\t",p->amount);
	printf("%d    |\n",p->borrow);
		printf("\t\t |                                                                                    |\n");
		q1=p;
		p=p->next;
	}
	   printf("\t\t |                                                                                   |\n");
		printf("\t\t ===================================================================================== \n\n\n");
		printf("\t\t\t按任意键后重新选择~~~~");getch();
}

book *book_ni(book *h)  //链表的逆置 
{
   book *p,*q;
   p=h->next;
   h->next=NULL;
   while(p)
   {
   	q=p->next;   //放手的时候要存储位置 
   	p->next=h->next;
   	h->next=p;
   	p=q;
	}
	return h;
} 

void Save_book(book *h) //存储图书信息在文件中 
{
	FILE *fp;
	book *t=h->next;
	if((fp=fopen("library information.txt","wt"))==NULL){
		printf("\t\t打开失败\n");
		getch();
		exit(1);
	}
	while(t->next){
		fprintf(fp,"%s ",t->number);
		fprintf(fp,"%s ",t->name);
		fprintf(fp,"%s ",t->author);
		fprintf(fp,"%.2lf ",t->price);
		fprintf(fp,"%s ",t->date);
		fprintf(fp,"%s ",t->sore);
		fprintf(fp,"%d ",t->amount);
		fprintf(fp,"%d\n",t->borrow);
		t=t->next;
	}
	    fprintf(fp,"%s ",t->number);
		fprintf(fp,"%s ",t->name);
		fprintf(fp,"%s ",t->author);
		fprintf(fp,"%.2lf ",t->price);
		fprintf(fp,"%s ",t->date);
		fprintf(fp,"%s ",t->sore);
		fprintf(fp,"%d ",t->amount);   //链表的最后不能加多余的字符以防从文件读取信息时 
		fprintf(fp,"%d",t->borrow);
		t=t->next;                    //读到最后有多余的字符造成一大堆乱码
	fclose(fp);
}

book *Open_book() //从文件中将信息加入链表中 
{
	FILE *fp;
	book *h,*p,*q1;
	if((fp=fopen("library information.txt","rt"))==NULL){
		printf("\t\t打开失败\n");
		getch();
		exit(1);
	}
	h=(book*)malloc(sizeof(book));
	h->next=NULL;
	q1=h;
	while(!feof(fp))  //文件流指向空为停止寻找 
	{
		p=(book*)malloc(sizeof(book));
		fscanf(fp,"%s",p->number);
		fscanf(fp,"%s",p->name);
		fscanf(fp,"%s",p->author);
		fscanf(fp,"%lf",&p->price);  //scanf加 & 
		fscanf(fp,"%s",p->date);
		fscanf(fp,"%s",p->sore);
		fscanf(fp,"%d",&p->amount);
		fscanf(fp,"%d",&p->borrow);
		q1->next=p;
		q1=p;
	}
	q1->next=NULL;
	fclose(fp);
	return h;
}

void find_student_name(student *h1,int m)//学生借阅信息 学号查询 (学生信息链表的头节点) 选择 1.  2. 
{
	char a[20];
	int i;
	student *p;
	p=h1->next;
	if(m==1) 
	{
		printf("\n\t\t\t请输入要查找学生的姓名：");
		scanf("%s",a);
		while(p)
		{
			if(strcmp(a,p->name)!=0)
			p=p->next; 
			else break;
		}
	}
	else if(m==2)	
	{
		printf("\n\t\t\t请输入要查找学生的学号：\n");
		scanf("%s",a);
		while(p)
		{
			if(strcmp(a,p->number)!=0)
			p=p->next;
			else break;
		}	
	}
	if(p)
	{
		printf("\n\n\t\t\t-- 姓名 ---- 学号 ------- 注册日期 ----- 数量 ------- 书号 --------\n\n"); 
		printf("\n\t\t\t   %s",p->name);
		printf("\t   %s",p->number);
		printf("\t  %s",p->bookdate);
		printf("\t  %d",p->many);
		for(i=0;i<p->many;i++)
		{
			printf("\t%s",p->count[i]);
		}
	printf("\n");
	}
	else printf("\n\t\t\t输入错误 该学生不存在！");
	printf("\n\t\t\t按任意键后重新选择~~~~");getch();screen_book_borrow();
}

void find_student_borrow_book(book *h)//查询所有借出去的书 (传入书籍信息的头节点)
{
	book *p;
	int i=0;
	p=h->next;
	while(p)
	{
	  if(p->borrow!=0)
	  {
	  	i=1;
	  	break;
	  }	
	  p=p->next;
	} 
	if(i)
	{
		system("cls");
		p=h->next;
	printf("\n\n\t\t ———————————————%s 所有借出图书信息 ——————————————— \n",p2->name);
		printf("\t\t |                                                                                    |\n");
		printf("\t\t |                                                                                     |\n");
	printf("\t\t |   编号        书名\t        作者    单价\t进书日期\t类别\t库存\t已借  |\n");
	printf("\t\t |                                                                                     |\n");
		while(p)
		{
			if(p->borrow!=0)
			{
			printf("\t\t |   %s\t",p->number);
	printf("%s\t",p->name);
	printf("%s\t",p->author);
	printf("%.2lf\t",p->price);
	printf("%s\t",p->date);
	printf("%s\t",p->sore);
	printf("%d\t",p->amount);
	printf("%d     |\n",p->borrow);
		printf("\t\t |                                                                                     |\n");
			}
			p=p->next;
		} 
		printf("\t\t |                                                                                    |\n");
		printf("\t\t ——————————————> Welcome To KuangTu Library <—————————————— \n\n\n");
	}
	else printf("\t\t\t暂时并无人借书~~\n"); 
	printf("\n\n\t\t\t按任意键后重新选择~~~~");getch();screen_manager_book();
}
