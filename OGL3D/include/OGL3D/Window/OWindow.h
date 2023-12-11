#pragma once
class OWindow
{

public:


	OWindow();
	~OWindow();
	
	//makes null handle of the window
	void onDestroy();

	//checks if the window is closed, thise will help close game if window is closed
	bool isClosed();

private:

	void* m_handle = nullptr;
};

