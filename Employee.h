// Employee.h
#pragma once

#include <iostream>
using namespace std;

namespace Records 
{
	const int kDefaultStartingSalary = 30000;

	class Employee
	{
	private:
		string	mFirstName;
		string	mLastName;
		int		mEmployeeNumber;
		int		mSalary;
		bool	fHired;
	
	public:
		Employee();

		void	promote(int inRaiseAmount = 1000);
		void	demote(int inDemeritAmount = 1000);
		void	hire();	// прием служащего на работу
		void	fire();	// увольнение служащего
		void	display();	// отображение информации о служащем

		void	setFirstName(string inFirstName);
		string	getFirstName();
		void	setLastName(string inLastName);
		string	getLastName();
		void	setEmployeeNumber(int inEmployeeNumber);
		int		getEmployeeNumber();
		void	setSalary(int inSalary);
		int		getSalary();
		bool	getIsHired();
	};
}

