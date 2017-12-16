#pragma once
#include "Pointer.h"

class HourPointer :
	public Pointer
{
private:

	//根据起点终点得到长度
	void setLength();

public:

	int getLength();

	HourPointer(int bx, int by, int fx, int fy);
	HourPointer(int bx, int by);
	HourPointer();
	~HourPointer();
};

