#include <windows.h>
#define CL_BUTTON 1
#define Em_BUTTON 1
#define ZA_BUTTON 1
#define PR_BUTTON 1
#define UB_BUTTON 1

HWND ventana; // referencia a la ventana principal
HWND clientes;

/* Aquí es donde va toda la entrada a la ventana */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
		
		/*Se analizan los casos, si el mensaje es destroy que pare */
	
	switch(Message) {
		case WM_CREATE:{
			CreateWindow(TEXT("BUTTON"),TEXT("CLIENTES"),
			WS_CHILD | WS_VISIBLE,10,10,100,50,hwnd,(HMENU) CL_BUTTON, NULL, NULL);
			
			CreateWindow(TEXT("BUTTON"),TEXT("EMPLEADOS"),
			WS_CHILD | WS_VISIBLE,10,70,100,50,hwnd,(HMENU) Em_BUTTON, NULL, NULL);
			
			CreateWindow(TEXT("BUTTON"),TEXT("PROCESOS"),
			WS_CHILD | WS_VISIBLE,10,130,100,50,hwnd,(HMENU) PR_BUTTON, NULL, NULL);
			
			CreateWindow(TEXT("BUTTON"),TEXT("CALZADO"),
			WS_CHILD | WS_VISIBLE,10,190,100,50,hwnd,(HMENU) ZA_BUTTON, NULL, NULL);
			
			CreateWindow(TEXT("BUTTON"),TEXT("UBICACIÓN"),
			WS_CHILD | WS_VISIBLE,10,250,100,50,hwnd,(HMENU) UB_BUTTON, NULL, NULL);
			
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
		
	/* para procesar todo los demas mensaajes */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* Donde se ejecutaran */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* propiedades de la estructura de las ventanas */
	MSG msg; /* locacion temporal de los mensajes */

	/* inicializar en cero la estructura y establecer las cosas que queremos modificar */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* aqui es donde se enviaraan los mensajes */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+2);
	wc.lpszClassName = "Proyecto";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* cargar un icino standar */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	
	ventana = CreateWindow("Proyecto","Shoe Assistant",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		900, /* ancho */
		650, /* alto */
		NULL,NULL,hInstance,NULL);
		
	clientes = CreateWindow("Proyecto","Clientes",WS_CHILD | WS_VISIBLE,
				120,10,800,500,
				NULL,(HMENU) NULL,hInstance,NULL);

	if(ventana == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		
	Este es el corazón de nuestro programa donde se procesan todas las entradas y
	enviado a WndProc. Tenga en cuenta que GetMessage bloquea el flujo de código hasta que recibe algo, por lo que
	este ciclo no producirá una CPU excesivamente alta
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* si ningun  error es recibido... */
		TranslateMessage(&msg); /* Traducir códigos clave a caracteres si están presentes */
		DispatchMessage(&msg); /* mandarlos a WndProc */
	}
	return msg.wParam;
}
