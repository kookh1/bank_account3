#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

/*���� ��������*/
class Account
{
private:
	int accId;           //����ID
	String name;         //�� �̸�
	int balance;         //���� �ܾ�

public:
	Account(int accId, String name, int balance);
	
	int GetAccId() const; //����ID ��ȯ
	virtual void SetMoney(int money) = 0;   //�Ա� 
	int GetMoney(int money);   //���
	virtual void ShowAccount() const = 0;  //�������� ����
};

#endif
