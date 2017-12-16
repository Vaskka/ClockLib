#include "stdafx.h"
#include "Point.h"


Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point::Point(int X, int Y)
{
	this->x = X;
	this->y = Y;
}

//设置x
void Point::setX(int x)
{
	this->x = x;
}

//设置y
void Point::setY(int y)
{
	this->y = y;
}

//获得x
int Point::getX()
{
	return this->x;
}

//获得y
int Point::getY()
{
	return this->y;
}

//得到拷贝副本
Point * Point::PointClone()
{
	Point * newPoint = new Point();
	newPoint->setX(this->x);
	newPoint->setY(this->y);

	return newPoint;
}

Point::~Point()
{
}
