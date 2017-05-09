#include<iostream>
#include<cstring>
using namespace std;

/* ��� ���� */
const int NAME_LEN = 20;  //���� �̸�����

enum{MAKE=1, DEPOSIT, WITHDRAW, SHOW, EXIT}; //������� �޴�����

enum{NORMAL=1, CREDIT};   //�������� ���� 

enum{LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};  //�ſ�ŷ� ��� �� ������ ����


/*���� ��������*/
class Account
{
private:
	int accId;           //����ID
	char *name;          //�� �̸�
	int balance;         //���� �ܾ�

public:
	Account(int accId, char *name, int balance);
	Account(const Account &ref);
	~Account();

	int GetAccId() const; //����ID ��ȯ
	virtual void SetMoney(int money)=0;   //�Ա� 
	int GetMoney(int money);   //���
	virtual void ShowAccount() const = 0;  //�������� ����
};

/*���� ��������*/
class NormalAccount : public Account
{
private:
	int ratio;   //����
public:
	NormalAccount(int accId, char *name, int balance, int ratio)
		: Account(accId, name, balance), ratio(ratio)
	{}
	
	virtual void SetMoney(int money)
	{
		Account::SetMoney(money);   //�Աݾ�
		Account::SetMoney((int)money*(ratio / 100.0));  //�Աݾ� * ����
	}

	virtual void ShowAccount() const
	{
		Account::ShowAccount();
		cout << "����: " << ratio << endl;
	}
};

/*�ſ� ��������*/
class HighCreditAccount : public NormalAccount
{
private:
	int specialRatio;   //�߰� ����
public:
	HighCreditAccount(int accId, char *name, int balance, int ratio, int special)
		: NormalAccount(accId, name, balance, ratio), specialRatio(special)
	{}

	virtual void SetMoney(int money)
	{
		NormalAccount::SetMoney(money);   //�Աݾ�
		Account::SetMoney((int)money*(specialRatio / 100.0));  //�Աݾ� * ����
	}

	virtual void ShowAccount() const
	{
		NormalAccount::ShowAccount();
		cout << "�߰�����: " << specialRatio << endl << endl;
	}
};


Account::Account(int accId, char *name, int balance)
	: accId(accId), balance(balance)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Account::Account(const Account &ref)   //���� ������
	: accId(ref.accId), balance(ref.balance)
{
	this->name = new char[strlen(ref.name) + 1];
	strcpy(this->name, ref.name);
}

Account::~Account()
{
	delete[] name;
}

int Account::GetAccId() const //����ID ��ȯ
{
	return accId;
}

void Account::SetMoney(int money)   //�Ա� 
{
	this->balance += money;
}

int Account::GetMoney(int money)   //���
{
	if (money > this->balance)
		return -1;

	this->balance -= money;
	return this->balance;
}

void Account::ShowAccount() const  //�������� ����
{
	cout << "����ID: " << this->accId << endl;
	cout << "�̸�: " << this->name << endl;
	cout << "�ܾ�: " << this->balance << endl;
}


/*���� ���������� ó��*/

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

	void MakeNormalAccount();  //������� ����
	void MakeHighCreditAccount(); //�ſ���� ����
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
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	
	int choice;
	cout << "����: ";
	cin >> choice;

	if (choice == NORMAL)
	{
		MakeNormalAccount();
	}
	else if (choice == CREDIT)
	{
		MakeHighCreditAccount();
	}
}


void  AccountHandler::MakeNormalAccount()  //������� ����
{
	cout << "[���뿹�ݰ��� ����]" << endl;
	int accId;
	cout << "����ID: ";
	cin >> accId;

	char name[NAME_LEN];
	cout << "�̸�: ";
	cin >> name;

	int balance;
	cout << "�Աݾ�: ";
	cin >> balance;

	int ratio;
	cout << "����: ";
	cin >> ratio;

	accArr[accNum++] = new NormalAccount(accId, name, balance, ratio);
}

void  AccountHandler::MakeHighCreditAccount() //�ſ�ŷڰ��� ����
{
	cout << "[�ſ�ŷڰ��� ����]" << endl;
	int accId;
	cout << "����ID: ";
	cin >> accId;

	char name[NAME_LEN];
	cout << "�̸�: ";
	cin >> name;

	int balance;
	cout << "�Աݾ�: ";
	cin >> balance;

	int ratio;
	cout << "����: ";
	cin >> ratio;

	int level;
	cout << "�ſ���(1toA, 2toB, 3toC): ";
	cin >> level;

	switch(level)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(accId, name, balance, ratio, LEVEL_A);
		break;

	case 2:
		accArr[accNum++] = new HighCreditAccount(accId, name, balance, ratio, LEVEL_B);
		break;

	case 3:
		accArr[accNum++] = new HighCreditAccount(accId, name, balance, ratio, LEVEL_C);
		break;
	}
}

/* ��ü�� �ܾ���ȸ */
void AccountHandler::ShowAllAccount()
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccount();
		cout << endl;
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