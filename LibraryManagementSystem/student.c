#include"library.h"

student *creat_student(student *h1,book *h);   //ѧ��ע��  ��Ų����ظ� 
student *change_passworld_student(student *p1);  //ѧ���޸����� 
void print_student(student *h1);  //��������
void return_book(student *p1,book *h); //����  �� ˵��ѧ������Ľڵ� �鼮��Ϣ��ͷ�ڵ� ��
void borrow_book(student *p1,book *h); //����
student *Open_student(); //���ļ��н���Ϣ���������� 
student *student_check(student *h1); //ѧ����½��
void password_password_add(char password[]); //�������
void password_password_pass(char password[]); //������� 
void Save_student(student *h1);  //�洢ѧ����Ϣ���ļ��� 
void find_student(book *h,int m); //ѧ������ͼ�� ������ ��� ���� ���� (�鼮��Ϣ��ͷ�ڵ�)ѡ������ 
void student_mine(student *p1,book *h); //�鿴�Լ��Ľ������  (����ѧ������Ϣ��������Ϣ��ͷ�ڵ�)

 student *creat_student(student *h1,book *h)   //ѧ��ע��  ��Ų����ظ� 
{
	system("cls");
	student *p,*q;
	int i=1,k=2,n,j=1,r;
	char a[20],b[20];
	book *p1;
	p1=h->next; 
	q=h1->next;
	p=(student *)malloc(sizeof(student));
	printf("\n\n\t\t\t---------- ��ӭ����ע����� ----------\n\n"); 
	printf("\t\t\t������");
	scanf("%s",p->name);
	printf("\t\t\tѧ�ţ�");
	scanf("%s",p->number);
	while(q)
	{
		if(strcmp(q->number,p->number)==0)    
		{
		printf("\t\t\t��ѧ���ѱ�ע��~~"); 
		i=0;
		break;
		}
		else q=q->next;	
	}
	if(i)
	{
	printf("\t\t\t������룺");
	manager_password(a);
	loop:printf("\n\t\t\t�ٴ����룺");   //�Ӹ� goto ��䷽�㣡�� 
	manager_password(b);
	if(strcmp(a,b)==0) 
	strcpy(p->password,a);
	else 
	j=0;
		if(j)
		{
			printf("\n\t\t\tע�����ڣ�");
			scanf("%s",p->bookdate);
			loo:printf("\t\t\t������");
			scanf("%d",&p->many);
			if(p->many>5)
			{
				printf("\t\t\tDear �����5����~\n\n"); 
				goto loo; 
			}
			
			for(r=0;r<p->many;r++)
			{
				printf("\t\t\t��ţ�");    
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
						printf("\t\t\t������");
						Sleep(1000);
						printf("\n\t\t\tSorry ���鲻���ڣ�");
						printf("\n\t\t\t������������ȷ���.\n\n");
						r-=1;   //�鲻���ڵö�����һ�� 
				}
				else if(p1->amount==0)
				{
					printf("\n\t\t\tSorry �����治�㣡"); 
					printf("\n\t\t\t������¼�����.\n\n");
					r-=1;
				}
				else
				{
					p1->borrow+=1;  //ֱ����ע���ʱ��ı��� 
					p1->amount-=1;
				}	
			}
			
			p->next=h1->next;
			h1->next=p;	
			printf("\n\t\t\t���Եȣ�����ע�ᡤ����\n");
			Sleep(1000);
			printf("\t\t\t������\n");
			Sleep(1000);
			printf("\t\t\t������\n");
			Sleep(1000);
			printf("\t\t\tDear %sע��ɹ�~",p->name);
			printf("\n\n\n\t\t\t����������غ������µ�½~");
			getch();
			return h1;	
		}
		else if(k) 
		{
			printf("\n\t\t\t(������������벻��ͬ ������������%d��)",k--);
			j=1;
			if(k+1) goto loop;
		} 
	    if(k==0)
		{
		printf("\n\n\t\t�ǳ���Ǹ ���볬ʱ ���Ǽ����˳���ҳ�� ������ѡ������ע��");
		printf("\n\t\t\t���Եȣ������˳�������\n");
			Sleep(1000);
			printf("\t\t\t������\n");
			Sleep(1000);
			printf("\t\t\t������\n");
			Sleep(1000);
		screen_student();
		}
	}
	else
	{
	printf("\n\t\t\t���������������ѡ��~");getch();screen_student();	
	}
}
 
student *change_passworld_student(student *p1)//�޸����� 
{
    char a[20],b[20]; //���ļ���Ϣ����������          //���ҵ�����Ϣͬ�������� ������pָ��û�������� h�� 
	printf("\n\t\t\t�����������룺");    //���ļ��ж�ȡ������ �����������������ͷָ�벻ͬ 
    looi:manager_password(a);
	if(strcmp(a,p1->password)==0)
	{
		printf("\n\t\t\tSorry �����벻�����������ͬ��");
		printf("\n\t\t\t����������\n"); 
		printf("\n\t\t\t��ͬ�������룺");
		goto looi;
	}
	
	printf("\n\t\t\t�ٴ��������룺");
	manager_password(b);
	if(strcmp(a,b)==0)
	{
		strcpy((p1->password),a);   // 
		printf("\n\t\t\t�޸�����ɹ���");
		printf("�����µ�½��");
		Sleep(1000);
			printf("\n\t\t\t������\n");
			Sleep(1000);
			printf("\t\t\t������\n");
			Sleep(1000);
		return p1;
	}
		else 
		{
		printf("\n\t\t\t������������벻��ͬ �޸�ʧ�ܣ�");
		printf("\n\t\t\t���������������ѡ��~");getch();screen_student_book();
		}	
}
 
void print_student(student *h1)  //�������� 
{
	student *p;
	int i;
	p=h1->next;
	printf("\n\n\t\t\t======================================================\n");
	printf("\n\t\t\t����\tѧ��\t\tע������\t����\t���\t\n");
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
 
 void return_book(student *p1,book *h)//����  �� ˵��ѧ������Ľڵ� �鼮��Ϣ��ͷ�ڵ� �� 
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
 	 	printf("\t\t\t�����뻹���ţ�");
 		scanf("%s",a);
 		while(q)
 			{
 			if(strcmp(a,q->number)==0)
 			break;
 			q=q->next;
 			}
 		if(q==NULL)
 		printf("\n\t\t\t��Ŵ��� û�и���~");
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
 					printf("\n\t\t\t���Եȣ����ڰ����С�����\n");
					Sleep(1000);
					printf("\t\t\t������\n");
					Sleep(1000);
					printf("\t\t\t������\n");
					Sleep(1000);
 					printf("\n\t\t\tHellow ����ɹ���");
 				j=0;
 				break;
 				}
 			}
 			if(j)
 			printf("\n\t\t\t��Ǹ ����δ�������~~");
 		}		
 	}

 printf("\n\n\t\t\t�����������~"); getch();screen_student_book();
 }
 
void borrow_book(student *p1,book *h)//���� 
 {
 	system("cls");
 h=book_sore_number(h);
 book_print(h); 
 	char a[20];
 	int i;
 	book *q=h->next;
 	if((p1->many)>=5)
 	{
 		printf("\t\t\tDear ���Ѿ��ﵽ����� ������ѡ������ٽ�~");
 	}
 	else
 	{	printf("\n\t\t\t Dear %s �ѽ�%d�� �ɽ�%d�� ",p1->name,p1->many,(5-p1->many));
 		printf("\t\t\t����������ţ�");
 		scanf("%s",a);
 		while(q)
 		{
 			if(strcmp(a,q->number)==0)
 			break;
 			q=q->next;
 		}
  	 	if(q==NULL)
 		printf("\n\t\t\tSorry��Ŵ��� û�и���~");
 		
 		else
 		{
 			if(q->amount<=0)
 			printf("\n\t\t\tSorry ����Ŀ����Ϊ0 ��ʱ�޷�����. . .");
 			else{
 			 i=p1->many;
 			 strcpy((p1->count[i]),a);
 			 p1->many+=1;
 			 q->amount-=1;
 			 q->borrow+=1;
 			 printf("\n\t\t\t���Եȣ����ڰ����С�����\n");
			 Sleep(1000);
			 printf("\t\t\t������\n");
			 Sleep(1000);
			 printf("\t\t\t������\n");
			 Sleep(1000);
 			 printf("\t\t\tDear �ɹ����飡"); 
 			}
 		}
	}
	printf("\n\n\t\t\t�����������~"); 
	getch();screen_student_book();
}
	

 student *Open_student() //���ļ��н���Ϣ���������� 
{
	FILE *fp;
	student *h1,*p,*p1;
	int i;
	if((fp=fopen("student.txt","rt"))==NULL){
		printf("\t\t��ʧ��\n");
		getch();
		exit(1);
	}
	h1=(student*)malloc(sizeof(student));
	h1->next=NULL;
	p1=h1;
	while(!feof(fp))  //�ļ���ָ���ΪֹͣѰ�� 
	{
		p=(student*)malloc(sizeof(student));
		fscanf(fp,"%s",p->name);
		fscanf(fp,"%s",p->number);
		fscanf(fp,"%s",p->password);
		fscanf(fp,"%d",&p->many);
		password_password_pass(p->password);
		for(i=0;i<p->many;i++)
		{
			fscanf(fp,"%s",p->count[i]);  //��¼����ı�� 
		}
			fscanf(fp,"%s",p->bookdate);
		p1->next=p;
		p1=p;
	}
		p1->next=NULL;
	fclose(fp);
	return h1;
}

student *student_check(student *h1) //ѧ����½�� 
{
	char a[20],b[20];
	int n,r;
	student *p1; 
	p1=h1->next;
	printf("\n\n\t\t\t�˻���");
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
			
		printf("\t\t\t���룺");
		manager_password(b);
		if(strcmp(b,p1->password)==0)  // 
		{
			printf("\n\t\t\t���Եȣ����ڵ�½������\n");
			Sleep(1000);
			printf("\t\t\t������\n");
			Sleep(1000);
			printf("\t\t\t������\n");
			Sleep(1000);
			printf("\n\t\t\t�װ���%s ��½�ɹ���",p1->name);
			printf("\t\t�����������~");
			getch();
			n=0;
			return p1;
		}
		else
		{
			if(n!=1)
			printf("\n\t\t\t(������� ������������%d��)~\n\n",n-1);
			else 
			{
				printf("\n\n\t\t\t��½ʧ�ܣ�!"); 
				printf("\t\t�밴���������ѡ��~~");
				getch(); 
				screen_student();
			}
			n--;
		}
	    }
	    break;   //�ж��˻��Ƿ�ʧ�� 
	  }
    }
    if(r) 
    {
    printf("\t\t\t�û�������~"); //���ص��ǵ�½ѧ���Ľڵ�
	printf("\n\n\t\t\t������ѡ��~~");
	Sleep(3000);
	screen_student(); 
    }
}

void password_password_add(char password[])//������� 
{
	int k,i;
	k=strlen(password);
	for(i=0;i<k;i++)
	{
		password[i]=password[i]+21;
	}
}

void password_password_pass(char password[])//������� 
{
	int k,i;
	k=strlen(password);
	for(i=0;i<k;i++)
	{
		password[i]=password[i]-21;
	}
}

void Save_student(student *h1) //�洢ѧ����Ϣ���ļ��� 
{
	FILE *fp;
	int i;
	student *t=h1->next;
	if((fp=fopen("student.txt","wt"))==NULL)
	{
		printf("\t\t��ʧ��\n");
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
			fprintf(fp,"%s ",t->count[i]);  //��¼����ı�� 
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
			fprintf(fp,"%s ",t->count[i]);  //��¼����ı�� 
		}
		fprintf(fp,"%s",t->bookdate);                   //��������ж�����ַ����һ�������
		t=t->next; 
	fclose(fp);
}

void find_student(book *h,int m)//ѧ������ͼ�� ������ ��� ���� ���� (�鼮��Ϣ��ͷ�ڵ�)ѡ������ 
{
	book *p;
	int i=0;
	p=h->next;
	char a[20];
	char b[20];
	if(m==1) 
	{
		printf("\n\t\t\t������Ҫ���ҵ�������");
		scanf("%s",&a); 
	}
	else if(m==2) 
	{
		printf("\n\t\t\t������Ҫ���ҵı�ţ�");
		scanf("%s",&a);
	}
	else if(m==3) 
	{
		printf("\n\t\t\t������Ҫ���ҵ����ͣ�");
		scanf("%s",&a); 
	}
	else if(m==4) 
	{
		printf("\n\t\t\t������Ҫ���ҵ����ߣ�");
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
	printf("\n\t\t\t --------------------------- Welcome ��Ĳ��Ľ��  --------------------------\n\n"); 
	printf("\t\t\t   ���   ����\t\t����\t����\t��������\t���\t���\t�ѽ�\n\n");
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
    else printf("\n\t\t\t�ǳ���Ǹ û�д����鼮~"); 
}

void student_mine(student *p1,book *h)//�鿴�Լ��Ľ������  (����ѧ������Ϣ��������Ϣ��ͷ�ڵ�)
{
	book *q;
	int i;
	q=h->next;
	if(p1->many==0)
	printf("\n\n\t\t\tdear ��Ŀǰû�н���Ӵ~~");
	else
	{
		system("cls");
		printf("\n\n\t\t\t( �˱���Ľ���ʱ������ )\n\n");
		printf("\n\n\t\t ������������������������������%sͬѧ ��Ľ������ ���������������������������������� \n",p1->name);
		printf("\t\t |                                                                                    |\n");
		printf("\t\t |                                                                                     |\n");
	printf("\t\t |   ���       ����\t       ����    ����\t��������\t���\t���\t�ѽ�  |\n");
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
	 printf("\t\t |                                                               (>�ѽ�%d�� �ɽ�%d��)    |\n",p1->many,(5-p1->many));
		printf("\t\t ����������������������������> Welcome To KuangTu Library <���������������������������� \n\n\n");
	}
}

