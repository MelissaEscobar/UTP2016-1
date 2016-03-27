#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

int proceso();														//Inicializa el todo el proceso.
int leer_num();														//
int validar_numeros(int a, int b);
int mostrar_menu();
int leer_operador();
int validar_operador(int x);
int primer_digito();
int ultimo_digito();
int suma();
int resta();
int producto();
int division();
int modulo();
int realizar_operacion(int a, int b, int op);
int seleccionar_dib_numero();
int seleccionar_dib_simbolo();
int visualizar(int a, int op, int b, int res);
int otra_operacion();


int main(){
	proceso();
}

int proceso(){
	int a,b,op,res;
	a=leer_num();
	b=leer_num();
	if((validar_numeros(a,b))==0){
	cout<<"Error! Los numeros ingresados no cumplen con las condiciones indicadas";
	otra_operacion();
	}
	else{
		mostrar_menu();
		op=leer_operador();
		if((validar_operador(op))==0){
		cout<<"Error! No selecciono uno de los posibles operadores";
		otra_operacion();
		}
		else{
			res=realizar_operacion(a,b,op);
			visualizar(a,op,b,res);
			otra_operacion();
		}
	}
}


int leer_num(){
	int n;
	cout<<"Ingrese un numero entero de un digito: ";
	cin>>n;
	return(n);
}

int validar_numeros(int a, int b){
	if(((a<=9)&&(b<=9))&&((a>=-9)&&(b>=-9)))
		return(1);

	return(0);
}

int mostrar_menu(){

	cout<<"MENU DE OPERACIONES"<<endl
			<<"===================="<<endl
			<<"[1] Suma"<<endl
			<<"[2] Resta"<<endl
			<<"[3] Producto"<<endl
			<<"[4] Division"<<endl
			<<"[5] Modulo"<<endl
			<<"Elija la operacion a realizar:  >";
}

int leer_operador(){
	int x;
	cin>>x;
	return(x);
}

int validar_operador(int x){
	switch(x){
		case 1: case 2:	case 3: case 4: case 5:
		return(x);
		default: return(0);
	}
}


int primer_digito(int n){
	if((n>=-9) && (n>=9))
	return(n%10);
	return((n/10)%10);
}

int ultimo_digito(int n){
	return(n%10);
}

int suma(int a, int b){
	return(ultimo_digito(a+b));
}

int resta(int a, int b){
	return(a-b);
}

int producto(int a, int b){
	return(primer_digito(a*b));
}

	int division(int a, int b){
		if(b==0)
		return(100);													//El 100 es para tener una forma de indicar la
		return(a/b);													//indeterminacion
	}

int modulo(int a, int b){
	if(b==0)
	return(100);
	return(a%b);
}

int realizar_operacion(int a, int b, int op){
	int res;
	switch(op){
		case 1: res=suma(a,b); break;
		case 2: res=resta(a,b); break;
		case 3: res=producto(a,b); break;
		case 4: res=division(a,b); break;
		case 5: res=modulo(a,b); break;
	}
	return(res);
}

void gotoxy(int x, int y){
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon, dwPos);
}

int dib_mas(int x, int y){
	gotoxy(x,y);  cout<<"   **   ";
	gotoxy(x,y+1);cout<<"   **   ";
	gotoxy(x,y+2);cout<<"********";
	gotoxy(x,y+3);cout<<"********";
	gotoxy(x,y+4);cout<<"   **   ";
	gotoxy(x,y+5);cout<<"   **   ";
}

int dib_menos(int x,int y){
	gotoxy(x,y+2);cout<<"********";
	gotoxy(x,y+3);cout<<"********";
}

int dib_producto(int x, int y){
	gotoxy(x,y);  cout<<"**    **";
	gotoxy(x,y+1);cout<<" **  ** ";
	gotoxy(x,y+2);cout<<"  ****  ";
	gotoxy(x,y+3);cout<<"  ****  ";
	gotoxy(x,y+4);cout<<" **  ** ";
	gotoxy(x,y+5);cout<<"**    **";
}

int dib_division(int x, int y){
	gotoxy(x,y);  cout<<"      **";
	gotoxy(x,y+1);cout<<"     ** ";
	gotoxy(x,y+2);cout<<"   **   ";
	gotoxy(x,y+3);cout<<"  **    ";
	gotoxy(x,y+4);cout<<" **     ";
	gotoxy(x,y+5);cout<<"**      ";
}

int dib_modulo(int x, int y){
	gotoxy(x,y);  cout<<" *    **";
	gotoxy(x,y+1);cout<<"    ** ";
	gotoxy(x,y+2);cout<<"   **   ";
	gotoxy(x,y+3);cout<<"  **    ";
	gotoxy(x,y+4);cout<<" **     ";
	gotoxy(x,y+5);cout<<"**    * ";
}


int dib_igual(int x, int y){
	gotoxy(x,y);  cout<<"        ";
	gotoxy(x,y+1);cout<<"********";
	gotoxy(x,y+2);cout<<"        ";
	gotoxy(x,y+3);cout<<"        ";
	gotoxy(x,y+4);cout<<"********";
	gotoxy(x,y+5);cout<<"        ";
}

int dib_0(int x, int y){
	gotoxy(x,y);  cout<<"********";
	gotoxy(x,y+1);cout<<"*      *";
	gotoxy(x,y+2);cout<<"*      *";
	gotoxy(x,y+3);cout<<"*      *";
	gotoxy(x,y+4);cout<<"*      *";
	gotoxy(x,y+5);cout<<"********";
}

int dib_1(int x, int y){
	gotoxy(x,y);  cout<<"   **   ";
	gotoxy(x,y+1);cout<<"  ***   ";
	gotoxy(x,y+2);cout<<" * **   ";
	gotoxy(x,y+3);cout<<"   **   ";
	gotoxy(x,y+4);cout<<"   **   ";
	gotoxy(x,y+5);cout<<" ****** ";
}

int dib_2(int x, int y){
	gotoxy(x,y);  cout<<"  ****  ";
	gotoxy(x,y+1);cout<<" **  ** ";
	gotoxy(x,y+2);cout<<"    **  ";
	gotoxy(x,y+3);cout<<"   **   ";
	gotoxy(x,y+4);cout<<" *******";
	gotoxy(x,y+5);cout<<"********";
}

int dib_3(int x, int y){
	gotoxy(x,y);  cout<<"********";
	gotoxy(x,y+1);cout<<"      **";
	gotoxy(x,y+2);cout<<"********";
	gotoxy(x,y+3);cout<<"********";
	gotoxy(x,y+4);cout<<"      **";
	gotoxy(x,y+5);cout<<"********";
}

int dib_4(int x, int y){
	gotoxy(x,y);  cout<<"**    **";
	gotoxy(x,y+1);cout<<"**    **";
	gotoxy(x,y+2);cout<<"********";
	gotoxy(x,y+3);cout<<"********";
	gotoxy(x,y+4);cout<<"      **";
	gotoxy(x,y+5);cout<<"      **";
}

int dib_5(int x, int y){
	gotoxy(x,y);  cout<<"********";
	gotoxy(x,y+1);cout<<"**      ";
	gotoxy(x,y+2);cout<<"********";
	gotoxy(x,y+3);cout<<"********";
	gotoxy(x,y+4);cout<<"      **";
	gotoxy(x,y+5);cout<<"********";
}

int dib_6(int x, int y){
	gotoxy(x,y);  cout<<"*******";
	gotoxy(x,y+1);cout<<"**      ";
	gotoxy(x,y+2);cout<<"**      ";
	gotoxy(x,y+3);cout<<"********";
	gotoxy(x,y+4);cout<<"**    **";
	gotoxy(x,y+5);cout<<"********";
}

int dib_7(int x, int y){
	gotoxy(x,y);  cout<<"*********";
	gotoxy(x,y+1);cout<<"**     **";
	gotoxy(x,y+2);cout<<"      **";
	gotoxy(x,y+3);cout<<"    	 **";
	gotoxy(x,y+4);cout<<"      **";
	gotoxy(x,y+5);cout<<"      **";
}

int dib_8(int x, int y){
	gotoxy(x,y);  cout<<"********";
	gotoxy(x,y+1);cout<<"*      *";
	gotoxy(x,y+2);cout<<"********";
	gotoxy(x,y+3);cout<<"********";
	gotoxy(x,y+4);cout<<"*      *";
	gotoxy(x,y+5);cout<<"********";
}

int dib_9(int x, int y){
	gotoxy(x,y);  cout<<"********";
	gotoxy(x,y+1);cout<<"**    **";
	gotoxy(x,y+2);cout<<"**    **";
	gotoxy(x,y+3);cout<<"********";
	gotoxy(x,y+4);cout<<"      **";
	gotoxy(x,y+5);cout<<"      **";
}

int dib_error(int x, int y){
	gotoxy(x,y);  cout<<"******"<<"  ***** "<<"  ***** "<<"  ******"<<"  ***** ";
	gotoxy(x,y+1);cout<<"*     "<<"  *    *"<<"  *    *"<<"  *    *"<<"  *    *";
	gotoxy(x,y+2);cout<<"******"<<"  ***** "<<"  ***** "<<"  *    *"<<"  ***** ";
	gotoxy(x,y+3);cout<<"*     "<<"  *   * "<<"  *   * "<<"  *    *"<<"  *   * ";
	gotoxy(x,y+4);cout<<"******"<<"  *    *"<<"  *    *"<<"  ******"<<"  *    *";
}

int seleccionar_dib_numero(int n, int x, int y){
	switch(n){
		case 0: dib_0(x,y); break;
		case 1: dib_1(x,y); break;
		case 2: dib_2(x,y); break;
		case 3: dib_3(x,y); break;
		case 4: dib_4(x,y); break;
		case 5: dib_5(x,y); break;
		case 6: dib_6(x,y); break;
		case 7: dib_7(x,y); break;
		case 8: dib_8(x,y); break;
		case 9: dib_9(x,y); break;
	}
}

int seleccionar_dib_simbolo(int op, int x, int y){
	switch(op){
		case 1: dib_mas(x,y); break;
		case 2: dib_menos(x,y); break;
		case 3: dib_producto(x,y); break;
		case 4: dib_division(x,y); break;
		case 5: dib_modulo(x,y); break;
	}
}

int visualizar(int a, int op, int b, int res){
	int x=0;
	if(a<0){
		dib_menos(x,10);
		x=x+10;
		seleccionar_dib_numero((a*(-1)),x,10);
		x=x+10;
	}
	else{
	seleccionar_dib_numero(a,x, 10);
	x=x+10;
	}
	seleccionar_dib_simbolo(op,x,10);
	x=x+10;
	if(b<0){
		dib_menos(x,10);
		x=x+10;
		seleccionar_dib_numero((b*(-1)),x,10);
		x=x+10;
	}
	else{
		seleccionar_dib_numero(b,x, 10);
		x=x+10;
	}
	dib_igual(x,10);
	x=x+10;

	if(res<0){
		dib_menos(x,10);
		seleccionar_dib_numero((res*(-1)),x+10,10);
	}
	else if(res==100){
		dib_error(x,10);
	}
	else{
		seleccionar_dib_numero(res,x,10);
	}
}

int otra_operacion(){
	char n;
	cout<<"\n\nSi va a realizar otra operacion presione Enter... ";
	n=getche();
	if(n=='\r'){
	system("cls");
	proceso();
	}
}
