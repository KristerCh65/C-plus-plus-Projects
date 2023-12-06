#ifndef PROCESOS_H
#define PROCESOS_H
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Procesos.h"
#include "string"
using namespace std;

class Procesos
{
	public:
		Procesos *I, *L, *F;
		Procesos *sig;
		Procesos *ant;
		int pro;
		int codigo, c;
		int cliente, cl;
		int calzado, z;
		string descripcion, d;
		string inicio, i;
		string final, f;
		int empleado, e;
		
		void menu(){
			do{
				cout<<"|\t   PROCESOS     |"<<endl;
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout<<"1) Agregar Proceso"<<endl;
				cout<<"2) Cargar Registros"<<endl;
				cout<<"3) Eliminar Registros "<<endl;
				cout<<"4) Guardar Registros"<<endl;
				cout<<"0) Menu Principal "<<endl;
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cin>>pro;
				
				switch(pro){
					case 1:
						cout<<"Ingrese Codigo Proceso:"<<endl;
						cin>>c;
						cout<<"Ingrese Codigo Cliente:"<<endl;
						cin>>cl;
						cout<<"Ingrese Codigo Calzado:"<<endl;
						cin>>z;
						cout<<"Ingrese Descripcion:"<<endl;
						cin>>d;
						cout<<"Ingrese Fecha Inicio:"<<endl;
						cin>>i;
						cout<<"Ingrese fecha Final:"<<endl;
						cin>>f;
						cout<<"Ingrese Codigo Empleado:"<<endl;
						cin>>e;
						Procesos::agregar(c,cl,z,d,i,f,e);
						break;
					case 2:
						Procesos::lectura();
						break;
					case 3:
						Procesos::borrar();
						break;
					case 4:
						Procesos::guardar();
						break;
					default:
						cout<<"Opcion Invalida...!!!"<<endl;
				}
			}while(pro!=0);
		}
		
		void agregar(int cod, int clien, int cal, string des,string ini, string fin,int emp){
			L = new Procesos();
		
			L->codigo=cod;
			L->cliente=clien;
			L->calzado=cal;
			L->descripcion=des;
			L->inicio=ini;
			L->final=fin;
			L->empleado=emp;
			
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
		    
		    archivo.open("c:\\archivo\\Procesos.txt",ios::out|ios::in);//abrimos archivo en lectura
		 
			if(!archivo.is_open()){
				cout<<"No se pudo abrir el Archivo";
				cout<<"Cargando Registros en Memoria";
				
				L=I;
				while(L!=NULL){
					cout<<"Codigo:  "<<L->codigo<<endl;
					cout<<"Cliente:  "<<L->cliente<<endl;
					cout<<"Calzado: "<<L->calzado<<endl;
					cout<<"Descripcion: "<<L->descripcion<<endl;
					cout<<"Fecha Inicio: "<<L->inicio<<endl;
					cout<<"Fecha Final: "<<L->final<<endl;
					cout<<"Empleado: "<<L->empleado<<endl;
					
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
			archivo.open("c:\\archivo\\Procesos.txt",ios::out|ios::app);//abrimos archivo a escribir
			
			while(L!=NULL){
				archivo<<L->codigo<<"\n";
				archivo<<L->cliente<<"\n";
				archivo<<L->calzado<<"\n";
				archivo<<L->descripcion<<"\n";
				archivo<<L->inicio<<"\n";
				archivo<<L->final<<"\n";
				archivo<<L->empleado<<"\n";
				
				L=L->sig;
			}
			
			archivo.close();
		}
			
		void borrar(){
			system("del c:\\archivo\\Procesos.txt");
		}
};

#endif
