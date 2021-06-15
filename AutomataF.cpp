#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

// ESTADOS

enum class Estado {INICIO, Q1, Q2, ENTERO, REAL, NO_RECONOCIDO}; // Transiciones CONSTANTES

Estado reconocerNumero(const string& inputString); // Regresa un estaado

// INICIO 
int main() {
    cout << "Automata que reconoce numero {0,1,2,3,4,5,6,7,8,9} " << endl;
    string inputString;
    cin >> inputString;
    Estado ultimo = reconocerNumero(inputString);
    if (ultimo == Estado::ENTERO) {
        cout << "La cadena ingresada es un numero" << endl;
    } else if (ultimo == Estado::REAL) {
        cout << "La cadena ingresada es un numero con decimales" << endl;
    } else {
        cout << "La cadena ingresada no es aceptada por el automata" << endl;
    }

    cout << endl;
    system("pause");
    system("cls");
    main(); // recursividad al main, no funciona con while xD

    return 0;
}

Estado reconocerNumero(const string& inputString)
{
    unsigned int pos = 0; // estado inicial
    Estado actual = Estado::INICIO;
    bool cadenaRechazada = false;
    while (not cadenaRechazada and pos < inputString.length()) {
        char simbolo = inputString[pos];
        switch (actual) {
        case Estado::INICIO:
            if (isdigit(simbolo)) {
                actual = Estado::ENTERO;
            } else if (simbolo == '+' or simbolo == '-') {
                actual = Estado::Q1;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q1:
            if (isdigit(simbolo)) {
                actual = Estado::ENTERO;
            } else if (simbolo == '.') {
                actual = Estado::Q2;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::Q2:
            if (isdigit(simbolo)) {
                actual = Estado::REAL;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::ENTERO:
            if (isdigit(simbolo)) {
                actual = Estado::ENTERO;
            } else if (simbolo == '.') {
                actual = Estado::Q2;
            } else {
                cadenaRechazada = true;
            }
            break;
        case Estado::REAL:
            if (isdigit(simbolo)) {
                actual = Estado::REAL;
            } else {
                cadenaRechazada = true;
            }
            break;
        }
        pos++; // aumenta el estado inicial
    }
    if (cadenaRechazada) {
        return Estado::NO_RECONOCIDO;
    }
    return actual;
}