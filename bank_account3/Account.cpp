#include "Account.h"
#include "BankingCommonDecl.h"

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

