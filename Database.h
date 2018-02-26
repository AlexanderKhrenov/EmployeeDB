#pragma once
// Database.h
#include <iostream>
#include <vector>
#include "Employee.h"
using namespace std;

namespace Records
{
	const int kMaxEmployees = 100;
	const int kFirstEmployeeNumber = 1000;

	class Database
	{
	protected:
		vector<Employee> mEmployees;
	
	public:
		Database() {};
		~Database() {};

		Employee& addEmployee(string inFirstName, string inLastName);
		Employee& getEmployee(int inEmployeeNumber);
		Employee& getEmployee(string inFirstName, string inLastName);
		void displayAll();
		void displayCurrent();
		void displayFormer();
	};
}