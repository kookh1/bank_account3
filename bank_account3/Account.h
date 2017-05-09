#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

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
	Account& operator=(const Account& ref);
	~Account();

	int GetAccId() const; //����ID ��ȯ
	virtual void SetMoney(int money) = 0;   //�Ա� 
	int GetMoney(int money);   //���
	virtual void ShowAccount() const = 0;  //�������� ����
};

#endif
