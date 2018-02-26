// Employee.cpp
#include "stdafx.h"
#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

void normalizeString(string& inString)
{
	int spaceCountPrefx;
	int spaceCountPostfx;
	
	string tempString = "";
	
	spaceCountPrefx = 1;
	spaceCountPostfx = 15 - inString.length();
	
	tempString += " ";
	
	tempString += inString;
	
	for (int i = spaceCountPostfx; i > 0; i--) {
		tempString += " ";
	}
	inString = "";
	inString = tempString;
}

namespace Records
{
	Employee::Employee()
	{
		mFirstName = "";
		mLastName = "";
		mEmployeeNumber = -1;
		mSalary = kDefaultStartingSalary;
		fHired = false;
	}

	void Employee::promote(int inRaiseAmount)
	{
		setSalary(getSalary() + inRaiseAmount);
	}

	void Employee::demote(int inDemeritAmount)
	{
		setSalary(getSalary() - inDemeritAmount);
	}

	void Employee::hire()
	{
		fHired = true;
	}
	
	void Employee::fire()
	{
		fHired = false;
	}

	void Employee::display()
	{
		string firstName, lastName;
		firstName = getFirstName();
		lastName = getLastName();
		normalizeString(firstName);
		normalizeString(lastName);

		cout << firstName << "|" << lastName;
		cout << "| " <<(fHired ? "штатный" : "бывший ") << " | ";
		cout << getEmployeeNumber();
		cout << "\t| " << getSalary() << "\t|" << endl;
	}

	// Методы доступа к закрытым членам данных.
	void Employee::setFirstName(string inFirstName)
	{
		if (inFirstName.length() < 16) {
			mFirstName = inFirstName;
		}
		else {
			cerr << "Имя слишком длинное!" << endl;
			throw exception();
		}
	}

	string Employee::getFirstName()
	{
		return mFirstName;
	}

	void Employee::setLastName(string inLastName)
	{
		if (inLastName.length() < 16) {
			mLastName = inLastName;
		}
		else {
			cerr << "Имя слишком длинное!" << endl;
			throw exception();
		}
	}

	string Employee::getLastName()
	{
		return mLastName;
	}

	void Employee::setEmployeeNumber(int inEmployeeNumber)
	{
		mEmployeeNumber = inEmployeeNumber;
	}

	int Employee::getEmployeeNumber()
	{
		return mEmployeeNumber;
	}

	void Employee::setSalary(int inSalary)
	{
		mSalary = inSalary;
	}

	int Employee::getSalary()
	{
		return mSalary;
	}

	bool Employee::getIsHired()
	{
		return fHired;
	}
}