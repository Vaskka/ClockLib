#include "stdafx.h"
#include "Pointer.h"
#include <graphics.h>
#include <cmath>


//获得指针转角
int Pointer::getAngle()
{
	return this->angle;
}

//设置指针转角
void Pointer::setAngle(int d)
{
	this->angle = d;
}

//画出钟表指针
void Pointer::drawPointer()
{
	line(basePoint->getX(), basePoint->getY(), finalPoint->getX(), finalPoint->getY());
	graphdefaults();

}

//用指针的顺时针转角画出钟表指针
void Pointer::drawPointerWithAngle()
{
	//cmath库sin cos 以弧度制计算，这里进行换算
	int fx = this->basePoint->getX() + this->length * cos((90 - this->angle) * 3.14 / 180);
	int fy = this->basePoint->getY() - this->length * sin((90 - this->angle) * 3.14 / 180);

	//画线代替钟表指针
	line(basePoint->getX(), basePoint->getY(), fx, fy);

}

//获得终点Point对象
Point * Pointer::getFinalPoint()
{
	return this->finalPoint;
}

//获得转轴Point对象
Point * Pointer::getBasePoint()
{
	return this->basePoint;
}

//设置转轴点
void Pointer::setBasePoint(Point * p)
{
	this->basePoint = p;
}

//设置终点
void Pointer::setFinalPoint(Point * p)
{
	this->finalPoint;
}

Pointer::Pointer()
{
	this->angle = 0;
	this->basePoint = new Point(0, 0);
	this->finalPoint = new Point(0, 0);
}


Pointer::~Pointer()
{
}
