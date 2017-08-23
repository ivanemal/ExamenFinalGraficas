#pragma once
#include <string>

class Empleado 
{
private:
	int _id;
	std::string _firstName;
	std::string _lastName;
	int _salary;
public:
	Empleado(int id, std::string firstName, std::string lastName, int salary);
	int GetId();
	std::string GetFirstName();
	std::string GetLastName();
	int GetSalary();
	void SetSalary(int salary);
	int GetAnnualSalary();
	int RaiseSalary(int percent);
	std::string Print();

};

