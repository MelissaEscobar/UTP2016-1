#include <iostream>
using namespace std;
int suma(int vn1, int vn2);

void imprimir(int n){
    switch(n){
        case 1:
          cout<<"  **\n";
          cout<<" ***\n";
          cout<<"  **\n";
          cout<<"  **\n";
          cout<<" ****\n"<<endl;
        break;

        case 2:
          cout<<"****\n";
          cout<<"   *\n";
          cout<<"****\n";
          cout<<"*   \n";
          cout<<"****\n";
        break;

        case 3:
          cout<<"****\n";
          cout<<"   *\n";
          cout<<"****\n";
          cout<<"   *\n";
          cout<<"****\n"<<endl;
        break;

        case 4:
          cout<<"*  *\n";
          cout<<"*  *\n";
          cout<<"****\n";
          cout<<"   *\n";
          cout<<"   *\n"<<endl;
        break;

        case 5:
          cout<<"*****\n";
          cout<<"*    \n";
          cout<<"*****\n";
          cout<<"    *\n";
          cout<<"*****\n"<<endl;
        break;

        case 6:
          cout<<"*****\n";
          cout<<"*   \n";
          cout<<"*****\n";
          cout<<"*   *\n";
          cout<<"*****\n"<<endl;
        break;

        case 7:
          cout<<"******\n";
          cout<<"    *\n";
          cout<<"   *\n";
          cout<<"  *\n";
          cout<<" *\n"<<endl;
        break;

        case 8:
          cout<<"*****\n";
          cout<<"*   *\n";
          cout<<"*****\n";
          cout<<"*   *\n";
          cout<<"*****\n"<<endl;
        break;


        case 9:
          cout<<"*****\n";
          cout<<"*   *\n";
          cout<<"*****\n";
          cout<<"    *\n";
          cout<<"    *\n"<<endl;
        break;
    }
    }

int leernums(){
int n1;
  cout<<"[*]Ingresa un Numero Entero: ";
  cin>>n1;
  return(n1);
}

bool validar(int n1,int n2){
    if(n1<=9 && n2<=9)
        return 1;
    return 0;
}

int menu(){
    int operador;
    //empresa();
    cout<<"---------------------------------"<<endl;
    cout<<"             MENU"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"1.SUMA\n2.RESTA\n3.MULTIPLICACION\n4.DIVISION\n5.MODULO\n\n: ";
    cin>>operador;
    return(operador);
}
bool validaroperador(int operador){
    if(operador==(1||2||3||4||5))
        return 1;
    return 0;
}

int seleccion_operacion(int vn1,int vn2, int operador){
    int a;
    switch(operador){
        case 1:
            a=suma(vn1,vn2);
            return(a);
        break;

        default:
        cout<<"ERROR ERNO !";
    }
 }

int suma(int vn1, int vn2){
    int result;
    result=vn1+vn2;
    cout<<endl;
    cout<<" "<<vn1<<" + "<<vn2<<endl;
    return(ult_dig(result))
}
int ult_dig(int result){
    return(result%10);
}

int main(){
    int n1, n2;     //Operandos
    int operador;  //Operador
    n1=leernums();
    n2=leernums();
    if(validar(n1, n2))
        operador=menu();
    cout<<operador<<endl;
    if(validaroperador(operador))
        imprimir(seleccion_operacion(n1,n2,operador));
    else
        cout<<"Error el Valor del Operacdor no coincide con los disponibles en el menu"<<endl;
    return 0;

}
