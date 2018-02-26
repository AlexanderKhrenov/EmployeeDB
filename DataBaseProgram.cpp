// DataBaseProgram.cpp: определяет точку входа для консольного приложения.
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
			cerr << "Неизвестная команда." << endl;
		}
	}
    return 0;
}

int displayMenu()
{
	int selection;

	cout << endl;
	cout << "База Данных Служащих" << endl;
	cout << "--------------------" << endl;
	cout << "1) - Прием на работу нового служащего" << endl;
	cout << "2) - Увольнение служащего" << endl;
	cout << "3)- Повышение служащего" << endl;
	cout << "4) - Понижение служащего" << endl;
	cout << "5) - Список всех служащих" << endl;
	cout << "6) - Список штатных служащих" << endl;
	cout << "7) - Список бывших служащих" << endl;
	cout << "0) - Выход" << endl;
	cout << endl;
	cout << "----> ";

	cin >> selection;

	return selection;
}

void doHire(Database& inDB)
{
	string firstName, lastName;

	cout << "Имя? ";
	cin >> firstName;
	cout << endl << "Фамилия? ";
	cin >> lastName;
	cout << endl;

	try {
		inDB.addEmployee(firstName, lastName);
	} catch (exception ex) {
		cerr << "Не удается добавить новую запись!" << endl;
	}
}

void doFire(Database& inDB)
{
	int employeeNumber;
	cout << "Номер служащего? ";
	cin >> employeeNumber;
	cout << endl;

	try {
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.fire();
		cout << "Служащий с номером " << employeeNumber << " уволен." << endl;
	} catch (exception ex) {
		cerr << "Не удается реализовать увольнение служащего!" << endl;
	}
}

void doPromote(Database& inDB)
{
	int employeeNumber, raiseAmount;

	cout << "Номер служащего? ";
	cin >> employeeNumber;
	cout << endl << "Размер повышения оклада? ";
	cin >> raiseAmount;
	cout << endl;

	try {
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
		cout << "Служащий с номером " << employeeNumber << " повышен." << endl;
	}
	catch (exception ex) {
		cerr << "Не удается реализовать повышение служащего!" << endl;
	}
}


void doDemote(Database& inDB)
{
	int employeeNumber, loweringAmount;

	cout << "Номер служащего? ";
	cin >> employeeNumber;
	cout << endl << "Размер понижения оклада? ";
	cin >> loweringAmount;
	cout << endl;

	try {
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.demote(loweringAmount);
		cout << "Служащий с номером " << employeeNumber << " понижен." << endl;
	}
	catch (exception ex) {
		cerr << "Не удается реализовать понижение служащего!" << endl;
	}
}