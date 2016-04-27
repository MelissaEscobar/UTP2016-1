#include <iostream>
#include <math.h>

using namespace std;

int isprime(int n){
   if (n<=1) return 0;
   if (n==2) return 1;
   if (n%2==0) return 0;
   int m=sqrt(n);
   for (int i=3; i<=m; i+=2)
   if (n%i==0)
       return 0;
   return 1;
}

int leernum(){
    int n;
    cout<<"Ingresa un numero: ";
    cin>>n;
    return n;
}

int lastdigit(int n){
    return(n%10);
}

int cuentaprimos(int n){
    while(m !=0){
    int acu=0,m=n;
   if(isprime(x))
        acu+=1;
    }

}
int main(){
    int x=leernum();
    cout<<x<<endl;
    if(isprime(x))
        cout<<"Si es primo :D"<<endl;
    else
        cout<<"Lo siento no lo es"<<endl;

}
