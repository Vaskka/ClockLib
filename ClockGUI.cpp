// ClockGUI.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Clock.h"
#include <graphics.h>
#define WIDTH  600
#define HEIGHT 600
#define RADIUS 200

int main()
{

	Clock myClock(WIDTH, HEIGHT, WIDTH / 2, HEIGHT / 2, RADIUS);

	//进入钟表主循环
	myClock.runClock();


    return 0;
}

