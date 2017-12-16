/**
* 存在问题：目前钟表虽然能显示正确位置的数字， 但是这是通过在初始化数字矩形的时候强行加上3度，
*			而且在渲染数字的时候，按正常的思路结果会向前串一位，所以为了整齐强行向后串一位。
*			具体原因猜测和三角函数的double转int所造成的长度丢失有关
*/

#include "stdafx.h"
#include "Clock.h"
#include <graphics.h>
#include <cmath>
#include <exception>
#include <ctime>

//秒针 分针的单位移动量
#define DERTA_M_S_ANGLE 6
//时针的单位移动量
#define DERTA_H_ANGLE 30

//渲染钟表轮廓
void Clock::drawCircle()
{
	circle(this->centerPoint->getX(), this->centerPoint->getY(), this->r);
	graphdefaults();

}

//渲染钟表数字
void Clock::drawNum()
{

	for (int i = 0; i < 12; i++)
	{

		switch (i)
		{
		case 0:
			drawtext(_T("11"), &((this->clockRectNum[i]).getRECT()), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			graphdefaults();
			break;
		case 1:
			drawtext(_T("12"), &((this->clockRectNum[i]).getRECT()), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			graphdefaults();
			break;
		case 2:
			drawtext(_T("1"), &((this->clockRectNum[i]).getRECT()), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			graphdefaults();
			break;
		case 3:
			drawtext(_T("2"), &((this->clockRectNum[i]).getRECT()), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			graphdefaults();
			break;
		case 4:
			drawtext(_T("3"), &((this->clockRectNum[i]).getRECT()), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			graphdefaults();
			break;
		case 5:
			drawtext(_T("4"), &((this->clockRectNum[i]).getRECT()), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			graphdefaults();
			break;
		case 6:
			drawtext(_T("5"), &((this->clockRectNum[i]).getRECT()), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			graphdefaults();
			break;
		case 7:
			drawtext(_T("6"), &((this->clockRectNum[i]).getRECT()), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			graphdefaults();
			break;
		case 8:
			drawtext(_T("7"), &((this->clockRectNum[i]).getRECT()), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			graphdefaults();
			break;
		case 9:
			drawtext(_T("8"), &((this->clockRectNum[i]).getRECT()), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			graphdefaults();
			break;
		case 10:
			drawtext(_T("9"), &((this->clockRectNum[i]).getRECT()), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			graphdefaults();
			break;
		case 11:
			drawtext(_T("10"), &((this->clockRectNum[i]).getRECT()), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			graphdefaults();
			break;
		default:
			break;
		}
		
	}


}

//渲染钟表指针
void Clock::drawClockPointer()
{
	this->oneHP.drawPointerWithAngle();
	this->oneMP.drawPointerWithAngle();
	this->oneSP.drawPointerWithAngle();

}

//绘制当前钟表
void Clock::drawClock()
{
	this->drawCircle();
	this->drawNum();
	this->drawClockPointer();
}

//更新钟表(参数int currentHour：当前是几点，参数int currentMinuate：当前是几分，int currentSecond：当前是几秒)
void Clock::update(int currentHour, int currentMinuate, int currentSecond)
{
	//处理小时数 分钟数 秒数超出界限的异常
	if (currentSecond < 0 || currentSecond > 59)
		throw std::exception("秒数超出界限（应该为0~59）");
	if (currentMinuate < 0 || currentMinuate >59)
		throw std::exception("分钟数超出界限（应该为0~59）");
	if (currentHour < 0 || currentHour > 59)
		throw std::exception("小时数超出界限（应该为0~59）");

	//根据当前时间设置各指针偏转的角度（相对0时）
	this->oneSP.setAngle(DERTA_M_S_ANGLE * currentSecond);
	this->oneMP.setAngle(DERTA_M_S_ANGLE * currentMinuate);
	this->oneHP.setAngle(DERTA_H_ANGLE   * currentHour);


}


//将时针 分针 秒针重置为 00:00:00
void Clock::resetClockPointer()
{
	this->oneSP.setAngle(0);
	this->oneMP.setAngle(0);
	this->oneHP.setAngle(0);

}


//钟表主循环
void Clock::runClock()
{
	int hour = 0;
	int min = 0;
	int sec = 0;

	//声明描述时间的结构体
	struct tm *newTime;
	time_t now;

	//初始化画布
	initgraph(this->canvasXLength, this->canvasYLength);

	while (true)
	{
		time(&now);
		newTime = localtime(&now);

		hour = newTime->tm_hour;
		//钟表只需讨论12小时制
		if (hour > 12)
			hour -= 12;

		//获得分钟数 秒数
		min = newTime->tm_min;
		sec = newTime->tm_sec;

		//更新当前钟表
		update(hour, min, sec);

		//绘制当前钟表
		this->drawClock();
		//每一秒更新一次
		Sleep(1000);
		//重置钟表指针
		this->resetClockPointer();

		//清屏
		cleardevice();

	}

}


//默认构造函数
Clock::Clock()
{
	this->canvasXLength = 0;
	this->canvasYLength = 0;

	this->centerPoint = new Point();
	this->r = 0;
	this->rNum = 0;
	this->hourPointerLength = 0;
	this->minuatePointerLength = 0;
	this->secondPointerLength = 0;

}


//构造钟表的新实例
Clock::Clock(int canvas_x, int canvas_y, int center_x, int center_y, int r)
{
	if (center_x + r > canvas_x || center_y + r > canvas_y)
		throw std::exception("画布长高设置过小或钟表位置半径参数设置不当导致显示不完全的异常");


	//初始化画布长高属性
	this->canvasXLength = canvas_x;
	this->canvasYLength = canvas_y;

	//初始化钟表中心和钟表半径
	this->centerPoint = new Point(center_x, center_y);
	this->r = r;

	//得到时针 分针 秒针的长度
	this->hourPointerLength = this->r * HOURPOINTER_LENGTH_MULTIPLE;
	this->minuatePointerLength = this->r * MINUATEPOINTER_LENGTH_MULTIPLE;
	this->secondPointerLength = this->r * SECONDPOINTER_LENGTH_MULTIPLE;

	int bx, by, fx, fy;
	bx = this->centerPoint->getX();
	by = this->centerPoint->getY();
	fx = bx;

	//得到时针的对象
	fy = by - this-> hourPointerLength;
	this->oneHP = HourPointer(bx, by, fx, fy);
	
	//得到分针对象
	fy = by - this->minuatePointerLength;
	this->oneMP = MinutePointer(bx, by, fx, fy);

	//得到秒针对象
	fy = by - this->secondPointerLength;
	this->oneSP = SecondPointer(bx, by, fx, fy);

	this->rNum = this->r * RNUM_MULTIPLE;

	//得到承装数字的矩形
	for (int i = 0; i < 12; i++)
	{
		this->clockRectNum[i] = RectNum(this->centerPoint->PointClone(),
										this->rNum,
										(30 * i - 3) * 3.14 / 180,
										NUMRECT_HALF_LENGTH, NUMRECT_HALF_WIDTH);

	}

}


Clock::~Clock()
{
}
