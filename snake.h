#pragma once
#ifndef _SNAKE_H_
#define _SNAKE_H_
#include <time.h>
#include <cstdlib>
#include <iostream>
//两个头文件  控制光标
#include <conio.h>
#include <Windows.h>
#define LENGTH 60
#define WIDE 20
using namespace std;
//typedef int size_t;
//一个身体的对象
//以坐标的形式表示
struct BODY
{
	int x;
	int y;
};
//蛇定义
struct SNAKE
{
	struct BODY body[WIDE * LENGTH];	//定义一个数组.
	//表示蛇的身子，body[0] -- 蛇头
	int size;	//蛇的大小
	//size<=WIDE*LENGTH;
}snake;//一个蛇对象

//食物对象
struct FOOD
{
	int x;
	int y;
}food;//一个食物对象

int score = 0;

int kx = 0;	//用户按下wasd任意一个所得到的坐标值
int ky = 0;

int lastX = 0;	//描述蛇尾的坐标，去除蛇尾
int lastY = 0;

int sleepTime = 300;
//初始化蛇
void initSnake(void);
//全局变量 snake  不需要传参数
//初始化食物
void initFood(void);

//初始化界面控件
void initUI(void);

//开始游戏
void playGame(void);

void initWall(void);//初始化墙

void showScore(void);

#endif // !_SNAKE_H_

//1。定义蛇对象，食物对象
// 
//2.初始化蛇、食物
// 
//3。 控制流程：
//	1）蛇头和墙壁的碰撞
//	2）蛇头和身体的碰撞
// //以上两种程序终止。。
//	3）蛇头和食物的碰撞
//		1》蛇身增长
//		2》食物消失--新食物产生
//		3》分数累加
//		4》移动速度增加
//	4）蛇的移动
//		自动移动
//		手动控制移动：WASD
//	5）游戏结束的时候，显示分数
		//排行榜？把数据写入文件里面。
//4.图形界面

//COORD coord{ snake.body[0].x,snake.body[0].y };
///*typedef struct _COORD {
//	SHORT X;
//	SHORT Y;
//} COORD, * PCOORD;*/
////COORD是Windows API中定义的结构
////表示一个字符在控制台屏幕上的坐标
//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
////会把光标的位置，定位到  初始化好的蛇头位置
//cout.put('@');

//蛇的移动控制
//	W:(0, -1)
//	S:(0 ,+1)
//	A:(-1, 0)
//	D:(+1, 0)

//不 回显:
//		getch()函数,接受用户输入，不回显.
//		char ch = getch();
//		包含头文件 conio.h
//		从控制台无回显的取一个字符	
// 返回值：读取的字符的ASCII码
// 
//		getchar();是构成回显的函数.

//不 阻塞:	（阻塞等待）
//		kbhit(); 不阻塞接收用户输入。
//		包含头文件 conio.h
//用法： if(kbhit()) {.....}
//返回值: 若有则返回1（非0值）,否则返回0
//以非阻塞方式，检查当前是否有键盘输入


//游戏结束的条件
//蛇头与墙壁碰撞
	/*snake.body[0].x >= 0 && snake.body[0].x < LENGTH
	&&
	snake.body[0].y >= 0 && snake.body[0].y < WIDE;*/
	//蛇头与身体的碰撞：
	//蛇头的坐标与  任意一节身体的坐标完全一致。
	//循环
	// for (int i  = 1;i<snake.size;++i)
	//if (snake.body[i].x == snake.body[0].x && snake.body[i].y == snake.body[0].y)
	//	return;//直接结束游戏;
	//蛇头和食物的碰撞：
	//if (snake.body[0].x == food.x && snake.body[0].y == food.y)
	//{
	//	蛇身增长： snake.size++;
	// 食物消失：(产生一个新的食物) initFood();
	// 加分：score+=10;
//////
	//}


//去除蛇尾:
//蛇移动之前保存蛇尾坐标。
//定义全局变量 : 1astX, 1astY;
//1astX = snake.body[snake.size - 1].X; 1astY = snake.body[snake.size - 1].Y; 
// 在initUI中，将蛇尾替换为' ',
//coord.x = 1astX;
//coord.Y = 1astY;
//在移动光标位置  那个函数
//输出一个‘ ’空格取代那个蛇尾的'*'



////去除光标:
//typedef struct _CONSOLE_CURSOR_INFO {
//	DWORD dwSize;//大小
//	BOOL bvisib1e;//是否可见
//}CONSOLE_CURSOR_INFO;
////定义结构体变量:
//	_CONSOLE_CURSOR_INFO cci;
//	cci = sizeof(cci);
//	cci.bvisib1e = FALSE;  // О假-- - 不可见
////设置光标不可见生效:
//	SetConsoleCursorInfo(GetSTDHand1er(STD_OUTPUT_HANDLE),& cci);
//	在main函数中，调用一次即可生效。


//显示分数
//p1ayGame调用结束时，打印全局score值。
//加速 :
//全局定义变量:s1eepSecond = 300;
//s1eep(s1eepSecond); 
//成功吃食物，sleepSecond -= 10;
