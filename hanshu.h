#include<iostream>
using namespace std;
#define Max 1000
#include<string>

//ͨѶ¼�ṹ��
struct Person
{
	string m_name;
	//�Ա�1�У�2Ů
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

//��������
void showmenu();
void addperson(Addressbooks* ab);
void showPerson(Addressbooks* ab);
int isExit(Addressbooks* ab, string name);
void deleteP(Addressbooks* ab);
void findP(Addressbooks* ab);
void modifyP(Addressbooks* ab);
void cleanP(Addressbooks* ab);