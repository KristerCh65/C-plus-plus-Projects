#ifndef UBICACION_H
#define UBICACION_H
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Ubicacion.h"
#include "string"
using namespace std;

class Ubicacion
{
	public:
		Ubicacion *I, *L, *F;
		Ubicacion *sig;
		Ubicacion *ant;
		int ub;
		int codigo, c;
		string tienda, t;
		int repisa, r;
		int fila, f;
		int columna, cl;
		string descripcion, d;
		
		void menu(){
			do{
				cout<<"|\t   Ubicacion     |"<<endl;
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout<<"1) Ubicacion en Repisa"<<endl;
				cout<<"2) Cargar Registros"<<endl;
				cout<<"3) Eliminar Registros "<<endl;
				cout<<"4) Guardar Registros"<<endl;
				cout<<"0) Menu Principal "<<endl;
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cin>>ub;
				
				switch(ub){
					case 1:
						cout<<"Ingrese Codigo:"<<endl;
						cin>>c;
						cout<<"Ingrese Nombre Tienda:"<<endl;
						cin>>t;
						cout<<"Ingrese N° Repisa:"<<endl;
						cin>>r;
						cout<<"Ingrese Fila:"<<endl;
						cin>>f;
						cout<<"Ingrese Columa:"<<endl;
						cin>>cl;
						cout<<"Ingrese Descripcion:"<<endl;
						cin>>d;
						Ubicacion::agregar(c,t,r,f,cl,d);
						break;
					case 2:
						Ubicacion::lectura();
						break;
					case 3:
						Ubicacion::borrar();
						break;
					case 4:
						Ubicacion::guardar();
						break;
					default:
						cout<<"Opcion Invalida...!!!"<<endl;
				}
			}while(ub!=0);
		}
		
		void agregar(int c, string t, int r, int f,int cl, string d){
			L = new Ubicacion();
		
			L->codigo=c;
			L->tienda=t;
			L->repisa=r;
			L->fila=f;
			L->columna=cl;
			L->descripcion=d;
			
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
		    
		    archivo.open("c:\\archivo\\Ubicacion.txt",ios::out|ios::in);//abrimos archivo en lectura
		 
			if(!archivo.is_open()){
				cout<<"No se pudo abrir el Archivo";
				cout<<"Cargando Registros en Memoria";
				
				L=I;
				while(L!=NULL){
					cout<<"Codigo:  "<<L->codigo<<endl;
					cout<<"Tienda:  "<<L->tienda<<endl;
					cout<<"N° Repisa: "<<L->repisa<<endl;
					cout<<"Fila: "<<L->fila<<endl;
					cout<<"Columna: "<<L->columna<<endl;
					cout<<"Descripcion: "<<L->descripcion<<endl;
					
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
			archivo.open("c:\\archivo\\Ubicacion.txt",ios::out|ios::app);//abrimos archivo a escribir
			
			while(L!=NULL){
				archivo<<L->codigo<<"\n";
				archivo<<L->tienda<<"\n";
				archivo<<L->repisa<<"\n";
				archivo<<L->fila<<"\n";
				archivo<<L->columna<<"\n";
				archivo<<L->descripcion<<"\n";
				
				L=L->sig;
			}
			
			archivo.close();
		}
			
		void borrar(){
			system("del c:\\archivo\\Ubicacion.txt");
		}
};

#endif
