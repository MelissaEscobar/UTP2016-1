#include<iostream>
using namespace std;

//funciones prototipo:
int leernum();
int producto_dig_dividen(int n);
int ult_dig(int n);
int producto_suma_dig(int n);

int main(){
    int numerito;        //llamamos la funcion leer numero.
    numerito=leernum();  //operemos con el numero que leimos.
    producto_dig_dividen(numerito);

    return 0;
}

int leernum(){
    int n;
    cout<<"Ingrese un Numero Entero: ";
    cin>>n;
    return(n);
}

int producto_dig_dividen(int n){
	if(producto_suma_dig(n)==0)
        cout<<"El producto de los digitos de "<<n<<" no lo dividem de forma exacta";
	else if((n%producto_suma_dig(n))==0)
		cout<<"El producto de los digitos de "<<n<<" lo dividem de forma exacta";
	else
        cout<<"El producto de los digitos de "<<n<<" no lo dividem de forma exacta";
}

int producto_suma_dig(int n){
    int acu=1,m=n;
    while(m!=0){
        acu*=ult_dig(m);
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
