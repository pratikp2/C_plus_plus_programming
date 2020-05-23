#pragma once
enum class AccountType{SAVINGS, CURRENT};
class Account {
	float m_Balance ;
	int m_No ;
	float m_RateOfInterest ;
	float m_MinBalance ;
	AccountType m_Type ;
public:
	Account(float initialBalance, AccountType type);
	~Account();
	void Withdraw(float amount) ;
	void Deposit(float amount) ;
	float GetBalance() {
		return m_Balance ;
	}
	void AccumulateInterest() ;
};

