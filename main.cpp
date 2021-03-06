/*******************************************************************************************
   Hello World ! - pogramma base Windows
   Code by Leonardo Berti (c) 2003
********************************************************************************************/


#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{

	static TCHAR szAppName[]=TEXT("Hello World!");
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;

	//definisce lo stile della finestra
	wndclass.style=CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc=WndProc;
	wndclass.cbClsExtra=0;
	wndclass.cbWndExtra=0;
	wndclass.hInstance=hInstance;
	wndclass.hIcon=LoadIcon(NULL,IDI_APPLICATION); //icona stndard
    wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);
	wndclass.hbrBackground=(HBRUSH) GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName=NULL;
	wndclass.lpszClassName=szAppName; //nome applicazione

	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL,TEXT("Questo programma richiede Windows NT !"),szAppName,MB_ICONEXCLAMATION);
		return 0;
	}

	//crea la finestra
    hwnd=CreateWindow(szAppName,
					  TEXT("Programma Hello World!"), //titolo della finestra
					  WS_OVERLAPPEDWINDOW, //stile
					  CW_USEDEFAULT, //posizione x iniziale
					  CW_USEDEFAULT, //y iniziale
					  CW_USEDEFAULT, //larghezza iniziale
					  CW_USEDEFAULT, //altezza iniziale
					  NULL,          //handle finestra genitore
					  NULL,          //handle del menu
					  hInstance,     //handle dell'istanza del programma
					  NULL);

	ShowWindow(hwnd,nCmdShow);
	UpdateWindow(hwnd);

	//ciclo messaggi
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

//Window procedue - gestisce i messaggi della finestra
LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch(message)
	{
		case WM_CREATE:

			return 0;

		case WM_PAINT:

			hdc=BeginPaint(hwnd,&ps);
			EndPaint(hwnd,&ps);
			return 0;


		case WM_DESTROY:

			PostQuitMessage(0);
			return 0;
	}
    //procedura predefinita
	return DefWindowProc(hwnd,message,wParam,lParam);
}















