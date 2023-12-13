#pragma once
#include <OGL3D/OPreReq.h>

//Vector used for colors
class OVec4
{
public:

	OVec4() {};

	//parametirized constructor
	OVec4(f32 x, f32 y, f32 z, f32 w): x(x),y(y),z(z),w(w)
	{
		
	};
	~OVec4() {};

	f32 x = 0, y = 0, z = 0, w = 0;
};