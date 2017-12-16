#include "stdafx.h"
#include "HourPointer.h"
#include <cmath>

//根据起点终点得到长度
void HourPointer::setLength()
{
	this->length = (int)sqrt(pow((this->basePoint->getX() 
								- this->finalPoint->getX()), 2) 
							+ pow((this->basePoint->getY() 
								- this->finalPoint->getY()), 2));
}

//得到时针的长度
int HourPointer::getLength()
{
	return this->length;
}

//构造函数的几种重载
HourPointer::HourPointer(int bx, int by, int fx, int fy)
{
	this->basePoint = new Point(bx, by);
	this->finalPoint = new Point(fx, fy);
	setLength();
}

HourPointer::HourPointer(int bx, int by)
{
	this->basePoint = new Point(bx, by);
	this->finalPoint = new Point(0, 0);
	setLength();
}

HourPointer::HourPointer()
{
	this->length = 0;
}


HourPointer::~HourPointer()
{
}
