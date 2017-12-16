#pragma once
#include "Point.h"
#include "SecondPointer.h"
#include "MinutePointer.h"
#include "HourPointer.h"
#include "RectNum.h"
//规定装数字的矩形半长为10
#define NUMRECT_HALF_LENGTH 10
//规定装数字的矩形半宽为10
#define NUMRECT_HALF_WIDTH  10

//规定时针长度是半径的 0.2倍
#define HOURPOINTER_LENGTH_MULTIPLE    0.2
//规定分针长度是半径的 0.6倍
#define MINUATEPOINTER_LENGTH_MULTIPLE 0.6
//规定秒针长度是半径的 0.8倍
#define SECONDPOINTER_LENGTH_MULTIPLE  0.8
//默认表盘中心到表盘数字的距离是半径的 0.9 倍
#define RNUM_MULTIPLE 0.9


class Clock
{
private:
	//画布长
	int canvasXLength;

	//画布高
	int canvasYLength;


	//钟表中心Point
	Point* centerPoint;

	//时针
	HourPointer oneHP;

	//分针
	MinutePointer oneMP;

	//秒针
	SecondPointer oneSP;

	//时针长
	int hourPointerLength;

	//分针长
	int minuatePointerLength;

	//秒针长
	int secondPointerLength;

	//表盘的半径
	int r;

	//表盘中心到表盘数字的距离
	int rNum;

	//用于盛装数字的12个矩形
	RectNum clockRectNum[12];

	//渲染钟表轮廓
	void drawCircle();

	//渲染钟表数字
	void drawNum();

	//渲染钟表指针
	void drawClockPointer();

	//绘制当前钟表
	void drawClock();

	//更新钟表(参数int currentHour：当前是几点，参数int currentMinuate：当前是几分，int currentSecond：当前是几秒)
	void update(int currentHour, int currentMinuate, int currentSecond);

	//将时针 分针 秒针重置为 00:00:00
	void resetClockPointer();

public:

	//钟表主循环
	void runClock();

	Clock();
	Clock(int canvas_x_length, int canvas_y_length, int center_x, int center_y, int r);
	~Clock();
};

