#include <iostream>
#include "Clientes.h"
#include "Procesos.h"
#include "Ubicacion.h"
#include "Empleados.h"
#include "Calzado.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
Clientes Cl = Clientes(); 
Procesos Pro = Procesos(); 
Ubicacion Ub = Ubicacion(); 
Empleados Emp = Empleados(); 
Calzado zap = Calzado();
int op;

void menu();

int main(int argc, char** argv) {
	
	menu();
	return 0;
}

void menu(){
	do{
		cout<<"|\t   MENU        |"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"1) Procesos Ejecutandose"<<endl;
		cout<<"2) Cartera de Clientes"<<endl;
		cout<<"3) Base de Empleados"<<endl;
		cout<<"4) Control de Orgnizacion"<<endl;
		cout<<"5) Inventario de Calzado"<<endl;
		cout<<"0) Salir del Programa... "<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cin>>op;
		
		switch(op){
			case 0:
				cout<<"Hasta Pronto...!!!"<<endl;
				break;
			case 1:
				Pro.menu();
			case 2:
				Cl.menu();
				break;
			case 3:
				Emp.menu();
			case 4:
				Ub.menu();
				break;
			case 5:
				zap.menu();
				break;
			default:
				cout<<"Opcion Invalida...!!!"<<endl;
		}
		
	}while(op!=0);
}


