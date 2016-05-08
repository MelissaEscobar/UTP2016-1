#include <iostream>
using namespace std;

// Construir un prog que permita leer una cadena y 
// que elimine las vocales

int leercad(char *p)
{	// mientras lo que entre sea difte de ESC
    *p=getche();
	while(*p!=27)
	{
		if(*p==39)  // si es la tilde
		{
			putchar('\b');  // retorne el cursor
			*p=getche(); // reciba otro caracter
			putchar('\b'); // vuelva a retornar el cursor
			switch (*p){  // evalúe lo que recibió
				case 'a':putchar(160);*p=160;break;
				case 'e':putchar(130);*p=130;break;
				case 'i':putchar(161);*p=161;break;
				case 'o':putchar(162);*p=162;break;
				case 'u':putchar(163);*p=163;break;
				default:putchar(7);
			}
		}
		p++;  // pase a la sigte casilla de memoria
		*p=getche();
	}
	*p='\0';  // finalice la cadena (nulo)
}

int mostrarcad(char *p)
{
	while(*p)   // mientras haya caracteres 
	{
		putchar(*p);  // muestre un caracter
		//cout<<"-->"<<int(*p)<<"\n";  // testing
		p++;  // y pase al siguiente
	}
}

// Función clave de este ejercicio
int esvocal(char c)
{   // si el parámetro recibido es una vocal
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'
	||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'
	||c==160||c==130||c==161||c==162||c=='ú')
	   return(1);  // retorne V
	   return(0);  // retorne V
}

int eliminavoc(char *p)
{
	while(*p)  // mientras hayan caracteres
	{
	    if(esvocal(*p))	// // si el caracter es vocal
	        *p='-';  // cámbiela por un guión
	    p++;  // avance al sigte caracter
	}
}

// función ppal
int main()
{
	char v[6];
	// 1. leer una cadena
	leercad(v);
	// 2. mostrarla por verificación
	cout<<"\n\n";mostrarcad(v);
	// 3. le eliminamos las vocales
	eliminavoc(v);
	// 4. volvemos a mostrar la cadena
	cout<<"\n\n-->";mostrarcad(v);
}
