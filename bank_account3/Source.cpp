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