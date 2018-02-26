// DataBaseProgram.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& inDB);
void doFire(Database& inDB);
void doPromote(Database& inDB);
void doDemote(Database& inDB);

int main()
{
	system("chcp 1251");

	Database employeeDB;
	bool done = false;

	while (!done) {
		int selection = displayMenu();

		switch (selection) {
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			doDemote(employeeDB);
			break;
		case 5:
			employeeDB.displayAll();
			break;
		case 6:
			employeeDB.displayCurrent();
			break;
		case 7:
			employeeDB.displayFormer();
			break;
		case 0:
			done = true;
			break;
		default:
			cerr << "����������� �������." << endl;
		}
	}
    return 0;
}

int displayMenu()
{
	int selection;

	cout << endl;
	cout << "���� ������ ��������" << endl;
	cout << "--------------------" << endl;
	cout << "1) - ����� �� ������ ������ ���������" << endl;
	cout << "2) - ���������� ���������" << endl;
	cout << "3)- ��������� ���������" << endl;
	cout << "4) - ��������� ���������" << endl;
	cout << "5) - ������ ���� ��������" << endl;
	cout << "6) - ������ ������� ��������" << endl;
	cout << "7) - ������ ������ ��������" << endl;
	cout << "0) - �����" << endl;
	cout << endl;
	cout << "----> ";

	cin >> selection;

	return selection;
}

void doHire(Database& inDB)
{
	string firstName, lastName;

	cout << "���? ";
	cin >> firstName;
	cout << endl << "�������? ";
	cin >> lastName;
	cout << endl;

	try {
		inDB.addEmployee(firstName, lastName);
	} catch (exception ex) {
		cerr << "�� ������� �������� ����� ������!" << endl;
	}
}

void doFire(Database& inDB)
{
	int employeeNumber;
	cout << "����� ���������? ";
	cin >> employeeNumber;
	cout << endl;

	try {
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.fire();
		cout << "�������� � ������� " << employeeNumber << " ������." << endl;
	} catch (exception ex) {
		cerr << "�� ������� ����������� ���������� ���������!" << endl;
	}
}

void doPromote(Database& inDB)
{
	int employeeNumber, raiseAmount;

	cout << "����� ���������? ";
	cin >> employeeNumber;
	cout << endl << "������ ��������� ������? ";
	cin >> raiseAmount;
	cout << endl;

	try {
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
		cout << "�������� � ������� " << employeeNumber << " �������." << endl;
	}
	catch (exception ex) {
		cerr << "�� ������� ����������� ��������� ���������!" << endl;
	}
}


void doDemote(Database& inDB)
{
	int employeeNumber, loweringAmount;

	cout << "����� ���������? ";
	cin >> employeeNumber;
	cout << endl << "������ ��������� ������? ";
	cin >> loweringAmount;
	cout << endl;

	try {
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.demote(loweringAmount);
		cout << "�������� � ������� " << employeeNumber << " �������." << endl;
	}
	catch (exception ex) {
		cerr << "�� ������� ����������� ��������� ���������!" << endl;
	}
}