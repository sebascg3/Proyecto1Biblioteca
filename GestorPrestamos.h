#pragma once  
#include "Fecha.h"
#include<iostream>  
#include<sstream>  
using namespace std;  

class GestorPrestamos {  
private:  
   Fecha* fPrestamo;  
   Fecha* fDevolucion;
   bool retrasado;  

public:  
   GestorPrestamos(Fecha* fP, Fecha* fD, bool ret);
   Fecha* getfechaP();
   Fecha* getfechaD();
   void setFechaP(Fecha*);
   void setFechaD(Fecha*);
   bool getRet();  
   void setRet(bool);  
};