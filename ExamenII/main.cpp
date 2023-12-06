#include <iostream>
#include <fstream>
#include <thread>
#include "string"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string nombre[10];
int op;
string nm;

void menu();
void agregar(string);
void Leer();
void guardar();

void hilos(int n, int t){
	while(0==0){
		if(n=1){
			menu();
			this_thread::sleep_for(chrono::milliseconds(t+100));
		}
		if(n=2){
			guardar();
			this_thread::sleep_for(chrono::milliseconds(t+100));
		}
	}
}

int main(int argc, char** argv) {
	
	thread m(hilos,1,1);
	thread g(hilos,2,10);
	
	m.join();
	g.join();
	
	return 0;
}

void menu(){
	do{
		cout<<"\t MENU"<<endl;
		cout<<"1) Agregar"<<endl;
		cout<<"2) Guardar"<<endl;
		cout<<"3) Leer"<<endl;
		cout<<"0) Salir..."<<endl;
		
		switch(op){
			case 1:
				cout<<"Ingrese Nombre"<<endl;
				cin>>nm;
				agregar(nm);
				break;
			case 2:
				guardar();
				break;
			case 3:
				Leer();
				break;
			default:
				cout<<"Opcion no valida..."<<endl;
		}
		
	}while(op!=0);
}

void agregar(string nom ){
	for(int i; i<10; i++){
		nombre[i]=nom;
	}
}

void Leer(){
	string texto;
	ofstream archivo;
	archivo.open("c:\\archivo\\nombres.txt",ios::app);
	while(!archivo.eof()){
		texto<<archivo<<"\n";
	}
	cout<<Texto<<endl;
	archivo.close();
}

void guardar(){
	ofstream archivo;
	archivo.open("c:\\archivo\\nombres.txt",ios::app);
	for(int x;x<10;x++){
		archivo<<nombre[x]<<"\n";
	}
	archivo.close();
}

