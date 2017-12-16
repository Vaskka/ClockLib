#include "stdafx.h"
#include "MinutePointer.h"
#include <cmath>


//根据起点终点得到长度
void MinutePointer::setLength()
{
	this->length = (int)sqrt(pow((this->basePoint->getX()
		- this->finalPoint->getX()), 2)
		+ pow((this->basePoint->getY()
			- this->finalPoint->getY()), 2));
}

//得到分针的长度
int MinutePointer::getLength()
{
	return this->length;
}

MinutePointer::MinutePointer(int bx, int by, int fx, int fy)
{
	this->basePoint = new Point(bx, by);
	this->finalPoint = new Point(fx, fy);
	setLength();
}

MinutePointer::MinutePointer(int bx, int by)
{
	this->basePoint = new Point(bx, by);
	this->finalPoint = new Point(0, 0);
	setLength();
}

MinutePointer::MinutePointer()
{
	this->length = 0;
}


MinutePointer::~MinutePointer()
{
}
