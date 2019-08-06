#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include <Windows.h>

typedef struct BOOK
{
	char number[20];  //��� 
    char name[20];    //���� 
    char author[20];  //���� 
    double price;     //���� 
    char date[20];    //�������� 
    char sore[20];    //���� 
    int amount;       //��� 
    int borrow;
    struct BOOK *next;
}book;

typedef struct STUDENT
{
	char name[20];
	char number[20];
	char password[20]; 
	char bookdate[20];
	int many;    //����ı��� 
	char count[5][20];    //һ��ѧ��ֻ�ܽ� 5���� 
	struct STUDENT *next; 
 }student;

typedef struct MANAGER
{
	char name[20];   //���� 
	char number[20];   //�˺� 
	char password[20];   //���� 
	struct MANAGER *next;
 }manager;
 
void book_print(book *h);  //��������
book *book_add(book *h);  //�ϼ�ͼ�� 
book *book_cut(book *h);  //�¼�ͼ��
book *book_sore_number(book *h);  //����ı������  ������� 
void book_sore_borrow(book *h); //ð������ ͼ���������  ������� 
book *book_ni(book *h);
void Save_book(book *h); //�洢ͼ����Ϣ���ļ���
book *Open_book(); //���ļ��н���Ϣ����������
void find_student_name(student *h1,int m); //ѧ��������Ϣ ѧ�Ų�ѯ (ѧ����Ϣ�����ͷ�ڵ�) ѡ�� 1.  2.
void find_student_borrow_book(book *h); //��ѯ���н��ȥ���� (�����鼮��Ϣ��ͷ�ڵ�)


manager *Open_manager(); //���ļ��н���Ϣ����������
manager *manager_check(manager *h2); //����Ա��½
manager *change_passworld_manager(manager *p2);//�޸�����
void Save_manager(manager *h2); //�洢����Ա��Ϣ���ļ���
void manager_password(char password[]);  //����Ա�������� 


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
  
  book *h; 
student *h1,*p1;
manager *h2,*p2;

