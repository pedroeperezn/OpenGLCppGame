#include <OGL3D/Window/OWindow.h>
#include <Windows.h>
#include <assert.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) 
	{

	case WM_DESTROY:
	{
		OWindow* window = (OWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
		window->onDestroy();
		break;
	}

	default:

		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	return NULL;
}

OWindow::OWindow()
{
	//Sets initial parameters for game window
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = L"OGL3DWindow";

	//DEFINES THE MESSAGE CALLBACK 
	wc.lpfnWndProc = &WndProc;

	//do assert check to see if my window class was created correctly
	assert(RegisterClassEx(&wc));

	//set size of the window, we want to define the user available space, not overall window size
	RECT rc = { 0,0,1024,768 };
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

	//Window handle---------->Style, class name,    window name,              style, 
	m_handle = CreateWindowEx(NULL, L"OGL3DWindow", L"PedroEPerezN C++ Game",WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
	//-------------------------------SIZE-----------------------------Not used at the moment
		CW_USEDEFAULT,CW_USEDEFAULT,rc.right-rc.left,rc.bottom-rc.top, NULL,NULL,NULL,NULL);
	
	//check handle
	assert(m_handle);

	//Store window instance pointer in a data structure that can be accessed easier
	SetWindowLongPtr((HWND)m_handle, GWLP_USERDATA, (LONG_PTR)this);

	//show window
	ShowWindow((HWND)m_handle,SW_SHOW);
	UpdateWindow((HWND)m_handle);

}

OWindow::~OWindow()
{
	DestroyWindow((HWND)m_handle);
}

bool OWindow::isClosed()
{
	return !m_handle;
}

void OWindow::onDestroy()
{
	m_handle = nullptr;
}
