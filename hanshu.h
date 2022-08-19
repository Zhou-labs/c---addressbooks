#include<iostream>
using namespace std;
#define Max 1000
#include<string>

//通讯录结构体
struct Person
{
	string m_name;
	//性别1男，2女
	int m_sex;
	int m_age;
	string m_phone;
	string m_Addr;
};
struct Addressbooks
{
	Person personarray[Max];
	int m_size = 0;
};

//函数声明
void showmenu();
void addperson(Addressbooks* ab);
void showPerson(Addressbooks* ab);
int isExit(Addressbooks* ab, string name);
void deleteP(Addressbooks* ab);
void findP(Addressbooks* ab);
void modifyP(Addressbooks* ab);
void cleanP(Addressbooks* ab);