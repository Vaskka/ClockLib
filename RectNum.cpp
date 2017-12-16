#include "stdafx.h"
#include "RectNum.h"
#include "Point.h"
#include <cmath>


void RectNum::setTraditionalRECT()
{
	//极坐标转直角坐标
	int x = this->clockCenterPoint->getX() + this->radius * cos((90 - this->angle));
	int y = this->clockCenterPoint->getY() - this->radius * sin((90 - this->angle));
	
	
	//获得传统矩形的4个参数
	this->left_x = x - this->half_length;
	this->top_y = y - this->half_width;
	this->right_x = x + this->half_length;
	this->bottom_y = y + this->half_width;

	//获得传统矩形
	this->traditionalRECT = { this->left_x, this->top_y, this->right_x, this->bottom_y };

}

//获得矩形长
int RectNum::getLength()
{
	return this->half_length * 2;
}

//获得矩形宽
int RectNum::getWidth()
{
	return this->half_width * 2;
}

//获得传统矩形
RECT RectNum::getRECT()
{
	return this->traditionalRECT;
}

//默认构造函数
RectNum::RectNum()
{
	this->clockCenterPoint = new Point();
	this->left_x = 0;
	this->top_y = 0;
	this->right_x = 0;
	this->bottom_y = 0;
	this->radius = 0;
	this->angle = 0;
	this->half_length = 0;
	this->half_width = 0;
	this->traditionalRECT = { 0,0,0,0 };

}


RectNum::RectNum(Point* center, int r, double d, int half_l, int half_w)
{
	this->clockCenterPoint = center;
	this->radius = r;
	this->angle = d;
	this->half_length = half_l;
	this->half_width = half_w;
	
	this->setTraditionalRECT();


}

RectNum::~RectNum()
{
}
