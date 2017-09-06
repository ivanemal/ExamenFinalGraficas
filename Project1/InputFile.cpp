#include "InputFile.h"
#include <fstream>
#include <sstream>
bool InputFile::Read(std::string filename)
{
	std::fstream ifile(filename, std::fstream::in);
	if (ifile.is_open()) {
		std::stringstream archivo; 
		archivo << ifile.rdbuf();
		_contents = archivo.str(); 
	}
	else {
		return false; 
	}
}

std::string InputFile::GetContents()
{
	return _contents; 
}
