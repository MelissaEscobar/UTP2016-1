#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//definicion de funciones prototipo.
int proceso();												//Es una funcion subcoordinadora !
int leernums();												//obtiene datos de entrada.
bool validarnumero(int n1,int n2);		//validar si los datos ingresados son de un digito.
void menu();							   					//esta funcion imprime un menu de operaciones, y obtiene el operador
																			// que operacion vamos a hacer.
bool validaroperador(int operador);		//como los operadores estan enumeraods del 1 al 5, necesitamos validar esto
																			//para saber que es correcta la operacion.
int seleccion_operacion(int vn1,int vn2, int operador);			//realiza un switch por, es decir que selecciona cual es la operacion
																														//seleccionada por el usuario.
int suma(int vn1, int vn2);																  //funcion que realiza la suma.
int resta(int vn1, int vn2);																//funcion que realiza la suma.
int producto(int vn1, int vn2);															//realiza producto entre vn1 , vn2, retorna ultimo digito
int division(int vn1, int vn2);															//realiza division entre vn1 , vn2
int modulo (int vn1, int vn2);															//realiza modulo entre vn1 , vn2
void imprimir(int n);																				//funcion que imprime la notacion grande,para los numeros
void imprimiroperadores(int n); 														//funcion que imprime la notacion grande,para los operadores
int otra_operacion();

int main(){
	proceso();
}

int proceso(){
	int n1, n2, operador;
	n1=leernums();											//es necesario leer dos operandos usamos la funcion leernums para eso.
	n2=leernums();		   								//es necesario leer dos operandos usamos la funcion leernums para eso.
	if(validarnumero(n1, n2)){				 //si ambos numeros son de un solo digito, entonces muestre el menu de opcio		nes
				menu();								  		 //el menu se muestra y retorna cual fue la operador seleccionado por el usuario.
				cin>>operador;
				if(validaroperador(operador))				//valida el numero del operador
					seleccion_operacion(n1,n2,operador);

				}
	else														    //Si hay uno de los numeros ingresados por el usuario de dos o mas digitos.
			cout<<"[!]Los numeros poseen mas de dos digitos."<<endl;//imprime este mensaje.

	otra_operacion();
	return 0;
}																		  //EOF main.EOF significa(End of File)

int leernums(){												//Adquisicion de datos de entrada
int n1;
  	cout<<"[*]Ingresa un Numero Entero: ";
  	cin>>n1;													  //el valor que el usuario ha ingresado, lo retornamos.!
  	return(n1);
}

bool validarnumero(int n1,int n2){										//Validamos que los numeros sean de un solo digito entre
    if( (n1>=-9 && n1<=9)  && (n2>=-9 && n2<=9) )			//Si el numero esta entre n1 [0-9] y n2 [0-9] quiere decir
			return 1; 																			//que es de un digito positivo
		else
			  return 0;
}

void menu(){															//Es solo un menu de texto.
    cout<<"---------------------------------"<<endl
    		<<"      CALCULADORA TESLA V0.1		  "<<endl
    		<<"---------------------------------"<<endl
    		<<"             MENU								"<<endl
    		<<"---------------------------------"<<endl
	    	<<"[1] SUMA													"<<endl
				<<"[2] RESTA												"<<endl
				<<"[3] MULTIPLICACION								"<<endl
				<<"[4] DIVISION											"<<endl
				<<"[5] MODULO												"<<endl
    		<<"[*] Seleccione la Opcion del Menu: ";
}

bool validaroperador(int operador){				//Se encarga de verificar que el operador ingresado en el menu
//sea un numero entre 1 y 5 opciones posibles.
	if(operador == 1|| operador == 2 || operador == 3 || operador == 4 || operador == 5)
		return 1;
	else
		cout<<"[!]Error la opcion elejida del menu de operaciones es incorrecta."<<endl;
}

int seleccion_operacion(int vn1,int vn2, int operador){
switch(operador){
		case 1:
			suma(vn1,vn2);													//Suma.ultimo digito de la operacion de suma.
      break;
    case 2:																		//resta
		 resta(vn1,vn2);
     break;
    case 3:																		//multiplicacion  primer digito de la operacion de producto.
		producto(vn1,vn2);												//realiza la operacion correspondiente
    break;

    case 4:																		//division
		division(vn1,vn2);												//llama a la funcion que realiza la funcion de la division
    break;
    case 5:																		//modulo.
		modulo(vn1,vn2);
    break;

    default:
  	cout<<"ERROR ERNO !";
    }
 }

//Operaciones Individuales
int suma(int vn1, int vn2){			//Realiza la operacion de suma, para poder operar necesita dos valores
int result=vn1+vn2;							//vn1 y vn2 , esto es validadon1, validadon2
cout<<endl;
imprimir(vn1);									//Imprimir en formato grande, el numero correspondiente
imprimiroperadores(1);					//Imprimimos en formato grande, el operador de signo mas.
imprimir(vn2);								  //Imprimir en formato grande, el numero correspondiente
imprimiroperadores(0);					//Imprimimos en formato grande, el operador de cero.
imprimir(result%10);						//el ultimo digito del resultado obtenido.
}

int resta(int vn1, int vn2){		//Realiza la operacion de resta, para poder operar necesita dos valores
int result=vn1-vn2;							//vn1 y vn2 , esto es validadon1, validadon2
cout<<endl;
imprimir(vn1);									//Imprimir en formato grande, el numero correspondiente
imprimiroperadores(2);					//Imprimimos en formato grande, el operador de signo menos.
imprimir(vn2);									//Imprimir en formato grande, el numero correspondiente
imprimiroperadores(0);					//Imprimimos en formato grande, el operador de cero.
imprimir(result);								//el resultado obtenido en formato grande.
}

//Para cada modulo de operacion la descripcion es la misma que en el anterior.
int producto(int vn1, int vn2){		//Realiza la operacion de producto, para poder operar necesita dos valores
int result=vn1*vn2;								//vn1 y vn2 , esto es validadon1, validadon2
cout<<endl;
imprimir(vn1);
imprimiroperadores(5);
imprimir(vn2);
imprimiroperadores(0);
result=(result/10)%10;
imprimir(result);							//Esto realiza la division por 100, suponga un numero result=89/100=0.89%10=8
															//Se obtiene el primer digito
}

int division(int vn1, int vn2){		//Realiza la operacion de division, para poder operar necesita los vn1 y vn
int result=vn1/vn2;
cout<<endl;
imprimir(vn1);
imprimiroperadores(3);
imprimir(vn2);
imprimiroperadores(0);
imprimir(result);
}

int modulo (int vn1, int vn2){		//Realiza la operacion de division, para poder operar necesita los vn1 y vn
int result=vn1%vn2;
cout<<endl;
imprimir(vn1);
imprimiroperadores(4);
imprimir(vn2);
imprimiroperadores(0);
imprimir(result);
}

//Impresiones Formato Grande
//Nomenclatura en las avisos por pantalla.
//[*] :Significa Entrada de datos!
//[!] : Significa Error
//[Ok]: La operacion es correcta, se  imprime solo cuando es necesario.
//Imprime los operadores en notacion grande
void imprimiroperadores(int n){
switch(n){
	case 0:
	 cout<<" 					  \n"
     		 <<"**********\n"
     		 <<"          \n"
     		 <<"**********\n"
     		 <<"   \n"<<endl;
	break;

	case 1:
	   cout<<"   ***		\n"
     		 <<"   ***		\n"
     		 <<"*********	\n"
     	   <<"*********	\n"
     		 <<"   ***		\n"
     		 <<"   ***		\n"<<endl;
	break;

    case 2:
	 	 cout<<"  			\n"
     		 <<"********\n"
     		 <<"********\n"
     		 <<"  \n"<<endl;
	break;
	case 3:
     cout<<"     ***  \n"
     		 <<"    **    \n"
     		 <<"   **     \n"
     		 <<"  **      \n"
     		 <<" **       \n"<<endl;
	 break;

	 case 4:
	 	 cout<<" XX  ***  \n"
	 			 <<" XX **    \n"
	 			 <<"   **     \n"
	 			 <<"  ** XX   \n"
	 			 <<" **  XX   \n"<<endl;
	  break;
       case 5:
	cout<<"XX   XX \n"
  		<<"  x|X   \n"
  	  <<"  x|X   \n"
  		<<"XX   XX \n"<<endl;
			break;

		}
  }		//EOF Imprimir

//Imprime los digitos en notacion grande
void imprimir(int n){
switch(n){
	case -9:
      cout<<"      *****\n";
      cout<<"      *   *\n";
      cout<<" **** *****\n";
      cout<<"          *\n";
      cout<<"          *\n"<<endl;
     break;

     case -8:
      cout<<"       *****\n";
      cout<<"       *   *\n";
      cout<<" ****  *****\n";
      cout<<"       *   *\n";
      cout<<"       *****\n"<<endl;
     break;

      case -7:
      cout<<"      ******\n";
      cout<<"          *\n";
      cout<<"****     *\n";
      cout<<"        *\n";
      cout<<"       *\n"<<endl;
     break;

     case -6:
      cout<<"      *****\n";
      cout<<"      *   \n";
      cout<<" **** *****\n";
      cout<<"      *   *\n";
      cout<<"      *****\n"<<endl;
     break;

     case -5:
      cout<<"       *****\n";
      cout<<"       *    \n";
      cout<<" ****  *****\n";
      cout<<"           *\n";
      cout<<"       *****\n"<<endl;
     break;

     case -4:
      cout<<"       *  *\n";
      cout<<"       *  *\n";
      cout<<" ****  ****\n";
      cout<<"          *\n";
      cout<<"          *\n"<<endl;
     break;

     case -3:
      cout<<"      ****\n";
      cout<<"         *\n";
      cout<<" **** ****\n";
      cout<<"         *\n";
      cout<<"      ****\n"<<endl;
     break;

    case -2:
     cout<<"       ****\n";
     cout<<"          *\n";
     cout<<" ****  ****\n";
     cout<<"       *   \n";
     cout<<"       ****\n";
     break;

	case -1:
	 cout<<"       	  **\n"
     		 <<"       ***\n"
     		 <<"****    **\n"
     		 <<"        **\n"
     		 <<"       ****\n"<<endl;
	break;

	case 0:
     cout<<"   *****\n"
     		 <<"   *   *\n"
     		 <<"   *   *\n"
     		 <<"   *   *\n"
     		 <<"   *****\n"<<endl;
		 break;

	case 1:
	   cout<<"    **\n"
     		 <<"   ***\n"
     		 <<"    **\n"
     		 <<"    **\n"
     		 <<"   ****\n"<<endl;
	break;

    case 2:
     cout<<" *****\n"
     		 <<"     *\n"
     		<<"  *****\n"
     		<<"  *   \n"
     		<<"  *****\n"<<endl;
     break;

     case 3:
      cout<<"  ****\n"
      		<<"     *\n"
      		<<"  ****\n"
      		<<"     *\n"
      		<<"  ****\n"<<endl;
     break;

     case 4:
      cout<<"  *  *\n"
      		<<"  *  *\n"
      		<<"  ****\n"
      		<<"     *\n"
      		<<"     *\n"<<endl;
     break;

     case 5:
      cout<<"  *****\n"
      		<<"  *    \n"
      		<<"  *****\n"
      		<<"      *\n"
      		<<"  *****\n"<<endl;
     break;

     case 6:
      cout<<"  *****\n"
      		<<"  *   \n"
      		<<"  *****\n"
      		<<"  *   *\n"
      		<<"  *****\n"<<endl;
     break;

     case 7:
      cout<<"  ******\n"
      		<<"      *\n"
      		<<"     *\n"
      		<<"    *\n"
      		<<"   *\n"<<endl;
     break;

     case 8:
    cout<<"  *****\n"
      	<<"  *   *\n"
      	<<"  *****\n"
      	<<"  *   *\n"
				<<"  *****\n"<<endl;
     break;


     case 9:
      cout<<"  *****\n"
      		<<"  *   *\n"
      		<<"  *****\n"
      		<<"      *\n"
      		<<"      *\n"<<endl;
     break;
		}
  }		//EOF Imprimir


int otra_operacion(){				//Esta funcion creada por gabriel, realiza el retorno a la funcion principal.
	char n;
	cout<<"\n\nSi va a realizar otra operacion presione Enter\"\"... ";
	n=getche();         //se recibe datos por teclado.
	if(n=='\r'){        //\r return
	system("cls");      //limpia la pantalla.
	proceso();          //de nuevo llama al proceso.
	}
}
