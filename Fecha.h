#pragma once
#include <string>  
#include <sstream>
#include <iostream>
using namespace std;

class Fecha{
private:
	int dia;
	int mes;
	int anno;

public:
	Fecha(int, int, int);
	string toString();

	int getDia();
	int getMes();
	int getAnno();
};

