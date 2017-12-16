#pragma once
#include "graphics.h"
#include "Point.h"

//描述承载钟表数字的矩形
class RectNum
{

private:
	//钟表的中心
	Point* clockCenterPoint;

	//exsyX中RECT对象的坐标
	int left_x;
	int top_y;
	int right_x;
	int bottom_y;
	
	//容易使用的极坐标(钟表中心为极点，当前矩形的中心坐标，角度规定角度制，且相对与00:00:00的顺时针角度)
	int radius;
	double angle;

	//矩形的半长
	int half_length;
	//矩形的半宽
	int half_width;

	//传统矩形
	RECT traditionalRECT;


	//得到传统矩形
	void setTraditionalRECT();


public:

	//获得矩形的长
	int getLength();
	//获得矩形的宽
	int getWidth();

	//获得当前极坐标下的传统矩形
	RECT getRECT();


	RectNum();
	RectNum(Point* center,int r, double d, int half_l, int half_w);

	~RectNum();
};

