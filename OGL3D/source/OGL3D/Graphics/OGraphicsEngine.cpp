#include "OGL3D/Graphics/OGraphicsEngine.h"
#include <glad/glad_wgl.h>
#include <glad/glad.h>
#include <stdexcept>
#include <assert.h>

OGraphicsEngine::OGraphicsEngine()
{
	//Sets initial parameters for game window
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = L"OGL3DDummyWindow";

	//DEFINES THE MESSAGE CALLBACK 
	wc.lpfnWndProc = DefWindowProc;
	
	wc.style = CS_OWNDC;

	//do assert check to see if my window class was created correctly
	auto classId = RegisterClassEx(&wc);
	assert(classId);


	//Window handle---------->Style, class name,    window name,              style, 
	auto dummyWindow = CreateWindowEx(NULL, MAKEINTATOM(classId), L"PedroEPerezN C++ Game", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
		//-------------------------------SIZE-----------------------------Not used at the moment
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, NULL, NULL);

	assert(dummyWindow);

	auto dummyDC = GetDC(dummyWindow);
	
	PIXELFORMATDESCRIPTOR pixelFormatDesc = {};
	pixelFormatDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pixelFormatDesc.nVersion = 1;
	pixelFormatDesc.iPixelType = PFD_TYPE_RGBA;
	pixelFormatDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pixelFormatDesc.cColorBits = 32;
	pixelFormatDesc.cAlphaBits = 8;
	pixelFormatDesc.cDepthBits = 24;
	pixelFormatDesc.cStencilBits = 8;
	pixelFormatDesc.iLayerType = PFD_MAIN_PLANE;
	
	auto pixelFormat = ChoosePixelFormat(dummyDC, &pixelFormatDesc);
	SetPixelFormat(dummyDC,pixelFormat,&pixelFormatDesc);

	auto dummyContext = wglCreateContext(dummyDC);
	assert(dummyContext);

	wglMakeCurrent(dummyDC, dummyContext);

	if (!gladLoadWGL(dummyDC)) 
	{
		throw std::runtime_error("Load Error in OGraphicsEngine -- gladLoadWGL failed");
	}

	if (!gladLoadGL())
	{
		throw std::runtime_error("Load Error in OGraphicsEngine -- gladLoadGL failed");
	}

	wglMakeCurrent(dummyDC, 0);
	wglDeleteContext(dummyContext);
	ReleaseDC(dummyWindow, dummyDC);
	DestroyWindow(dummyWindow);
}

OGraphicsEngine::~OGraphicsEngine()
{
}

void OGraphicsEngine::clear(const OVec4& color)
{
	glClearColor(color.x, color.y, color.z, color.w);
	glClear(GL_COLOR_BUFFER_BIT);
}
