#include<iostream>
using namespace std;

/* ��� ���� */
const int NAME_LEN = 20;  //���� �̸�����


/*���� ��������*/
struct Account
{
	int accId;           //����ID
	char name[NAME_LEN]; //�� �̸�
	int balance;         //���� �ܾ�
};

Account accArr[100];  //�� �������� ������ ���� ����ü �迭
int accNum = 0;       //�� ���� ����

/* ������� ���� ���*/
void ShowMenu();       //�޴� ���
void MakeAccount();    //���� ����
void Deposit();        //�Ա�
void Withdraw();       //���
void ShowAllAccount(); //��ü�� �ܾ���ȸ


/* �޴� ���*/
void ShowMenu()
{
	cout <<endl<< "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl<<endl;
}

/* ���� ���� */
void MakeAccount()
{
	cout << "[���°���]" << endl;
	
	int accId;
	cout << "����ID: ";
	cin >> accId;

	char name[NAME_LEN];
	cout << "�̸�: ";
	cin >> name;

	int balance;
	cout << "�Աݾ�: ";
	cin >> balance;

	accArr[accNum].accId = accId;
	strcpy_s(accArr[accNum].name, name);
	accArr[accNum].balance = balance;
	accNum += 1;
}

/* ��ü�� �ܾ���ȸ */
void ShowAllAccount()
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "����ID: " << accArr[i].accId << endl;
		cout << "�̸�: " << accArr[i].name << endl;
		cout << "�ܾ�: " << accArr[i].balance << endl<<endl;
	}
}

/* �Ա� */
void Deposit()
{
	cout << "[�� ��]" << endl;

	int accId;
	cout << "����ID: ";
	cin >> accId;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accId == accId)
		{
			int money;
			cout << "�Աݾ�: ";
			cin >> money;

			accArr[i].balance += money;
			return;
		}
	}
	cout << "�ش� ID�� �������� �ʽ��ϴ�." << endl;
}


/* ��� */
void Withdraw()
{
	cout << "[�� ��]" << endl;

	int accId;
	cout << "����ID: ";
	cin >> accId;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accId == accId)
		{
			int money;
			cout << "��ݾ�: ";
			cin >> money;

			accArr[i].balance -= money;
			return;
		}
	}
	cout << "�ش� ID�� �������� �ʽ��ϴ�." << endl;
}


int main()
{
	while (1)
	{
		ShowMenu();   //�޴� ���

		int choice;
		cout << "����: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			MakeAccount();   //���� ����
			break;
		case 2:
			Deposit();       //�Ա�
			break;
		case 3:
			Withdraw();      //���
			break;
		case 4:
			ShowAllAccount(); //��� �������� �޴� ���
			break;
		case 5:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}
		
	}
	return 0;
}