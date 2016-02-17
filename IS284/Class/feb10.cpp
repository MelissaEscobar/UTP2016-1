//1. Construir un programa que permita leer un entero de 3 digitos y mostrar
//la suma de los tres digitos. No validar el numero.

//2. Leer un numero real con decimales y determinar a cuanto es igual
//la suma del ultimo digito de la parte entera mas el primer digito de la parte decimal.

//3. Leer un numero real con decimales y suma el penultimo digito de la parte
//entera con el segundo digito de la parte decimal.

//4. Leer dos numero enteros y sumar los dos ultimos digitos de un numero con
//los otros dos ultimos digitos del otro numero.

//5. Leer tres numeros enteros mostrarlos en pantalla usando una sola variable

#include <bits/stdc++.h>

using namespace std;

int main(){
    float valorcito;
    cout<<"Ingresa un Numero Real";
    cin>>valorcito;
    cout<<"\n";
    cout<<(((int)valorcito%100)/10) + ((int)(valorcito*10)%10);
    int trivar[2];

    return 0;

}
