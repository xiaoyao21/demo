#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include <Windows.h>

typedef struct BOOK
{
	char number[20];  //编号 
    char name[20];    //书名 
    char author[20];  //作者 
    double price;     //单价 
    char date[20];    //上书日期 
    char sore[20];    //分类 
    int amount;       //库存 
    int borrow;
    struct BOOK *next;
}book;

typedef struct STUDENT
{
	char name[20];
	char number[20];
	char password[20]; 
	char bookdate[20];
	int many;    //借书的本书 
	char count[5][20];    //一个学生只能借 5本书 
	struct STUDENT *next; 
 }student;

typedef struct MANAGER
{
	char name[20];   //姓名 
	char number[20];   //账号 
	char password[20];   //密码 
	struct MANAGER *next;
 }manager;
 
void book_print(book *h);  //链表的输出
book *book_add(book *h);  //上架图书 
book *book_cut(book *h);  //下架图书
book *book_sore_number(book *h);  //按书的编号排序  不带输出 
void book_sore_borrow(book *h); //冒泡排序 图书借阅排行  不带输出 
book *book_ni(book *h);
void Save_book(book *h); //存储图书信息在文件中
book *Open_book(); //从文件中将信息加入链表中
void find_student_name(student *h1,int m); //学生借阅信息 学号查询 (学生信息链表的头节点) 选择 1.  2.
void find_student_borrow_book(book *h); //查询所有借出去的书 (传入书籍信息的头节点)


manager *Open_manager(); //从文件中将信息加入链表中
manager *manager_check(manager *h2); //管理员登陆
manager *change_passworld_manager(manager *p2);//修改密码
void Save_manager(manager *h2); //存储管理员信息在文件中
void manager_password(char password[]);  //管理员密码输入 


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
  
  book *h; 
student *h1,*p1;
manager *h2,*p2;

