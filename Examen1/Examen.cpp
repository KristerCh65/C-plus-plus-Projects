#include <iostream>
#include "Empleados.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

Empleados *IN, *FN, *LI, *D;
void agregar(string,int);
void Mostrar();
void Mayores();
int op;
string nm;
int base;

int main(int argc, char** argv) {
	
	do{
		cout<<"\tMenu"<<endl;
		cout<<"1) Ingresar Datos"<<endl;
		cout<<"2) Mostrar Datos"<<endl;
		cout<<"3) Mostrar Mayores"<<endl;
		cout<<"0) Salir..."<<endl;
		cout<<"Seleccione una opcion:"<<endl;
		cin>>op;
	
		switch(op){
			case 1:
				cout<<"Ingrese Nombre: "<<endl;
				cin>>nm;
				cout<<"Ingrese Sueldo Base"<<endl;
				cin>>base;
				agregar(nm,base);
				break;
			case 2:
				cout<<"Mostrando Elementos: "<<endl;
				Mostrar();
				break;
			case 3:
				cout<<"Mostrando Sueldos Mayores: "<<endl;
				Mayores();
				break;
		}
	}while(op!=0);
	
	
	return 0;
}

void agregar(string nom, int SB){
	LI = new Empleados();
	LI->Nombre = nom;
	LI->sueldo = SB;
	
	if(IN==NULL){
		IN = LI;
		FN = LI;
	}else{
		FN->nxt=LI;
		FN = LI;
	}
}

void Mostrar(){
	LI=IN; //puntero a inicio
	
	while(LI!=NULL){
		cout<<"Nombre:      "<<LI->Nombre<<endl;
		cout<<"Sueldo Base: "<<LI->sueldo<<endl;
		cout<<"Deducciones: "<<LI->deducciones()<<endl;
		cout<<"Sueldo Neto: "<<LI->Pagar()<<endl;
		LI = LI->nxt;
	}
}

void Mayores(){
	LI=IN;
    D=LI;
    int datos;
    int cont;
    while (LI->nxt!=NULL) {
        D = LI->nxt;
        
        while (D!=NULL) {
 
            if (LI->sueldo > D->sueldo) {
                datos = D->sueldo;
                D->sueldo = LI->sueldo;
                LI->sueldo = datos;
            }
            D = D->nxt;
            cont++;
        }
        LI = LI->nxt;
    }
    
	while(LI!=NULL){
		if(cont<2){
			cout<<"Nombre:      "<<LI->Nombre<<endl;
			cout<<"Sueldo Base: "<<LI->sueldo<<endl;
			cout<<"Deducciones: "<<LI->deducciones()<<endl;
			cout<<"Sueldo Neto: "<<LI->Pagar()<<endl;
		}
		LI = LI->nxt;
		cont++;
	}
	
}

