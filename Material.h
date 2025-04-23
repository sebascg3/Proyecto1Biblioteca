#ifndef MATERIAL_H  
#define MATERIAL_H  

#include <string>  
#include <sstream>
#include <iostream>  
using namespace std; 

#include "ObjetoBase.h"

class Material : public ObjetoBase {  
private:  
   string codigo;  
   string titulo;  
   bool disponible; 
   int numeroCatalogo;
   string autor;
   string palabraClave;
   string tipo;


public:  
   Material(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado);  
   Material(string codigo, string titulo);

   string getCodigo();  
   string getTitulo();  
   bool isDisponible();
   string getNumeroCatalogo();
   string getTipo();
   string getAutor();
   string getPalabraClave();

   void setTitulo(string tit);  
   void setDisponible(bool disp);  

   virtual string toString() const;
};  

#endif