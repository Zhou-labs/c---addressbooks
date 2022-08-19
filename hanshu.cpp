#include"hanshu.h"

//�˵�����
void showmenu()
{
	cout << "***********************" << endl;
	cout << "*****1�������ϵ��*****" << endl;
	cout << "*****2����ʾ��ϵ��*****" << endl;
	cout << "*****3��ɾ����ϵ��*****" << endl;
	cout << "*****4��������ϵ��*****" << endl;
	cout << "*****5���޸���ϵ��*****" << endl;
	cout << "*****6�������ϵ��*****" << endl;
	cout << "*****0���˳�ͨѶ¼*****" << endl;
	cout << "***********************" << endl;
}
void recordP(Addressbooks* ab)
{
	//����
	string name;
	cout << "������������" << endl;
	cin >> name;
	ab->personarray[ab->m_size].m_name = name;
	//�Ա�
	int sex = 0;
	while (true)
	{
		cout << "�������Ա�1Ϊ�У�2ΪŮ��" << endl;
		cin >> sex;
		if (sex == 2 || sex == 1)
		{
			ab->personarray[ab->m_size].m_sex = sex;
			break;
		}
		else
		{
			cout << "�Ա������������������롭��" << endl;
		}
	}
	//����
	int age = 0;
	cout << "���������䣺" << endl;
	cin >> age;
	ab->personarray[ab->m_size].m_age = age;
	//�绰
	string phone = "12345678900";
	while (true)
	{
		cout << "������绰���룺" << endl;
		cin >> phone;
		if (phone.length() == 11)
		{
			ab->personarray[ab->m_size].m_phone = phone;
			break;
		}
		else
		{
			cout << "��������ȷ�ĵ绰���롭��" << endl;
		}
	}
	//סַ
	string address = "����";
	cout << "������סַ��" << endl;
	cin >> address;
	ab->personarray[ab->m_size].m_Addr = address;
}
//�����ϵ��
void addperson(Addressbooks* ab)
{

	if (ab->m_size == Max)
	{
		cout << "ͨѶ¼�������޷����";
		cout << endl;
	}
	else
	{
		recordP(ab);
		//����ͨѶ¼����
		ab->m_size++;
		cout << "��ӳɹ���" << endl;
		cout << "��ǰͨѶ¼����Ϊ��" << ab->m_size;
		//����
		system("pause");
		system("cls");
	}
}
//��ʾ��ϵ��
void showPerson(Addressbooks* ab)
{
	if (ab->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < ab->m_size; i++)
		{
			cout << "������" << ab->personarray[i].m_name << "\t";
			cout << "�Ա�" << ((ab->personarray[i].m_sex == 1) ? "��" : "Ů") << "\t";
			cout << "���䣺" << ab->personarray[i].m_age << "\t";
			cout << "�绰��" << ab->personarray[i].m_phone << "\t";
			cout << "סַ��" << ab->personarray[i].m_Addr << endl;
		}
	}
	//����
	system("pause");
	system("cls");
}
//�����ϵ���Ƿ����
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
//ɾ����ϵ��
void deleteP(Addressbooks* ab)
{
	string nname;
	cout << "��������Ҫɾ������ϵ��������";
	cin >> nname;
	int ret = isExit(ab, nname);
	if (ret != -1)
	{
		for (int i = ret; i < (ab->m_size - 1); i++)
		{
			ab->personarray[i] = ab->personarray[i + 1];
		}
		ab->m_size--;
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ��
void findP(Addressbooks* ab)
{
	string nname;
	cout << "��������Ҫ���ҵ���ϵ��������";
	cin >> nname;
	int ret = isExit(ab, nname);
	if (ret != -1)
	{
		cout << "������" << ab->personarray[ret].m_name << "\t";
		cout << "�Ա�" << ((ab->personarray[ret].m_sex == 1) ? "��" : "Ů") << "\t";
		cout << "���䣺" << ab->personarray[ret].m_age << "\t";
		cout << "�绰��" << ab->personarray[ret].m_phone << "\t";
		cout << "סַ��" << ab->personarray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void modifyP(Addressbooks* ab)
{
	string nname;
	cout << "��������Ҫ�޸ĵ���ϵ��������";
	cin >> nname;
	int ret = isExit(ab, nname);
	if (ret != -1)
	{
		//����
		ab->personarray[ret].m_name = nname;
		//�Ա�
		int sex = 0;
		while (true)
		{
			cout << "�������Ա�1Ϊ�У�2ΪŮ��" << endl;
			cin >> sex;
			if (sex == 2 || sex == 1)
			{
				ab->personarray[ret].m_sex = sex;
				break;
			}
			else
			{
				cout << "�Ա������������������롭��" << endl;
			}
		}
		//����
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		ab->personarray[ret].m_age = age;
		//�绰
		string phone = "12345678900";
		while (true)
		{
			cout << "������绰���룺" << endl;
			cin >> phone;
			if (phone.length() == 11)
			{
				ab->personarray[ret].m_phone = phone;
				break;
			}
			else
			{
				cout << "��������ȷ�ĵ绰���롭��" << endl;
			}
		}
		//סַ
		string address = "����";
		cout << "������סַ��" << endl;
		cin >> address;
		ab->personarray[ret].m_Addr = address;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�����ϵ��
void cleanP(Addressbooks* ab)
{
	ab->m_size = 0;
	cout << "ͨѶ¼����գ�" << endl;
	system("pause");
	system("cls");
}