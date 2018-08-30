#pragma once
#ifndef IPICTURE_H
#define IPICTURE_H
#include<iostream>
#include<Windows.h>
using std::endl;
using std::ostream;
//图片接口类
class IPicture
{
public:
	//图片高度
	virtual unsigned int height()const = 0;

	//图片宽度
	virtual unsigned int width()const = 0;

	//fill为图片空白填充字符
	IPicture(short x = 0, short y = 0, char fill = ' ');

	virtual ~IPicture() {}

	//输出全部图片信息
	virtual void display(ostream& out)const;


	//指定输出高度某一行图片信息
	//line标明指定行（超过图片高度时将以fill_char填充），width标明输出的宽度（超过图片宽度时将以fill_char填充）
	virtual void draw(ostream& out, unsigned int line, unsigned int width)const = 0;

	//设置图片空白填充字符
	virtual void set_fill(char fill) { fill_char = fill; }

	//设置显示的位置
	virtual void set_position(short x, short y) { this->x = x; this->y = y; };
protected:
	//空白填充字符
	char fill_char;
	short x, y;
};
#endif // !IPICTURE_H

