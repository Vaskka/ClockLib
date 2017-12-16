#pragma once

//描述点的类（x，y）
class Point
{
private:
	//横坐标
	int x;
	//纵坐标
	int y;

public:
	Point();

	Point(int X, int Y);

	//设置x
	void setX(int x);
	//设置y
	void setY(int y);

	//获得x
	int getX();
	//获得y
	int getY();

	//得到拷贝副本
	Point* PointClone();

	~Point();
};

