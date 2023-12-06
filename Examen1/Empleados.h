#ifndef EMPLEADOS_H
#define EMPLEADOS_H

using namespace std;

class Empleados
{
	public:
		
		int sueldo;
		string Nombre;
		Empleados *nxt;
		
		int deducciones(){
			return (sueldo*0.05);
		}
		
		int Pagar(){
			return (sueldo-deducciones());
		}
	protected:
};

#endif
