#include<iostream>
using namespace std;

//Funciones Prototipo
int leernum();
int tamano(int n);
int ult_dig(int n);
int divisor(int n, int dig);
int cont_div(int n);
int div_todos(int n);

int main(){
    int numerito;        //llamamos la funcion leer numero.
    numerito=leernum();  //operemos con el numero que leimos.
    div_todos(numerito);
    return 0;
}

int leernum(){
    int n;
    cout<<"Ingrese un Numero Entero: ";
    cin>>n;
    return(n);
}

int div_todos(int n){
	if(cont_div(n)==tamano(n))
        cout<<"[OK] Todos los digitos de "<<n<<" lo dividen de forma exacta\n";
	else
		cout<<"[!]NO Todos los Digitos del numero "<<n<<" o dividen de forma exacta\n";
}

int cont_div(int n){
    int acu=0,m=n;
    while(m!=0){
        acu+=divisor(n,ult_dig(m));
        m/=10;}
    return(acu);
}

//Funcion que cuenta los digitos de un numero
int tamano(int n){
	int acu=1;
	while(n>9){
        acu+=1;
		n=n/10;
		}
	return(acu);        //contar los digitos de un numero de forma al reves.
}

//Determina el ultimo digito
int ult_dig(int n){
    return(n%10);
}
//Boolean, si el valor obtenido se divide por el digito, retorna 1.
int divisor(int n, int dig)
{
	if(dig==0)
        return(0);
    if((n%dig)==0)
        return(1);
    else
        return(0);
}
