#ifndef MATERIAL_H  
#define MATERIAL_H  

#include <string>  
#include <iostream>  
using namespace std;  

class Material {  
private:  
   string codigo;  
   string titulo;  
   bool disponible;  

public:  
   Material(string numeroClasificacion, int numeroCatalogo, string titulo, string autor, string palabraClave, string tipo, bool estado);  
   Material(string codigo, string titulo);

   string getCodigo();  
   string getTitulo();  
   bool isDisponible();  

   void setTitulo(string tit);  
   void setDisponible(bool disp);  

   virtual void mostrarInformacion() const; // Cambiado a virtual y const  
};  

#endif