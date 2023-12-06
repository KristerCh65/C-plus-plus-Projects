#ifndef CLIENTES_H
#define CLIENTES_H

#include <windows.h>
#define CL_BUTTON 1

class Clientes
{
	public:
		
	/*	HWND clientes;

Aquí es donde va toda la entrada a la ventana 
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
		
		/*Se analizan los casos, si el mensaje es destroy que pare 
	
	switch(Message) {
		case WM_CREATE:{
			
			break;
		}
		
		case WM_COMMAND:{
			
			if(LOWORD(wParam)==CL_BUTTON){
				clientes;
			}
			
			break;
		}
		
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
	/* para procesar todo los demas mensaajes
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* Donde se ejecutaran 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* propiedades de la estructura de las ventanas 
	MSG msg; locacion temporal de los mensajes 

	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* aqui es donde se enviaraan los mensajes 
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+2);
	wc.lpszClassName = "Proyecto";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);  cargar un icino standar */
/*	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	
	clientes = CreateWindow("Proyecto","Shoe Assistant",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
	/*	CW_USEDEFAULT, /* y 
		800, /* ancho 
		550, /* alto */
	/*	NULL,NULL,hInstance,NULL);

	if(ventana == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	while(GetMessage(&msg, NULL, 0, 0) > 0) { 
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}*/
		
	protected:
};

#endif
