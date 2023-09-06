#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
using std::string;

#define MAXAPELLIDO 15
#define MAXNOMBRE 10

class Cliente {
    private:
        /// Atributos
        int numeroCuenta;
        char apellidoPaterno[MAXAPELLIDO];
        char primerNombre[MAXNOMBRE];
        double saldo;

    public:
        /// Constructores
        Cliente();
        Cliente(int, string, string, double);
        /// Setters
        void setNumeroCuenta(int);
        void setApellidoPaterno(string);
        void setPrimerNombre(string);
        void setSaldo(double);
        /// Getters
        int getNumeroCuenta();
        string getApellidoPaterno();
        string getPrimerNombre();
        double getSaldo();
};

#endif