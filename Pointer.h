#pragma once
#include <graphics.h>
#include "Point.h"


class Pointer
{
protected:
	//描述指针相对0点的顺时针转角
	int angle;

	//描述指针的长度
	int length;

	//描述钟表指针的转轴
	Point* basePoint;

	//描述中标指针的终点
	Point* finalPoint;


public:
	//获得指针转角
	int getAngle();

	//设置指针转角
	void setAngle(int d);

	//画出钟表指针
	void drawPointer();

	//用指针的顺时针转角画出钟表指针
	void drawPointerWithAngle();

	//获得终点Point对象
	Point* getFinalPoint();
	//获得转轴Point对象
	Point* getBasePoint();

	//设置转轴点
	void setBasePoint(Point* p);
	//设置终点
	void setFinalPoint(Point* p);

	Pointer();
	~Pointer();
};

