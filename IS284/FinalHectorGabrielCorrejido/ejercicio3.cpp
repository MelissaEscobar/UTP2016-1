#include<iostream>
using namespace std;
//funciones prototipo.
int leernum();
int sum_dig_dividen(int n);
int cont_suma_dig(int n);
int ult_dig(int n);

int main(){
    int numerito;        //llamamos la funcion leer numero.
    numerito=leernum();  //operemos con el numero que leimos.
    sum_dig_dividen(numerito);
    return 0;
}

int leernum(){
    int n;
    cout<<"Ingrese un Numero Entero: ";
    cin>>n;
    return(n);
}

int sum_dig_dividen(int n){
	if((n%cont_suma_dig(n))==0)
        cout<<"[OK]La suma de los digitos de "<<n<<" lo dividen de forma exacta";
	else
        cout<<"[!!]La suma de los digitos de "<<n<<" no lo dividem de forma exacta";
}
int cont_suma_dig(int n){
    int acu=0,m=n;
    while(m!=0){
        acu+=ult_dig(m);
        m/=10;
        }
    return(acu);
}

//Determina el ultimo digito
int ult_dig(int n){
    int dig;
    dig=n%10;
    return(dig);
}
