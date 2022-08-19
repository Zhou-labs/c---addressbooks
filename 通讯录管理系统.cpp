#include<iostream>
using namespace std;
#include<string>
#define Max 1000

#include"hanshu.h";


int main()
{
	int select = 0;
	//创建通讯录
	Addressbooks abs;
	while (true)
	{
		//菜单界面
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
			cout << "欢迎下次使用" << endl;
			system("pause");
			break;
		default:
			break;
		}
	}
	return 0;
}
