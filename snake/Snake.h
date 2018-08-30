#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#include<list>

using std::list;

//The 2D coordinate of a unit of snake or food , relative to the map
struct Body
{
	int x, y;
	bool operator==(const Body& x)
	{
		return this->x== x.x && this->y == x.y;
	}
};

//The current orientation of the Snake
//Left=0 , Up=1 , Right=2 , Down=3
enum Direction
{
	L = 0, U, R, D
};

//The snake
class Snake
{
public:
	//x , y : The coordinates of the serpent's head
	//d : The primary orientation of the snake . 
	//len : The primary length of snake Y of the snake.
	Snake(unsigned int x, unsigned int y, Direction d, unsigned int len);

	//Help the snake to grow( the snake:"Wow ! I like it ! ")
	virtual void grow();

	//Let we go . (make snake a step forward)
	virtual void go();

	//d : To get the snake in this direction . (the snake:"Emmmm,the food is near me . ")
	virtual void turn(Direction d);

	//To tell you whether the snake bite itself
	//If it did,return true (Oh, poor guy...)
	virtual bool is_cross()const;

	//To tell you how long the snake is
	//Return the length (the snake:"Actually , I don't care it .")
	unsigned int get_len()const;

	//To tell you where the snake's head is
	//Return the 2D coordinates (the snake:"What the f**k! How dare you want my head ? ")
	Body get_head()const;

	//x , y : The coordinates of the serpent's head
	//d: The primary orientation of the snake 
	//len : The primary length of snake Y of the snake
	void reset(unsigned int x, unsigned int y, Direction d, unsigned int len);

	//Get 2D coordinates of all parts of shake 
	//Return list of coordinates (the snake:"Although you get my body, you can't get my heart ! ")
	const list<Body>& get_body()const;

	//Oh , see you again
	virtual ~Snake();
private:
	//Use the value of the Direction d as the index of to move in the x-axis direction
	static int xo[4];

	//The same is xo,Use the value of the Direction d as the index of to move in the y-axis direction
	static int yo[4];

	//The current orientation of the Snake('s head)
	Direction dir;

	//The body of the snake
	list<Body> body;
};
#endif // !SNAKE_H
