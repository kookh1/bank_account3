#ifndef HIGH_CREDIT_ACCOUNT_H__
#define HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

/*�ſ� ��������*/
class HighCreditAccount : public NormalAccount
{
private:
	int specialRatio;   //�߰� ����
public:
	HighCreditAccount(int accId, String name, int balance, int ratio, int special)
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

#endif