// Melanie Vértiz Jiménez A01169675 




#include <iostream>
#include "InputFIle.h" // Llamar a la clase creada 
#include "Prueba.txt"

int main(int argc, char*argv[])
{
	
	std::string filename = “Prueba.txt”;
	InputFile myFile;
	myFile.Read(filename);
	std::string _contents = myFile.GetContents();
	std::cout << “Contents: ” << _contents << std::endl;	std::cin; 	return 0; 

}
 