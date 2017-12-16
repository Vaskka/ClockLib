#pragma once
#include "Pointer.h"
class SecondPointer :
	public Pointer
{
private:
	void setLength();

public:

	int getLength();
	SecondPointer(int bx, int by, int fx, int fy);
	SecondPointer(int bx, int by);
	SecondPointer();
	~SecondPointer();
};

