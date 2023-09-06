#include "Cliente.h"
#include <string.h>

/// Constructores
Cliente::Cliente() : numeroCuenta(0), apellidoPaterno(""), primerNombre(""), saldo(0) {}
Cliente::Cliente(int valorNumeroCuenta, string valorPrimerNombre, string valorApellidoPaterno, double valorSaldo) {
    setNumeroCuenta(valorNumeroCuenta);
    setPrimerNombre(valorPrimerNombre);
    setApellidoPaterno(valorApellidoPaterno);
    setSaldo(valorSaldo);
}

/// Setters
void Cliente::setNumeroCuenta(int valorNumeroCuenta) {numeroCuenta = valorNumeroCuenta;}
void Cliente::setApellidoPaterno(string valorApellidoPaterno) {
    if (valorApellidoPaterno.length() >= MAXAPELLIDO) {
        throw std::invalid_argument("Apellido excede la longitud máxima permitida");
    } else {
        strcpy(this->apellidoPaterno, valorApellidoPaterno.c_str());
    }
}
void Cliente::setPrimerNombre(string valorPrimerNombre) {
    if (valorPrimerNombre.length() >= MAXAPELLIDO) {
        throw std::invalid_argument("Apellido excede la longitud máxima permitida");
    } else {
        strcpy(this->primerNombre, valorPrimerNombre.c_str());
    }
}
void Cliente::setSaldo(double valorSaldo) {saldo = valorSaldo;}

/// Getters
int Cliente::getNumeroCuenta() {return numeroCuenta;}
string Cliente::getApellidoPaterno() {return string(apellidoPaterno);}
string Cliente::getPrimerNombre() {return string(primerNombre);}
double Cliente::getSaldo() {return saldo;}
