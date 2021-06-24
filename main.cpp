#include <iostream>
#include <cstdlib>
#include <fstream> //libreria para leer archivo
#include <string> //libreria para string
#include <vector> //libreria para vector
#include "Funciones.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        std::vector<venta> V; //Vector que almacena las ventas
        std::string Archivo(argv[1]); //Archivo que hay que leer 
        std::ifstream lectura(Archivo); //Lectura
        std::vector<std::string> datos;
        venta dato;

        if(lectura){
            for(std::string linea; getline (lectura, linea);){
                if(linea != "created;sku;quantity;amount;name"){
                    datos = obtenerlinea(linea);
                    dato = guardarVenta(datos);
                    V.push_back(dato);
                    datos.clear(); 
                }
            }
        }
        imprimirvector(V);
    } 
    else {
        // Mostrar los integrantes
        Participantes();
    }
    return EXIT_SUCCESS;
}