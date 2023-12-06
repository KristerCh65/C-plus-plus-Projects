#ifndef CLIENTES_H
#define CLIENTES_H
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Clientes.h"
#include "string"

using namespace std;

class Clientes
{	
	public:	
		Clientes *I, *L, *F;
		Clientes *sig;
		Clientes *ant;
		
		int cl;
		int codigo, c;
		string nombre, n;
		string apellido, a;
		int telefono, t;
		
		void menu(){
			do{
				cout<<"|\t   CLIENTES      |"<<endl;
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout<<"1) Agregar Cliente"<<endl;
				cout<<"2) Cargar Registros"<<endl;
				cout<<"3) Eliminar Registros "<<endl;
				cout<<"4) Guardar Registros"<<endl;
				cout<<"0) Menu Principal "<<endl;
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cin>>cl;
				
				switch(cl){
					case 1:
						cout<<"Ingrese Codigo:"<<endl;
						cin>>c;
						cout<<"Ingrese Nombre:"<<endl;
						cin>>n;
						cout<<"Ingrese Apellido:"<<endl;
						cin>>a;
						cout<<"Ingrese Telefono:"<<endl;
						cin>>t;
						Clientes::agregar(c,n,a,t);
						break;
					case 2:
						Clientes::lectura();
						break;
					case 3:
						Clientes::elimina();
						break;
					case 4:
						Clientes::guardar();
						break;
					default:
						cout<<"Opcion Invalida...!!!"<<endl;
				}
			}while(cl!=0);
		}
		
		void agregar(int cod, string nom, string ape, int tel){
			L = new Clientes();
		
			L->codigo=cod;
			L->nombre=nom;
			L->apellido=ape;
			L->telefono=tel;
			
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
		    
		    archivo.open("c:\\archivo\\Clientes.txt",ios::out|ios::in);//abrimos archivo en lectura
		 
			if(!archivo.is_open()){
				cout<<"No se pudo abrir el Archivo";
				cout<<"Cargando Registros en Memoria";
				
				L=I;
				while(L!=NULL){
					cout<<"Codigo:  "<<L->codigo<<endl;
					cout<<"Nombre:  "<<L->nombre<<endl;
					cout<<"Apellido: "<<L->apellido<<endl;
					cout<<"Telefono: "<<L->telefono<<endl;
					
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
			archivo.open("c:\\archivo\\Clientes.txt",ios::app);;//abrimos archivo a escribir
			while(L!=NULL){
				archivo<<L->codigo<<"\n";
				archivo<<L->nombre<<"\n";
				archivo<<L->apellido<<"\n";
				archivo<<L->telefono<<"\n";
				
				L=L->sig;
			}
			archivo.close();
		}
		
		void elimina(){
			system("del c:\\archivo\\Clientes.txt");
		}
};

#endif
