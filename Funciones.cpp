#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Funciones.h"

/**
 * Funcion qque muestra los participantes
*/
void Participantes(){
  std::cout << "=== Integrantes ===\n\n";
  std::cout << "  + Jennifer Portiño Fredes\n";
  std::cout << "  + Diego Tapia Leal\n";
  std::cout << "\n";
}

/*
Funcion para ordenar una linea del archivo
@param linea del archivo
*/
std::vector<std::string> obtenerlinea(std::string fila){ 
    std::vector<std::string> arreglo;                           
    std::stringstream ss(fila);                  
    std::string item;
    while (std::getline(ss, item, ';')) {
        item.erase(item.begin()); //Se borra comilla inicio
        std::string dato = item;
        arreglo.push_back(dato);
    }
    return arreglo;
}

/*
Funcion para guardar datos de la venta dentro de la struct venta
@param Vector con datos del estudiante
@return venta llenado
*/
venta guardarVenta(std::vector<std::string> datos){
  venta V; //struct para retornar
  std::string d = datos[0]; //datos[0] es la fecha y hora 2020-10-14 11:07:26.008
  std::string f; //Aqui voy a guardar solo la fecha 2020-10-14

  for(int i = 0; i<10; i++){
    f = f + d[i];
  }
  V.created = f;
  V.sku = atoi(datos[1].c_str());
  V.quantity = atoi(datos[2].c_str());
  V.amount = atof(datos[3].c_str());
  V.name = datos[4];

  return V;
}
/*
Funcion para imprimir el vector por consola
@param Vector a imprimir
*/
void imprimirvector(std::vector<venta> V){
  for(std::size_t i = 0; i < V.size(); i++){
    std::cout <<std::endl<< std::endl;
    std::cout << "Fecha: " << V[i].created << std::endl; 
    std::cout << "Id: " << V[i].sku << std::endl;
    std::cout << "Cantidad: " << V[i].quantity<< std::endl;
    std::cout << "Valor: " << V[i].amount<< std::endl;
    std::cout << "Descripcion: " << V[i].name << std::endl; 
  }
}