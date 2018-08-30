#pragma once
#ifndef FOOD_H
#define FOOD_H
#include "Snake.h"
#include<cstdlib>
#include<ctime>

class Food
{
public:
	Food(unsigned int x=0, unsigned int y=0);
	virtual Body get_position();
	void reset(unsigned int w, unsigned int h);
	virtual ~Food();
private:
	unsigned int x, y;
};
#endif // !FOOD_H