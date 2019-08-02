#include "Account.h"
#include <stdexcept>


Account::Account(float initialBalance, AccountType type) {
	m_Balance = initialBalance ;
	m_Type = type ;
	switch (type) {
	case AccountType::SAVINGS:
		m_RateOfInterest = 0.04f ;
		m_MinBalance = 100 ;
		break ;
	case AccountType::CURRENT:
		m_RateOfInterest = 0 ;
		m_MinBalance = 500 ;
		break ;
	}
}

void Account::Withdraw(float amount) {
	if(amount > m_Balance)
		throw std::runtime_error{"Insufficient balance"} ;
	switch (m_Type) {
	case AccountType::SAVINGS:
		m_Balance-= amount ;
		if(m_Balance < m_MinBalance) {
			
		}
		break; ;
	case AccountType::CURRENT:
		m_Balance-= amount ;
		if(m_Balance < m_MinBalance) {
			
		}
		break ;
	}
}

void Account::Deposit(float amount) {
	m_Balance += amount ;
}

void Account::AccumulateInterest() {
	switch (m_Type) {
	case AccountType::SAVINGS:
		m_Balance += (m_Balance * m_RateOfInterest) ;

		break; ;
	case AccountType::CURRENT:
		break ;
	}
}

Account::~Account()
{
}
