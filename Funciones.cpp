#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include<algorithm>
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
*Funcion para ordenar una linea del archivo
*@param linea del archivo
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
*Funcion para guardar datos de la venta dentro de la struct venta
*@param Vector con datos del estudiante
*@return venta llenado
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
*Funcion para imprimir el vector tipo venta por consola
*@param Vector a imprimir
*/
void imprimirvector(std::vector<venta> V){
  for(std::size_t i = 0; i < V.size(); i++){
    std::cout <<std::endl;
    //std::cout << "i: " << i << std::endl;
    std::cout << "Fecha: " << V[i].created << std::endl; 
    std::cout << "Id: " << V[i].sku << std::endl;
    std::cout << "Cantidad: " << V[i].quantity<< std::endl;
    std::cout << "Valor: " << V[i].amount<< std::endl;
    std::cout << "Descripcion: " << V[i].name << std::endl; 
  }
}
/*
*Funcion para imprimir el vector tipo FechaV por consola
*@param Vector a imprimir
*/
void imprimirvectorF(std::vector<FechaV> F){
  for(std::size_t i = 0; i < F.size(); i++){
    std::cout <<std::endl;
    std::cout << "Id: " << F[i].id << std::endl; //Id del dia
    std::cout << "Fecha: " << F[i].fecha<< std::endl; 
    std::cout << "Cantidad: " << F[i].cantVentas << std::endl; 
  }
}
/**
 *Funcion para remover el caracter '-' de la fecha
 *@params string fecha
 *@return fecha como un int 
*/
int cambioFecha(std::string str){
  int fechaI;
  str.erase(remove(str.begin(), str.end(), '-'), str.end());
  fechaI=stoi(str);
  return fechaI;
}
/*
*Funcion para agregar datos
*@param Vector tipo venta
*@return vector tipo Fechav 
*/
std::vector<FechaV> FuncionOrdenar(std::vector<venta>V){
  std::string aux;
  int cont=0, contID=0;
  FechaV D;
  std::vector<FechaV> X;
  int fecha;
  for(std::size_t i=0; i<V.size()-1;i++){
    aux=V[i].created;
    if(aux==V[i+1].created){
      cont++;
      if(i+1 == V.size()-1){
        cont++;
        contID++;
        aux=V[i+1].created;
        fecha=cambioFecha(aux);//string a int eliminando "-"
        D.fecha=fecha;
        D.cantVentas=cont;
        D.id=contID;
        X.push_back(D);
      }
    }
    else{
      cont++;
      contID++;
      D.cantVentas=cont;
      fecha=cambioFecha(aux);//string a int eliminando "-"
      D.fecha=fecha;
      D.id=contID;
      X.push_back(D);
      cont=0;
      aux=V[i+1].created;
      if(i+1 == V.size()-1){
        contID++;
        aux=V[i+1].created;
        fecha=cambioFecha(aux);//string a int eliminando "-"
        D.fecha=fecha;
        D.cantVentas=1;
        D.id=contID;
        X.push_back(D);
      }
    }
  }
  return X;
}
/**
 * Funcion para calcular la pendiente
 * @param Vector tipo venta 
 * @param Vector tipo FechaV
*/
void CalculoPendiente(std::vector<venta>V, std::vector<FechaV> F){
  std::size_t n = V.size();
  int SumaXY=0, SumaX=0, SumaY=0, SumaX2=0, SumaXX=0, xy=0, x2=0;
  double Pendiente=0.0, numerador=0.0, denominador=0.0;

  for(std::size_t i=0; i< F.size();i++){
    xy = F[i].id * F[i].cantVentas;
    SumaXY = SumaXY + xy; //Suma(xy + xy + ...)
    SumaX = SumaX + F[i].id; //Suma(F.id + F.id + ...)
    SumaY = SumaY + F[i].cantVentas; //Suma(F.cant + F.cant + ...)
    x2 = F[i].id * F[i].id;
    SumaX2 = SumaX2 + x2; //Suma(x^2) = Suma((f.id)^2+(f.id)^2+...)
    SumaXX = SumaX*SumaX; //(Suma(x))^2 = ( suma(f.id+f.id+...) )^2
  }
  numerador = (n*SumaXY)-(SumaX*SumaY);
  denominador = (n*SumaX2)-SumaXX;
  Pendiente = numerador/denominador;
  /*std::cout << "xy: " << xy << std::endl;
  std::cout << "SumaXY: " << SumaXY << std::endl;
  std::cout << "SumaX: " << SumaX << std::endl;
  std::cout << "SumaY: " << SumaY << std::endl;
  std::cout << "x2: " << x2 << std::endl;
  std::cout << "SumaX2: " << SumaX2 << std::endl;
  std::cout << "SumaXX: " << SumaXX << std::endl;
  std::cout << "n: " << n << std::endl;
  std::cout << "numerador: " << numerador << std::endl;
  std::cout << "denominador: " << denominador << std::endl;
  std::cout << "Pendiente: " << Pendiente << std::endl;*/
  CalculoIntercepto(F,Pendiente);
}
/**
 * Funcion para calcular el intercepto
 * @param Vector tipo FechaV
 * @param pendiente calculada anteriormente
*/
void CalculoIntercepto(std::vector<FechaV> F, double P){
  int sumX=0, sumY=0, cont=0;
  double PromX=0.0,PromY=0.0, intercepto=0.0;
  
  for(std::size_t i=0; i< F.size();i++){
    cont++;
    sumX = sumX + F[i].id;
    sumY = sumY + F[i].cantVentas;
  }
  PromX = sumX/cont;
  PromY = sumY/cont;

  intercepto = PromY - (P*PromX);
  Formula(P,intercepto);
}
/**
 * Funcion para mostrar la formula
 * @param pendiente
 * @param intercepto
*/
void Formula(double P, double I){
  std::cout <<std::endl;
  std::cout << "Venta = Fecha * " << P << " + " << I << std::endl; //Id del dia
  std::cout << std::endl << "Considere fecha como un numero entero, donde el valor 1 es 2020-10-14 \n" << std::endl; 
}