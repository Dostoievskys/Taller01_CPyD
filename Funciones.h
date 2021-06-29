#ifndef FUNCIONES_H
#define FUNCIONES_H

struct venta{
    std::string created;//Fecha de compra 2020-10-14
    int sku;//identificador de producto
    int quantity;//cantidad adquirida
    float amount;//valor de los productos adquiridos (en CLP)
    std::string name;//indica el nombre del producto y sirve de descripción
};

struct datos{
    int fecha;//Fecha de compra 20201014  de tipo entero
    int cantVentas;//cantidad de ventas en ese dia
};

void Participantes();
std::vector<std::string> obtenerlinea(std::string);
venta guardarVenta(std::vector<std::string>);
void imprimirvector(std::vector<venta>);
int cambioFecha( std::string str);
# endif