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
/* Ejercicio 5
void FilaEstrellas(int n) { 
	cin >>  n; 
	while (n=>0) cout
} 

Preguntar como almacenar los caracteres en arrays*/


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

		return 0;
}
