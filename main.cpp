#include <iostream>
#include <cstdlib>
#include <fstream> //libreria para leer archivo
#include <string> //libreria para string
#include <vector> //libreria para vector
#include "Funciones.h"

/*
Compilacion: 
./ruta/bin/programa datosPrueba.csv
./ruta/bin/programa datos.csv
*/

int main(int argc, char** argv) {
    if (argc > 1) {
        std::vector<venta> V; //Vector que almacena las ventas
        std::string Archivo(argv[1]); //Archivo que hay que leer 
        std::ifstream lectura(Archivo); //Lectura
        std::vector<std::string> datos;
        std::vector<FechaV> FechaVentas; 
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
        FechaVentas = FuncionOrdenar(V);
        //imprimirvectorF(FechaVentas);
        //imprimirvector(V);
        Participantes();
        CalculoPendiente(V,FechaVentas);
        
        
    } 
    else {
        // Mostrar los integrantes
        Participantes();
    }
    return EXIT_SUCCESS;
}