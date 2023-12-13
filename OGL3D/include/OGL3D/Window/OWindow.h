#pragma once
#include <glad/glad_wgl.h>
#include <glad/glad.h>

class OWindow
{

public:


	OWindow();
	~OWindow();
	

	void MakeCurrentContext();
	void Present(bool vsync);

private:

	void* m_handle = nullptr;
	void* m_context = nullptr;
};

