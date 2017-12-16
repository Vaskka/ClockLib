#pragma once
#include "Pointer.h"
class MinutePointer :
	public Pointer
{
private:
	void setLength();

public:

	int getLength();
	MinutePointer(int bx, int by, int fx, int fy);
	MinutePointer(int bx, int by);
	MinutePointer();
	~MinutePointer();
};

