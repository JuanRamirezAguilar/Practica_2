#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#include "Cliente.h"

using namespace std;


int main () {
    // Variables auxiliares
    int numeroCuenta;
    char apellido[MAXAPELLIDO];
    char primerNombre[MAXNOMBRE];
    double saldo;
    Cliente c; // Objeto o registro cliente
    ofstream archivoCreditoSalida;

    archivoCreditoSalida.open("credito.dat", ios::binary);
    // Salir del programa si ofstream no puede abrir el archivo
    if (!archivoCreditoSalida) {
        cerr << "No se puede abrir el archivo" <<endl;
        exit(1);
    }

    cout << "Escriba el numero de cuenta (del 1 al 100 para terminar la entrada)" <<endl;
    cin >> numeroCuenta;
    c.setNumeroCuenta(numeroCuenta);

    // El usuario proporciona la informacion que se guarda en el archivo
    while (c.getNumeroCuenta() >= 1 && c.getNumeroCuenta() <= 100) {
        cout << "Teclea apellido, primer nombre, saldo" <<endl;
        cin >> setw(15) >> apellido;
        cin >> setw(10) >> primerNombre;
        cin >> saldo;

        // Establecer los valores apellido, primer nombre y saldo
        c.setApellidoPaterno(apellido);
        c.setPrimerNombre(primerNombre);
        c.setSaldo(saldo);

        // Buscar la pocicion el el archivo del registro especificado
        archivoCreditoSalida.seekp((c.getNumeroCuenta() - 1) * int(sizeof(Cliente))); // Aqui hize un casteo por
                                                                                      // un warning del compilador
        // Escribir la informacion especificada por el usuario en el archivo
        archivoCreditoSalida.write(reinterpret_cast<const char*>(&c), sizeof(Cliente));

        // Permitir que el usuario especifique otro numero de cuenta
        cout << "Escriba el numero de cuenta (de 1 a 100, o 0 para terminar el programa): ";
        cin >> numeroCuenta;
        c.setNumeroCuenta(numeroCuenta); 
    }
    archivoCreditoSalida.close();

    return 0;
}