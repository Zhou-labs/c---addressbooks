#include"hanshu.h"

//菜单界面
void showmenu()
{
	cout << "***********************" << endl;
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、显示联系人*****" << endl;
	cout << "*****3、删除联系人*****" << endl;
	cout << "*****4、查找联系人*****" << endl;
	cout << "*****5、修改联系人*****" << endl;
	cout << "*****6、清空联系人*****" << endl;
	cout << "*****0、退出通讯录*****" << endl;
	cout << "***********************" << endl;
}
void recordP(Addressbooks* ab)
{
	//姓名
	string name;
	cout << "请输入姓名：" << endl;
	cin >> name;
	ab->personarray[ab->m_size].m_name = name;
	//性别
	int sex = 0;
	while (true)
	{
		cout << "请输入性别，1为男，2为女：" << endl;
		cin >> sex;
		if (sex == 2 || sex == 1)
		{
			ab->personarray[ab->m_size].m_sex = sex;
			break;
		}
		else
		{
			cout << "性别输入有误，请重新输入……" << endl;
		}
	}
	//年龄
	int age = 0;
	cout << "请输入年龄：" << endl;
	cin >> age;
	ab->personarray[ab->m_size].m_age = age;
	//电话
	string phone = "12345678900";
	while (true)
	{
		cout << "请输入电话号码：" << endl;
		cin >> phone;
		if (phone.length() == 11)
		{
			ab->personarray[ab->m_size].m_phone = phone;
			break;
		}
		else
		{
			cout << "请输入正确的电话号码……" << endl;
		}
	}
	//住址
	string address = "北京";
	cout << "请输入住址：" << endl;
	cin >> address;
	ab->personarray[ab->m_size].m_Addr = address;
}
//添加联系人
void addperson(Addressbooks* ab)
{

	if (ab->m_size == Max)
	{
		cout << "通讯录已满，无法添加";
		cout << endl;
	}
	else
	{
		recordP(ab);
		//更新通讯录人数
		ab->m_size++;
		cout << "添加成功！" << endl;
		cout << "当前通讯录人数为：" << ab->m_size;
		//清屏
		system("pause");
		system("cls");
	}
}
//显示联系人
void showPerson(Addressbooks* ab)
{
	if (ab->m_size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < ab->m_size; i++)
		{
			cout << "姓名：" << ab->personarray[i].m_name << "\t";
			cout << "性别：" << ((ab->personarray[i].m_sex == 1) ? "男" : "女") << "\t";
			cout << "年龄：" << ab->personarray[i].m_age << "\t";
			cout << "电话：" << ab->personarray[i].m_phone << "\t";
			cout << "住址：" << ab->personarray[i].m_Addr << endl;
		}
	}
	//清屏
	system("pause");
	system("cls");
}
//检测联系人是否存在
int isExit(Addressbooks* ab, string name)
{
	int m = -1;
	for (int i = 0; i < ab->m_size; i++)
	{
		if (ab->personarray[i].m_name == name)
		{
			//cout << ab->personarray[i].m_name << endl;
			m = i;
			break;
		}
	}
	return m;
}
//删除联系人
void deleteP(Addressbooks* ab)
{
	string nname;
	cout << "请输入需要删除的联系人姓名：";
	cin >> nname;
	int ret = isExit(ab, nname);
	if (ret != -1)
	{
		for (int i = ret; i < (ab->m_size - 1); i++)
		{
			ab->personarray[i] = ab->personarray[i + 1];
		}
		ab->m_size--;
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void findP(Addressbooks* ab)
{
	string nname;
	cout << "请输入需要查找的联系人姓名：";
	cin >> nname;
	int ret = isExit(ab, nname);
	if (ret != -1)
	{
		cout << "姓名：" << ab->personarray[ret].m_name << "\t";
		cout << "性别：" << ((ab->personarray[ret].m_sex == 1) ? "男" : "女") << "\t";
		cout << "年龄：" << ab->personarray[ret].m_age << "\t";
		cout << "电话：" << ab->personarray[ret].m_phone << "\t";
		cout << "住址：" << ab->personarray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//修改联系人
void modifyP(Addressbooks* ab)
{
	string nname;
	cout << "请输入需要修改的联系人姓名：";
	cin >> nname;
	int ret = isExit(ab, nname);
	if (ret != -1)
	{
		//姓名
		ab->personarray[ret].m_name = nname;
		//性别
		int sex = 0;
		while (true)
		{
			cout << "请输入性别，1为男，2为女：" << endl;
			cin >> sex;
			if (sex == 2 || sex == 1)
			{
				ab->personarray[ret].m_sex = sex;
				break;
			}
			else
			{
				cout << "性别输入有误，请重新输入……" << endl;
			}
		}
		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		ab->personarray[ret].m_age = age;
		//电话
		string phone = "12345678900";
		while (true)
		{
			cout << "请输入电话号码：" << endl;
			cin >> phone;
			if (phone.length() == 11)
			{
				ab->personarray[ret].m_phone = phone;
				break;
			}
			else
			{
				cout << "请输入正确的电话号码……" << endl;
			}
		}
		//住址
		string address = "北京";
		cout << "请输入住址：" << endl;
		cin >> address;
		ab->personarray[ret].m_Addr = address;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//清空联系人
void cleanP(Addressbooks* ab)
{
	ab->m_size = 0;
	cout << "通讯录已清空！" << endl;
	system("pause");
	system("cls");
}