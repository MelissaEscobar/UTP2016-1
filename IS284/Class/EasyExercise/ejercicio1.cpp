#include <iostream>
using namespace std;
//1. Leer un número Z y determinar cuántos de sus dígitos lo divide exactamente.
//funciones prototipo:
int leernum();                    //Toma valor del usuario.:Interface
int cuenta_div(int n);            //Cuenta los divisores entre el numero deusuario/digitosdenumero:Operativo
int divisor(int n, int dig);      //Verifica la divisibilidad del numero y el digito, Resultado booleano:Operativo.
int ult_dig(int n);               //retorna el ultimo digito del valor numero: Operativo.

int main(){
    int numerito;                //llamamos la funcion leer numero.
    numerito=leernum();          //operemos con el numero que leimos.
    cout<<cuenta_divisores(numerito);    //muestra la operacion.
    return 0;
}

int leernum(){
    int n;
    cout<<"Ingrese un Numero Entero: ";
    cin>>n;
    return(n);
}

//Cuenta digitos que son divisores de n
int cuenta_divisores(int n){
    int acu=0,m=n;
    while(m!=0){
        acu+=divisor(n,ult_dig(m));
        m/=10;
    }
    return(acu);
}

//Boolean, entiendo si el valor obtenido se divide por el digito, retorna 1.
int divisor(int n, int dig){
	if(dig==0)
	    return(0);
    if( (n%dig) == 0)
	    return(1);
	else
        return(0);
}

//Determina el ultimo digito
int ult_dig(int n){
    return(n%10);
}
