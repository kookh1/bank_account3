#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

/*���� ��������*/
class NormalAccount : public Account
{
private:
	int ratio;   //����
public:
	NormalAccount(int accId, String name, int balance, int ratio)
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

#endif