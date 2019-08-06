#include"library.h"
void screen_one();
void screen_student();
void screen_manager();
void screen_student_book();
void screen_manager_book();
void screen_book_find_manager();
void screen_book_find_student();
void screen_book_borrow();
void screen_manager_all();

void screen_one()
{
	int i;
	printf("\n\n\t\t\t =========== Welcome ���� ͼ��� ============");
	printf("\n\t\t\t|                                            |\n"); 
	printf("\t\t\t|      1) ����Student                       |");
	printf("\n\t\t\t|                                            |\n"); 
	printf("\t\t\t|      2) ����Manager                       |");
	printf("\n\t\t\t|                                            |\n"); 
	printf("\t\t\t|      0) �˳�                              |");
	printf("\n\t\t\t|                                            |\n"); 
	printf("\t\t\t ============================================\n\n");
	printf("\t\t\t���ѡ��"); 
	scanf("%d",&i);
	while(getchar()!='\n')   
	continue;
	switch(i)
	{
		case 1:screen_student();break;
		case 2:screen_manager();break;
		case 0:printf("\n\t\t\t��ӭ�����´ι��٣���*^_^*��\n");break;
		default :printf("\t\t\t��������ȷ��ѡ�");getch();system("cls");screen_one();break; 
	}
} 

void screen_student()
{
	system("cls");
	int i;
	printf("\n\n\t\t\t =========== Welcome ���� ͼ��� ============");
	printf("\n\t\t\t|                                            |\n"); 
	printf("\t\t\t|      1) Student��½                       |");
	printf("\n\t\t\t|                                            |\n"); 
	printf("\t\t\t|      2) Studentע��                       |");
	printf("\n\t\t\t|                                            |\n"); 
	printf("\t\t\t|      0) ����                              |");
	printf("\n\t\t\t|                                            |\n"); 
	printf("\t\t\t ============================================\n\n");
	printf("\t\t\t���ѡ��"); 
	scanf("%d",&i);
	while(getchar()!='\n')   
	continue;
	switch(i)
	{
		case 1:p1=student_check(h1);screen_student_book();break;
		case 2:h1=creat_student(h1,h);screen_student();break;
		case 0:system("cls");screen_one();break;
		default :printf("\t\t\t��������ȷ��ѡ�");getch();screen_student();break; 
	}
} 

void screen_manager()
{
	system("cls");
	int i;
	printf("\n\n\t\t\t =========== Welcome ���� ͼ��� ============");
	printf("\n\t\t\t|                                            |\n"); 
	printf("\t\t\t|      1) Manager��½                       |");
	printf("\n\t\t\t|                                            |\n"); 
	printf("\t\t\t|      0) ����                              |");
	printf("\n\t\t\t|                                            |\n"); 
	printf("\t\t\t ============================================\n\n");
	printf("\t\t\t���ѡ��"); 
	scanf("%d",&i);   //!!!!!!
	while(getchar()!='\n')   
	continue;
	switch(i)
	{
		case 1:p2=manager_check(h2);screen_manager_book();break;
		case 0:system("cls");screen_one();break;
		default :printf("\t\t\t��������ȷ��ѡ�");getch();screen_manager();break; 
	}
} 

void screen_student_book()
{
	system("cls");
	int i;
	printf("\n\n\t\t\t============== Dear %sͬѧ ===============",p1->name);
	printf("\n\t\t\t|                                           |\n"); 
	printf("\t\t\t|     1.����                               |");
	printf("\n\t\t\t|                                           |\n"); 
	printf("\t\t\t|     2.����                               |");
	printf("\n\t\t\t|                                           |\n"); 
	printf("\t\t\t|     3.�������                           |");
	printf("\n\t\t\t|                                           |\n"); 
	printf("\t\t\t|     4.�鿯����                           |");
	printf("\n\t\t\t|                                           |\n");  
	printf("\t\t\t|     5.��������                           |");
	printf("\n\t\t\t|                                           |\n"); 
	printf("\t\t\t|     6.�޸�����                           |");
	printf("\n\t\t\t|                                           |\n"); 
	printf("\t\t\t|     0.����                               |"); 
	printf("\n\t\t\t|                                           |\n"); 
	printf("\t\t\t============================================\n\n");
	printf("\t\t\t���ѡ��"); 
	scanf("%d",&i);
	while(getchar()!='\n')   
	continue;
	switch(i)
	{
		case 1:borrow_book(p1,h);printf("\n\n\t\t\t�밴���������ѡ��. . .\n");getch();screen_student_book();break;
		case 2:return_book(p1,h);break;
		case 3:student_mine(p1,h);printf("\n\n\t\t\t�밴���������ѡ��. . .\n");getch();screen_student_book();break;
		case 4:screen_book_find_student();break;
		case 5:book_sore_borrow(h);screen_student_book();break;	
		case 6:p1=change_passworld_student(p1);screen_student();break;
		case 0:screen_student();break;
		default :printf("\t\t\t��������ȷ��ѡ�");getch();screen_student_book();break; 
	}
} 

void screen_manager_book()
{
	system("cls");
	int i;
	printf("\n\n\t\t\t============== Hello %s ===============",p2->name);
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|     1.�ϼ�                                |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|     2.�¼�                                |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|     3.����                                |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|     4.��ѯѧ��������Ϣ                    |"); 
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|     5.�ѽ�ͼ����Ϣ��ѯ                    |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|     6.��ʾ����ͼ��                        |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|     7.�޸�����                            |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|     0.����                                |"); 
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t=============================================\n\n");
	printf("\t\t\t���ѡ��"); 
	scanf("%d",&i);
	while(getchar()!='\n')   
	continue;
	switch(i)
	{
		case 1:h=book_add(h);printf(" \n\t\t\t�������������ѡ��~~~~");getch();screen_manager_book();break;
		case 2:h=book_cut(h);break;
		case 3:screen_book_find_manager();break;
		case 4:screen_book_borrow();break;
		case 5:find_student_borrow_book(h);break;
		case 6:screen_manager_all();break;
		case 7:p2=change_passworld_manager(p2);screen_manager();break;
		case 0:screen_manager();break;
		default :printf("\t\t\t��������ȷ��ѡ�");getch();screen_manager_book();break; 
	}
} 

void screen_book_find_manager()
{
	system("cls");
	int i;
	printf("\n\n\t\t\t============= Hello %s ================",p2->name);
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|      1.����                               |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|      2.���                               |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|      3.����                               |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|      4.����                               |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|      0.����                               |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t=============================================\n\n");
	printf("\t\t\t���ѡ��"); 
	scanf("%d",&i);
	while(getchar()!='\n')   
	continue;
	switch(i)
	{
		case 1:case 2:case 3:case 4:find_student(h,i);printf("\n\n\t\t\t�������������ѡ��~~~~");getch();screen_book_find_manager();break;
		case 0:screen_manager_book();break;
		default :printf("\t\t\t��������ȷ��ѡ�");getch();screen_book_find_manager();break; 
	}
} 

void screen_book_find_student()
{
	system("cls");
	int i;
	printf("\n\n\t\t\t============== Dear %sͬѧ ================",p1->name);
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|      1.����                               |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|      2.���                               |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|      3.����                               |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|      4.����                               |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|      0.����                               |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t=============================================\n\n");
	printf("\t\t\t���ѡ��"); 
	scanf("%d",&i);
	while(getchar()!='\n')   
	continue;
	switch(i)
	{
		case 1:case 2:case 3:case 4:find_student(h,i);printf("\n\t\t\t�������������ѡ��~~~~");getch();screen_book_find_student();break;
		case 0:screen_student_book();break;
		default :printf("\t\t\t��������ȷ��ѡ�");getch();screen_book_find_student();break; 
	}
} 

void screen_book_borrow()
{
	system("cls");
	int i;
	printf("\n\n\t\t\t============== Hello %s ===============",p2->name);
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|      1.����                               |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|      2.ѧ��                               |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|      0.����                               |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t=============================================\n\n");
	printf("\t\t\t���ѡ��"); 
	scanf("%d",&i);
	while(getchar()!='\n')   
	continue;
	switch(i)
	{
		case 1:case 2:find_student_name(h1,i);break;
		case 0:screen_manager_book();break;
		default:printf("\t\t\t��������ȷ��ѡ�");getch();screen_book_borrow();break; 
	}
} 

void screen_manager_all()   
{
	system("cls");
	int i;
	printf("\n\n\t\t\t============== Hello %s ===============",p2->name);
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|     1.������������ʾ                      |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|     2.�����������ʾ                      |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|     3.����Ž�����ʾ                      |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t|     0.����                                |");
	printf("\n\t\t\t|                                            |\n");
	printf("\t\t\t=============================================\n\n");
	printf("\t\t\t���ѡ��"); 
	scanf("%d",&i);
	while(getchar()!='\n')   
	continue;
	switch(i)
	{
		case 1:book_sore_borrow(h);screen_manager_all();break;
		case 2:h=book_sore_number(h);book_print(h);printf("\n\t\t\t�������������ѡ��~~~~");getch();screen_manager_all();break;
		case 3:h=book_sore_number(h);h=book_ni(h);book_print(h);printf("\n\t\t\t�������������ѡ��~~~~");getch();screen_manager_all();break;
		case 0:screen_manager_book();break;
		default:printf("\t\t\t��������ȷ��ѡ�");getch();screen_manager_all();break; 
	}
} 
