#include "Food.h"

Food::Food(unsigned int x, unsigned int y) :
	x(x), y(y) {}
Body Food::get_position()
{
	return Body{ (int)x,(int)y };
}
void Food::reset(unsigned int w, unsigned int h)
{
	srand((unsigned)time(NULL));
	x = rand() % w;
	y = rand() % h;
}
Food::~Food()
{
}
