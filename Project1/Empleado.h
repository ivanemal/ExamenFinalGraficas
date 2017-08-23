#pragma once
#include <string>

<<<<<<< HEAD
class Empl
=======
class Empleado 
>>>>>>> 8e5786a592fb9d60e4d553378e6c58f9088267a5
{
private:
	int _id;
	std::string _firstName;
	std::string _lastName;
	int _salary;
public:
<<<<<<< HEAD
	Employee(int id, std::string firstName, std::string lastName, int salary);
=======
	Empleado(int id, std::string firstName, std::string lastName, int salary);
>>>>>>> 8e5786a592fb9d60e4d553378e6c58f9088267a5
	int GetId();
	std::string GetFirstName();
	std::string GetLastName();
	int GetSalary();
	void SetSalary(int salary);
	int GetAnnualSalary();
	int RaiseSalary(int percent);
	std::string Print();

};

