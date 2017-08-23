// Melanie Vértiz Jiménez A01169675 



#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
// Ejercicio 1 
int PerimetroRectangulo(int base, int altura) {
	
	int p = 2*(base + altura);
	return p;
}
// Ejercicio 2
float AreaTriangulo(float base, float altura) {
	int at = (base*altura) / 2;
	return at; 



}
// Ejercicio 3 
int Mayor(int numero1, int numero2, int numero3) {
	int mayor;
	if (numero1 > numero2, numero1 > numero3)  mayor = numero1; 
	else if (numero2 > numero1, numero2 > numero3) mayor = numero2; 
	else if (numero3 > numero2, numero3 > numero1) mayor = numero3;
	return  mayor; 
}
// Ejercicio 4  
int Menor(int numero1, int numero2, int numero3) {
	int menor;
	if (numero1 < numero2, numero1 < numero3)  menor = numero1;
	else if (numero2 < numero1, numero2 < numero3) menor = numero2;
	else if (numero3 < numero2, numero3 < numero1) menor = numero3;
	return  menor;
}
// Ejercicio 5
void FilaEstrellas(int n) { 
	int counter = 0;
	while (counter != n) {
		if (counter == n - 1)
		{
			std::cout << "*" << std::endl;
		}
		else {
			std::cout << "*";
		}
		counter++;
	}

}

//Ejercicio 6
void MatrizEstrellas(int n)
{
	int counter = 0;
	while (counter != n) {
		int columnas = 0;
		while ( columnas != n) {
			if (columnas == n - 1)
			{
				std::cout << "*" << std::endl;
			}
			else {
				std::cout << "*";
			}
			columnas++;
		}
		counter++;
	}
}

//Ejercicio 7
void PiramideEstrellas(int n)
{

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			std::cout << "*";
		}
		std::cout << "\n";
	}

}

//Ejercicio 8
void FlechaEstrellas(int n)
{
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
	for (int i = n - 1; i >= 1; --i) {
		for (int j = 1; j <= i; ++j) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
}

//Ejercicio 9
void Fibonacci(int n)
{
	int counter = 1;
	int fib = 1;
	int a = 1;
	int b = 1;
	std::cout << "0 ";
	std::cout << a << " ";
	while (counter != n) {
		std::cout << fib << " ";
		fib = a + b;
		a = b;
		b = fib;
		counter++;

		if (counter == n) {
			std::cout << "\n";
		}
	}

}

//Ejercicio 10
bool EsPrimo(int numero)
{

	int a = 0;
	for (int i = 1; i < (numero + 1); i++) {
		if (numero %i == 0) {
			a++;
		}
	}
	if (a != 2) {
		std::cout << "No es primo " << "\n";
	}
	else {
		std::cout << "Si es primo " << "\n";
	}
	return 0;
}



int main(){

	// Ejercicio 1 
		cout << "Obtengamos el perimetro de un rectangulo\n";
		cin.get();
		int p = PerimetroRectangulo(5, 3);
		cout << "El perimetro es " << p << " \n";
		cin.get();
	// Ejercicio 2
		cout << "Obtengamos el area de un triangulo\n";
		cin.get();
		int at = AreaTriangulo(5, 8);
		cout << "El area es " << at << " \n";
		cin.get();
	// Ejercicio 3
		cout << "Obtengamos el numero mayor\n";
		cin.get();
		int mayor = Mayor (3, 6,5);
		cout << "El mayor es " << mayor << " \n";
		cin.get();
	// Ejercicio 4
		cout << "Obtengamos el numero menor\n";
		cin.get();
		int menor = Menor(3, 6, 5);
		cout << "El mayor es " << menor << " \n";
		cin.get();
	// Ejercicio 5 
		cout << "Imprimamos estrellas\n";
		cin.get(); 
		FilaEstrellas(9); 
	//Ejercicio 6
		cout << "Imprimamos una matriz de estrellas\n";
		cin.get();
		MatrizEstrellas(7);
	//Ejercicio 7 
		cout << "Imprimamos una piramide de estrellas\n";
		cin.get();
		PiramideEstrellas(8);
	//Ejercicio 8
		cout << "Imprimamos una flecha de estrellas\n";
		cin.get();
		FlechaEstrellas(10);
	//Ejercicio 9 
		cout << "Imprimamos la serie de Fibonacci \n";
		cin.get();
		Fibonacci(1);
	//Ejercicio 10 
		cout << "Veamos si tu numero es primo\n";
		cin.get();
		EsPrimo(63);
		cin.get();
		return 0;
}
