#include "Snake.h"

int Snake::xo[4] = { -1,0,1,0 };
int Snake::yo[4] = { 0,-1,0,1 };
Snake::Snake(unsigned int x, unsigned int y, Direction d, unsigned int len):
dir(d)
{
	reset(x, y, d, len);
}
void Snake::grow()
{
	list<Body>::const_iterator i = body.end();
	i--;
	body.push_back(*i);
}
void Snake::go()
{
	body.pop_back();
	body.push_front(Body{ body.begin()->x + xo[dir],body.begin()->y + yo[dir] });
}
void Snake::turn(Direction d)
{
	Direction tmp = (unsigned int)d > 1 ? (Direction)(d - 2): (Direction)(d + 2);
	if (dir == tmp) return;
	dir = d;
	go();
}
bool Snake::is_cross()const
{
	unsigned int x = body.begin()->x, y = body.begin()->y;
	list<Body>::const_iterator i = body.begin();
	for (i++ ; i != body.end(); i++)
		if (i->x == x && i->y == y)
			return true;
	return false;
}
unsigned int Snake::get_len()const
{
	return this->body.size();
}
Body Snake::get_head() const
{
	return *body.begin();
}
void Snake::reset(unsigned int x, unsigned int y, Direction d, unsigned int len)
{
	body.resize(0);
	Body bd = { (int)x,(int)y };
	body.push_back(bd);
	list<Body>::const_iterator j = body.begin();
	for (unsigned i = 1; i < len; i++)
	{
		bd.x = j->x - xo[d];
		bd.y = j->y - yo[d];
		body.push_back(bd);
		j++;
	}
	dir = d;
}
const list<Body>& Snake::get_body()const
{
	return this->body;
}

Snake::~Snake()
{
}
