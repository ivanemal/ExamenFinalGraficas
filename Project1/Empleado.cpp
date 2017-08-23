#include "Empleado.h"

Empleado::Empleado(int id, std::string firstName, std::string lastName, int salary)
{
}

int Empleado::GetId()
{
	return _id;
}

std::string Empleado::GetFirstName()
{
	return _firstName;
}

std::string Empleado::GetLastName()
{
	return _lastName;
}

int Empleado::GetSalary()
{
	return _salary;
}

void Empleado::SetSalary(int salary)
{
	_salary = salary;
}

int Empleado::GetAnnualSalary()
{
	return _salary * 12;
}

int Empleado::RaiseSalary(int percent)
{
	_salary = _salary * 1.0f + (float)(percent / 100.0f);
	return _salary;
}

std::string Empleado::Print()
{
	return "Empleado [" + std::to_string(_id) + ", name = " + GetLastName + "," + _salary + "]";


}
