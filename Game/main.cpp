#include <OGL3D/Game/OGame.h>
#include <iostream>

int main() 
{
	//run game
	try 
	{
		OGame myFirstGame;
		myFirstGame.run();
		
	}

	//if game didn't ran, throw error
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}