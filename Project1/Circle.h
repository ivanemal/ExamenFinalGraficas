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

