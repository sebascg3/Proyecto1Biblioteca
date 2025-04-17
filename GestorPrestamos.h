#pragma once  
#include<iostream>  
#include<sstream>  
using namespace std;  

class GestorPrestamos {  
private:  
   string fPrestamo;  
   string fDevolucion;  
   bool retrasado;  

public:  
   GestorPrestamos(string fP, string fD, bool ret); 
   string getfechaP();  
   string getfechaD();  
   void setFechaP(string);  
   void setFechaD(string);  
   bool getRet();  
   void setRet(bool);  
};