#include"library.h"
void book_print(book *h);  //��������
book *book_add(book *h);  //�ϼ�ͼ�� 
book *book_cut(book *h);  //�¼�ͼ��
book *book_sore_number(book *h);  //����ı������  ������� 
void book_sore_borrow(book *h); //ð������ ͼ���������  ������� 
book *book_ni(book *h);  //����ͼ����Ϣ 
void Save_book(book *h); //�洢ͼ����Ϣ���ļ���
book *Open_book(); //���ļ��н���Ϣ����������
void find_student_name(student *h1,int m); //ѧ��������Ϣ ѧ�Ų�ѯ (ѧ����Ϣ�����ͷ�ڵ�) ѡ�� 1.  2.
void find_student_borrow_book(book *h); //��ѯ���н��ȥ���� (�����鼮��Ϣ��ͷ�ڵ�) 

void book_print(book *h)  //�������� 
{
	system("cls");
	book *p;
	p=h->next;
		printf("\n\n\t\t ============================== ���� Library �鵥�� ================================== \n");
		printf("\t\t |                                                                                   |\n");
		printf("\t\t |                                                                                    |\n");
	printf("\t\t |   ���       ����\t        ����    ����\t��������\t���\t���\t�ѽ� |\n");
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
 
book *book_add(book *h)  //�ϼ�ͼ�� 
{
	system("cls");
	book *p,*q,*p1;
	int m,i;
	q=h; 
	printf("\n\n\t\t\t(ÿ������ϼ�10���飬Thinks~)");
	printf("\n\n\t\t\t������Ҫ����ĸ�����");
	scanf("%d",&m);
	printf("\n");
	if(m<=0||m>=10)
	{
	printf("\n\t\t\t��..Dear �����˰�~\n\n"); 
	}
	else
	{
		for(i=0;i<m;i++)  //�������� (p->next->num!=n //����ǰ���)
	{
	p=(book *)malloc(sizeof(book));
	printf("\t\t\t--------------- ������Ҫ�ϼܵĵ�%d���飺---------------\n\n",i+1);
	loop:printf("\t\t\t��ţ�"); 
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
		printf("\t\t\t�������Ѵ��� ����������~\n\n");
	goto loop;	
	}
	printf("\t\t\t������");
	scanf("%s",p->name);
	printf("\t\t\t���ߣ�");
	scanf("%s",p->author);
	printf("\t\t\t���ۣ�");
	scanf("%lf",&p->price);
	printf("\t\t\t��ݣ�"); 
	scanf("%s",p->date);
	printf("\t\t\t���"); 
	scanf("%s",p->sore);
	printf("\t\t\t��棺"); 
	scanf("%d",&p->amount);
	printf("\t\t\t�����"); 
	scanf("%d",&p->borrow);
	 p->next=q->next;
	 q->next=p;
	} 
	printf("\t\t\t-------------------------------------------------------\n",i+1);
	printf("\n\n\t\t\t���Եȣ����ڴ����С�����\n");
			Sleep(1000);
			printf("\t\t\t������\n");
			Sleep(1000);
			printf("\t\t\t������\n");
			Sleep(1000);
	printf("\n\t\t\tdear manager �ѳɹ��ϼ�ͼ�飡");
}
	 return h;
} 

book *book_cut(book *h)  //�¼�ͼ�� 
{
	char n[20];
	book *p,*q;
	p=q=h; //��ʼ��ʱ�򶼵��� h ɾ����һ���ſ��Ը�����whileѭ��������Ըı��Ⱥ��ֵ 
	printf("\t\t\t������Ҫ�¼���ı�ţ�");
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
			printf("\n\t\t\t������%d���ѽ�� �����й黹������¼ܣ�\n",p->borrow);
			printf("\n\t\t\t�������������ѡ��. . .");getch();screen_manager_book();
		}
		
		else
		{
		q->next=p->next;
		free(p);
		printf("\n\n\t\t\t���Եȣ����ڴ����С�����\n");
			Sleep(1000);
			printf("\t\t\t������\n");
			Sleep(1000);
			printf("\t\t\t������\n");
			Sleep(1000);	
		printf("\n\t\t\t%s�����ѳɹ��¼�!"); 
		printf("\t�������������ѡ��~~~~");getch();screen_manager_book();
		}	
	}
	
	else 
	{
	 printf("\n\t\t\tͼ�����������~");
	 printf("\n\n\t\t\t�����˳� ��Ҳ������������ѡ�� ~~~~\n");
	        Sleep(1000);
			printf("\t\t\t������\n");
			Sleep(1000);
			printf("\t\t\t������\n");
			Sleep(1000);	
			;screen_manager_book();	
	}
	return h;
}

book *book_sore_number(book *h)   //����ı������  ������� 
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

void book_sore_borrow(book *h) //ð������ ͼ���������  ������� 
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
		printf("\n\n\t\t ================================ �鵥���а� ========================================= \n");
		printf("\t\t |                                                                                   |\n");
		printf("\t\t |                                                                                    |\n");
	printf("\t\t | ����\t���      ����\t        ����    ����\t��������\t���\t���\t�ѽ� |\n");
	printf("\t\t |                                                                                    |\n");
	while(p)
	{
	if(p->borrow!=q1->borrow)   //�������в��е����� 
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
		printf("\t\t\t�������������ѡ��~~~~");getch();
}

book *book_ni(book *h)  //��������� 
{
   book *p,*q;
   p=h->next;
   h->next=NULL;
   while(p)
   {
   	q=p->next;   //���ֵ�ʱ��Ҫ�洢λ�� 
   	p->next=h->next;
   	h->next=p;
   	p=q;
	}
	return h;
} 

void Save_book(book *h) //�洢ͼ����Ϣ���ļ��� 
{
	FILE *fp;
	book *t=h->next;
	if((fp=fopen("library information.txt","wt"))==NULL){
		printf("\t\t��ʧ��\n");
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
		fprintf(fp,"%d ",t->amount);   //���������ܼӶ�����ַ��Է����ļ���ȡ��Ϣʱ 
		fprintf(fp,"%d",t->borrow);
		t=t->next;                    //��������ж�����ַ����һ�������
	fclose(fp);
}

book *Open_book() //���ļ��н���Ϣ���������� 
{
	FILE *fp;
	book *h,*p,*q1;
	if((fp=fopen("library information.txt","rt"))==NULL){
		printf("\t\t��ʧ��\n");
		getch();
		exit(1);
	}
	h=(book*)malloc(sizeof(book));
	h->next=NULL;
	q1=h;
	while(!feof(fp))  //�ļ���ָ���ΪֹͣѰ�� 
	{
		p=(book*)malloc(sizeof(book));
		fscanf(fp,"%s",p->number);
		fscanf(fp,"%s",p->name);
		fscanf(fp,"%s",p->author);
		fscanf(fp,"%lf",&p->price);  //scanf�� & 
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

void find_student_name(student *h1,int m)//ѧ��������Ϣ ѧ�Ų�ѯ (ѧ����Ϣ�����ͷ�ڵ�) ѡ�� 1.  2. 
{
	char a[20];
	int i;
	student *p;
	p=h1->next;
	if(m==1) 
	{
		printf("\n\t\t\t������Ҫ����ѧ����������");
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
		printf("\n\t\t\t������Ҫ����ѧ����ѧ�ţ�\n");
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
		printf("\n\n\t\t\t-- ���� ---- ѧ�� ------- ע������ ----- ���� ------- ��� --------\n\n"); 
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
	else printf("\n\t\t\t������� ��ѧ�������ڣ�");
	printf("\n\t\t\t�������������ѡ��~~~~");getch();screen_book_borrow();
}

void find_student_borrow_book(book *h)//��ѯ���н��ȥ���� (�����鼮��Ϣ��ͷ�ڵ�)
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
	printf("\n\n\t\t ������������������������������%s ���н��ͼ����Ϣ ������������������������������ \n",p2->name);
		printf("\t\t |                                                                                    |\n");
		printf("\t\t |                                                                                     |\n");
	printf("\t\t |   ���        ����\t        ����    ����\t��������\t���\t���\t�ѽ�  |\n");
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
		printf("\t\t ����������������������������> Welcome To KuangTu Library <���������������������������� \n\n\n");
	}
	else printf("\t\t\t��ʱ�����˽���~~\n"); 
	printf("\n\n\t\t\t�������������ѡ��~~~~");getch();screen_manager_book();
}
