#include<iostream>
using namespace std;
#include<string>
#define Max 1000

#include"hanshu.h";


int main()
{
	int select = 0;
	//����ͨѶ¼
	Addressbooks abs;
	while (true)
	{
		//�˵�����
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deleteP(&abs);
			break;
		case 4:
			findP(&abs);
			break;
		case 5:
			modifyP(&abs);
			break;
		case 6:
			cleanP(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			break;
		default:
			break;
		}
	}
	return 0;
}
