#pragma once
#ifndef CONTROL_H
#define CONTROL_H
#include<iostream>
#include<Windows.h>
#include<iomanip>
#include <string>
#include<conio.h>
#include "Snake.h" 
#include "Map.h" 
#include "Food.h"
using std::cout;
using std::string;
using std::endl;

class Control
{
public:
	enum State
	{
		Start, Working, Pause
	};
	Control(uint32_t delay = 5000,char bd='+',unsigned int h = 12, unsigned int w = 37, char m_fill = ' ',
		unsigned int s_x = 5, unsigned int s_y = 5, Direction d = R, unsigned int len = 2, char s_fill = '@',
		unsigned int f_x = 5, unsigned int f_y = 6, char f_fill = '#'
	);
	virtual void refresh();
	State get_state()const;
	virtual unsigned int run();
	~Control();
private:
	virtual void pause(State d);
	Control(const Control& con);
	Control & operator=(const Control& con);
	Map map;
	Snake snake;
	Food food;
	uint32_t  delay;
	char map_fill;
	char snake_fill;
	char food_fill;
	State state;
	unsigned int snake_len;
	Direction snake_d;
	unsigned int snake_x,snake_y;
	unsigned int score;
	static string state_table[];
	int * p;
};
#endif // !CONTROL_H
