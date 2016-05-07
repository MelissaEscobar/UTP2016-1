#include<iostream>
using namespace std;
//funciones prototipo:
int leernum();
int ult_dig();
int primo();
int suma_primos(int n);
int sp_dividen(int n, int sum);

int main(){
	int n;
	n=leernum();
	sp_dividen(n, suma_primos(n));
}

//Funcion que lee numero
int leernum(){
	int n;
	cout<<"Ingrese un numero ";
	cin>>n;
	return(n);
}

//Funcion que devuelve el ultimo digito
int ult_dig(int n){
	return(n%10);
}

//Determina si el digito es primo, de ser asi retorna el digito, de lo contrario retorna 0
int primo(int n){
	int i=2;
	if(n<=1)
        return(0);
	else
	{
		while((n%i)!=0){
			i=i+1;
		}
		if(i==n)
            return(n);
		return(0);
	}
}

//Esta funcion suma los digitos que sean numeros primos
int suma_primos(int n){
	int acu=0;
	while (n>0){
		acu+=primo(ult_dig(n));
		n=n/10;
	}
	return(acu);
}

//Esta funcion determina si la suma de los digitos primos
//divide exactamente alnumero n
int sp_dividen(int n, int sum){
	if(sum==0)
	cout<<"La suma de los digitos primos NOOO divide exactamente a "<<n;
	else{
		if((n%sum)==0)
		cout<<"La suma de los digitos primos divide exactamente a "<<n;
		else
		cout<<"La suma de los digitos primos NOOO divide exactamente a "<<n;
	}
}

