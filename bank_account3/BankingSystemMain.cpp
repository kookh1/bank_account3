#include "AccountHandler.h"
#include "BankingCommonDecl.h"


int main()
{
	AccountHandler manager;
	while (1)
	{
		manager.ShowMenu();   //�޴� ���

		int choice;
		cout << "����: ";
		cin >> choice;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();   //���� ����
			break;
		case DEPOSIT:
			manager.Deposit();       //�Ա�
			break;
		case WITHDRAW:
			manager.Withdraw();      //���
			break;
		case SHOW:
			manager.ShowAllAccount(); //��� �������� �޴� ���
			break;
		case EXIT:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}

	}
	return 0;
}