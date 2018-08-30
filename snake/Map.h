#pragma once
#ifndef MAP_H
#define MAP_H
#include"Picture.h"
#include"Snake.h"

class Map :public IPicture
{
public:
	//h , w : The internal height and width of the map , they are not the actual size (actual size=w\h+2)
	//bd : The map is surrounded by the char
	//x , y :When use dispaly() , it will start to print at (x , y)
	//fill :  When others use draw() , it  fill the margin that the arg w of the draw() is great than map's width() (PS:It isn't the w of the Map())
	Map(unsigned int h=20, unsigned int w=30, char bd = '+', short  x = 0, short y = 0, char fill = ' ');

	//Return the actual height of map(the value should be equal to h+2,it include the upper and bottom border) 
	virtual unsigned int height()const;

	//Return the actual height of map(the value should be equal to h+2,it include the upper and bottom border) 
	virtual unsigned int width()const;

	//fill : Fill the internal content of map by the char
	void fill(char fill =' ');

	//To test a 2D coordinate is out of the map's border or not
	//If it is,return true
	bool is_out(const Body& bd)const;

	//body : the list of 2D coordinates to fill
	//fill : fill by the char
	void update_data(const list<Body>& body,char fill);

	//body : The 2D coordinates to fill
	//fill : fill by the char
	void update_position(const Body& bd,char fill);

	//out : output stream
	//the line is relative to  caller
	virtual void draw(ostream& out, unsigned int line, unsigned int w)const;

	virtual ~Map();
private:
	Map(const Map& map);

	Map & operator=(const Map& map);

	//A array [h][w] , which is to present
	char* data;

	//The map is surrounded by the char
	char border;

	// The internal height and width of the map
	unsigned int h, w;
};
#endif // !MAP_H
