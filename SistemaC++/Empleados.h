#ifndef EMPLEADOS_H
#define EMPLEADOS_H
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Empleados.h"
#include "string"

using namespace std;

class Empleados
{	
	public:	
		Empleados *I, *L, *F;
		Empleados *sig;
		Empleados *ant;
		
		int em;
		int codigo, c;
		string nombre, n;
		string apellido, a;
		int telefono, t;
		int sueldo, s;
		
		void menu(){
			do{
				cout<<"|\t   Empleados      |"<<endl;
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout<<"1) Agregar Empleado"<<endl;
				cout<<"2) Cargar Registros"<<endl;
				cout<<"3) Eliminar Registros "<<endl;
				cout<<"4) Guardar Registros"<<endl;
				cout<<"0) Menu Principal "<<endl;
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cin>>em;
				
				switch(em){
					case 1:
						cout<<"Ingrese Codigo:"<<endl;
						cin>>c;
						cout<<"Ingrese Nombre:"<<endl;
						cin>>n;
						cout<<"Ingrese Apellido:"<<endl;
						cin>>a;
						cout<<"Ingrese Telefono:"<<endl;
						cin>>t;
						cout<<"Ingrese Sueldo:"<<endl;
						cin>>s;
						Empleados::agregar(c,n,a,t,s);
						break;
					case 2:
						Empleados::lectura();
						break;
					case 3:
						Empleados::elimina();
						break;
					case 4:
						Empleados::guardar();
						break;
					default:
						cout<<"Opcion Invalida...!!!"<<endl;
				}
			}while(em!=0);
		}
		
		void agregar(int cod, string nom, string ape, int tel, int sb){
			L = new Empleados();
		
			L->codigo=cod;
			L->nombre=nom;
			L->apellido=ape;
			L->telefono=tel;
			L->sueldo=sb;
			
			L->sig=NULL;
			
			if(I==NULL){
				I=L;
				F=L;
			}
			else{
				F->sig=L;
				L->ant=F;
				F=L;
			}
		}
			
		void lectura(){
		    fstream archivo;
		    string texto;
		    
		    archivo.open("c:\\archivo\\Empleados.txt",ios::out|ios::in);//abrimos archivo en lectura
		 
			if(!archivo.is_open()){
				cout<<"No se pudo abrir el Archivo";
				cout<<"Cargando Registros en Memoria";
				
				L=I;
				while(L!=NULL){
					cout<<"Codigo:  "<<L->codigo<<endl;
					cout<<"Nombre:  "<<L->nombre<<endl;
					cout<<"Apellido: "<<L->apellido<<endl;
					cout<<"Telefono: "<<L->telefono<<endl;
					cout<<"Sueldo: "<<L->sueldo<<endl;
					
					L=L->sig;
				}
				
				archivo.close();
					
				exit(1);
				
			}else{
				
				while(!archivo.eof()){//mientras no sea el final del archivo
			    	getline(archivo,texto);
		 			cout<<texto<<endl;
				}
				
				archivo.close();	
			}
		}
		
		void guardar(){
			ofstream archivo;
			L=I;
			archivo.open("c:\\archivo\\Empleados.txt",ios::app);;//abrimos archivo a escribir
			while(L!=NULL){
				archivo<<L->codigo<<"\n";
				archivo<<L->nombre<<"\n";
				archivo<<L->apellido<<"\n";
				archivo<<L->telefono<<"\n";
				archivo<<L->sueldo<<"\n";
				
				L=L->sig;
			}
			archivo.close();
		}
		
		void elimina(){
			system("del c:\\archivo\\Empleados.txt");
		}
};

#endif
