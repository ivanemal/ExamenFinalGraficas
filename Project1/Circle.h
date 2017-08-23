<<<<<<< HEAD
#pragma once
#include <string>

class Circle
{
private:
	double _radius;
	std::string _color;


public:
	Circle();
	Circle(double r);
	double GetRadius();
	double GetArea();


};
=======
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Circle
{
public:
	Circle();
	~Circle();
	double _radius = 1.0; 
	string _color = "red"; 

	double GetRadius(double r) {
		r = _radius; 
		return r; 
	}
	double GetArea(double r) {		double a = 3.1416*(r*r); 		return a; 	}
}

>>>>>>> 8e5786a592fb9d60e4d553378e6c58f9088267a5
