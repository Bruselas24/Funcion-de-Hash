#include <iostream>
//Libreria para usar la funcion "Ceil" para redondear numeros para arriba
#include <cmath>

using namespace std;

/*Funcion de Hash que devuelve los numeros centrales de un entero
Dado K > 10
========================================================================
En caso de que el numero resultante del cuadrado de K tenga 3 digitos
la funcion retornara los primeros 2 digitos
========================================================================
En caso de que el numero resulatnte del cuadrado de K tenga una cantidad
de digitos par retornara los 2 numeros centrales
========================================================================
En caso de que el numero resultante del cuadrado de k tenga una cantidad
de digitos impar retornara los 3 numeros centrales
*/
string funcionDeHash(int numero){
    //Declaramos un string que contendra el cuadrante de K como string
    //para posteriormente usar el metodo ".length" para saber la
    //cantidad de digitos
    string numeroCuadrado = to_string(numero*numero);
    //Variable auxiliar que nos ayudara a hacer los condicionales
    float longitud = numeroCuadrado.length();
    longitud /= 2;

    //Retorno de la funcion
    string resp;

    //Caso de que el numero tenga 3 digitos
    if(numeroCuadrado.length() <= 3){

        //Añadimos los dos primeros digitos
        resp = numeroCuadrado[0];
        resp += numeroCuadrado[1];

    }//Caso en el que la cantidad de digitos es par
    else if( longitud == ceil(longitud) ){

        //Añadimos los 2 digitos centrales
        resp = numeroCuadrado[longitud - 1];
        resp += numeroCuadrado[longitud];

    }//Caso en el que la cantidad de digitos es impar
    else{

        //Añadimos los 3 digitos centrales
        int primerNumero = ceil(longitud);
        resp = numeroCuadrado[primerNumero-2];
        resp += numeroCuadrado[primerNumero-1];
        resp += numeroCuadrado[primerNumero];
    }
    //devolvemos el resultado
    return resp;
}

int main() {

    int k;
    cout << "Ingrese un numero: ";
    cin >> k;
    cout << endl;

    cout << funcionDeHash(k);
    return 0;
}
