// Melanie Vértiz Jiménez A01169675 



#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int PerimetroRectangulo(int base, int altura) {
	
	int p = 2*(base + altura);
	return p;
}
int main(){


		cout << "Obtengamos el perimetro de un rectangulo\n";
		cin.get();
		int p = PerimetroRectangulo(5, 6);
		cout << "El perimetro es " << p << " \n";
				
}
