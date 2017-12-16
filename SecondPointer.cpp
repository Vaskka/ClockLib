#include "stdafx.h"
#include "SecondPointer.h"
#include <cmath>


//根据起点终点得到长度
void SecondPointer::setLength()
{
	this->length = (int)sqrt(pow((this->basePoint->getX()
		- this->finalPoint->getX()), 2)
		+ pow((this->basePoint->getY()
			- this->finalPoint->getY()), 2));
}

int SecondPointer::getLength()
{
	return this->length;
}

SecondPointer::SecondPointer(int bx, int by, int fx, int fy)
{
	this->basePoint = new Point(bx, by);
	this->finalPoint = new Point(fx, fy);
	setLength();
}

SecondPointer::SecondPointer(int bx, int by)
{
	this->basePoint = new Point(bx, by);
	this->finalPoint = new Point(0, 0);
	setLength();
}

SecondPointer::SecondPointer()
{
	this->length = 0;
}


SecondPointer::~SecondPointer()
{
}
