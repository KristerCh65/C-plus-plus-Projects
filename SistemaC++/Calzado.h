#ifndef CALZADO_H
#define CALZADO_H
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Calzado.h"
#include "string"
using namespace std;

class Calzado
{
	public:
		Calzado *I, *L, *F;
		Calzado *sig;
		Calzado *ant;
		int zap;
		int codigo, c;
		string marca, m;
		string estilo, s;
		string color, cl;
		string genero, g;
		int ubicacion, u;
		
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
				cin>>zap;
				
				switch(zap){
					case 1:
						cout<<"Ingrese Codigo:"<<endl;
						cin>>c;
						cout<<"Ingrese Marca:"<<endl;
						cin>>m;
						cout<<"Ingrese Estilo:"<<endl;
						cin>>s;
						cout<<"Ingrese Color:"<<endl;
						cin>>cl;
						cout<<"Tipo Genero:"<<endl;
						cin>>g;
						cout<<"Codigo Ubicacion:"<<endl;
						cin>>u;
						Calzado::agregar(c,m,s,cl,g,u);
						break;
					case 2:
						Calzado::lectura();
						break;
					case 3:
						Calzado::borrar();
						break;
					case 4:
						Calzado::guardar();
						break;
					default:
						cout<<"Opcion Invalida...!!!"<<endl;
				}
			}while(zap!=0);
		}
		
		void agregar(int cod, string mar, string  stl, string  col,string gen, int ub){
			L = new Calzado();
		
			L->codigo=cod;
			L->marca=mar;
			L->estilo=stl;
			L->color=col;
			L->genero=gen;
			L->ubicacion=ub;
			
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
		    
		    archivo.open("c:\\archivo\\Calzado.txt",ios::out|ios::in);//abrimos archivo en lectura
		 
			if(!archivo.is_open()){
				cout<<"No se pudo abrir el Archivo";
				cout<<"Cargando Registros en Memoria";
				
				L=I;
				while(L!=NULL){
					cout<<"Codigo:  "<<L->codigo<<endl;
					cout<<"Marca:  "<<L->marca<<endl;
					cout<<"Estilo: "<<L->estilo<<endl;
					cout<<"Color: "<<L->color<<endl;
					cout<<"Tipo Genero: "<<L->genero<<endl;
					cout<<"Ubicacion: "<<L->ubicacion<<endl;
					
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
			archivo.open("c:\\archivo\\Calzado.txt",ios::out|ios::app);//abrimos archivo a escribir
			
			while(L!=NULL){
				archivo<<L->codigo<<"\n";
				archivo<<L->marca<<"\n";
				archivo<<L->estilo<<"\n";
				archivo<<L->color<<"\n";
				archivo<<L->genero<<"\n";
				archivo<<L->ubicacion<<"\n";
				
				L=L->sig;
			}
			
			archivo.close();
		}
			
		void borrar(){
			system("del c:\\archivo\\Calzado.txt");
		}
};

#endif
