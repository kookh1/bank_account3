#include<iostream>
#include<cstring>
using namespace std;

/* ��� ���� */
const int NAME_LEN = 20;  //���� �̸�����

enum{MAKE=1, DEPOSIT, WITHDRAW, SHOW, EXIT}; //������� �޴�����

/*���� ��������*/
class Account
{
private:
	int accId;           //����ID
	char *name;          //�� �̸�
	int balance;         //���� �ܾ�

public:
	Account(int accId, char *name, int balance)
		: accId(accId), balance(balance)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	
	Account(const Account &ref)   //���� ������
		: accId(ref.accId), balance(ref.balance)
	{
		this->name = new char[strlen(ref.name) + 1];
		strcpy(this->name, ref.name);
	}

	~Account()
	{
		delete[] name;
	}

	int GetAccId() const //����ID ��ȯ
	{
		return accId;
	}
	
	void SetMoney(int money)   //�Ա� 
	{
		this->balance += money;
	}
	
	int GetMoney(int money)   //���
	{
		if (money > this->balance)
			return -1;

		this->balance -= money;
		return this->balance;
	}

	void ShowAccount() const  //�������� ����
	{
		cout << "����ID: " << this->accId << endl;
		cout << "�̸�: " << this->name << endl;
		cout << "�ܾ�: " << this->balance << endl << endl;
	}
};


class AccountHandler
{
private:
	Account *accArr[100];  //�� �������� ������ ���� ����ü �迭
	int accNum;       //�� ���� ����

public:
	/* ������� ���� ���*/
	AccountHandler();
	~AccountHandler();
	void ShowMenu();       //�޴� ���
	void MakeAccount();    //���� ����
	void Deposit();        //�Ա�
	void Withdraw();       //���
	void ShowAllAccount(); //��ü�� �ܾ���ȸ
};

AccountHandler::AccountHandler() : accNum(0)
{}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}


/* �޴� ���*/
void AccountHandler::ShowMenu()
{
	cout <<endl<< "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl<<endl;
}

/* ���� ���� */
void AccountHandler::MakeAccount()
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


	accArr[accNum++] = new Account(accId, name, balance);
}

/* ��ü�� �ܾ���ȸ */
void AccountHandler::ShowAllAccount()
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccount();
	}
}

/* �Ա� */
void AccountHandler::Deposit()
{
	cout << "[�� ��]" << endl;

	int accId;
	cout << "����ID: ";
	cin >> accId;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == accId)
		{
			int money;
			cout << "�Աݾ�: ";
			cin >> money;

			accArr[i]->SetMoney(money);
			cout << "�ԱݿϷ�" << endl;
			return;
		}
	}
	cout << "�ش� ID�� �������� �ʽ��ϴ�." << endl;
}


/* ��� */
void AccountHandler::Withdraw()
{
	cout << "[�� ��]" << endl;

	int accId;
	cout << "����ID: ";
	cin >> accId;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == accId)
		{
			int money;
			cout << "��ݾ�: ";
			cin >> money;

			if (accArr[i]->GetMoney(money) == -1)  //balance < money ��� -1��ȯ
			{
				cout << "�ܾ׺���" << endl;
				return;
			}
			cout << "��ݿϷ�" << endl;
			return;
		}
	}
	cout << "�ش� ID�� �������� �ʽ��ϴ�." << endl;
}


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