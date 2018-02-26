// Database.cpp
#include "stdafx.h"
#include <iostream>
#include <stdexcept>
#include <string>

#include "Database.h"

using namespace std;

namespace Records
{
	Employee& Database::addEmployee(string inFirstName, string inLastName)
	{
		int databaseSize = mEmployees.size();
		if (databaseSize > kMaxEmployees) {
			cerr << "���������� ������������ ����� �����������!" << endl;
			throw exception();
		}

		Employee theEmployee;
		theEmployee.setFirstName(inFirstName);
		theEmployee.setLastName(inLastName);
		theEmployee.setEmployeeNumber(kFirstEmployeeNumber + databaseSize);
		theEmployee.hire();

		mEmployees.push_back(theEmployee);
		//for (int i = 0; i < databaseSize+1; i++)
		//	cout << mEmployees[i].getEmployeeNumber() << " - " << i << endl;
		return theEmployee;
	}

	Employee& Database::getEmployee(int inEmployeeNumber)
	{
		int positionInDB = inEmployeeNumber - kFirstEmployeeNumber;
		if (positionInDB >= 0 || positionInDB < mEmployees.size()) {
			//cout << mEmployees[positionInDB].getEmployeeNumber() << endl;
			return mEmployees[positionInDB];
		}
		cerr << "� ���� ��� ��������� � ������� " << inEmployeeNumber << endl;
		throw exception();
	}

	Employee& Database::getEmployee(string inFirstName, string inLastName)
	{
		int databaseSize = mEmployees.size();
		for (int i = 0; i < databaseSize; i++) {
			if (mEmployees[i].getFirstName() == inFirstName &&
				mEmployees[i].getLastName() == inLastName) {
				return mEmployees[i];
			}
		}
		cerr << "� ���� ��� ��������� � ������ " << inFirstName << " " << inLastName << endl;
		throw exception();
	}

	void Database::displayAll()
	{
		int databaseSize = mEmployees.size();
		cout << "      ���       |    �������     | ������  | �����\t| �����\t|" << endl;
		for (int i = 0; i < databaseSize; i++) {
			mEmployees[i].display();
		}
	}

	void Database::displayCurrent()
	{
		int databaseSize = mEmployees.size();
		for (int i = 0; i < databaseSize; i++) {
			if (mEmployees[i].getIsHired()) {
				mEmployees[i].display();
			}
		}
	}

	void Database::displayFormer()
	{
		int databaseSize = mEmployees.size();
		for (int i = 0; i < databaseSize; i++) {
			if (!mEmployees[i].getIsHired()) {
				mEmployees[i].display();
			}
		}
	}
}