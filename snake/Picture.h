#pragma once
#ifndef PICTURE_H
#define PICTURE_H
#include<iostream>
#include "IPicture.h"
#include <string>
#include <vector>
#include <memory>
#include<Windows.h>

using std::ostream;
using std::string;
using std::shared_ptr;
using std::endl;
using std::vector;
//图片基类，继承IPicture接口
class Picture :public IPicture
{
public:
	friend ostream& operator<<(ostream& out, const Picture& p);
	Picture(IPicture* i);
	virtual unsigned int height()const;
	virtual unsigned int width()const;
	virtual ~Picture();
	virtual void draw(ostream & out, unsigned int line, unsigned int w) const;
private:
	shared_ptr<IPicture> m_p;
};

class StringPicture :public IPicture
{
public:
	StringPicture(const string& soure, char sp = ' ', short  x=0, short y=0, char fill = ' ');
	virtual unsigned int height()const;
	virtual unsigned int width()const;
	virtual void draw(ostream& out, unsigned int line, unsigned int w)const;
	virtual ~StringPicture();
private:
	unsigned int max_len;
	vector<string> data;
};

class Frame :public IPicture
{
public:
	Frame(const Picture& p, char bd = '*', short  x=0, short y=0,  char fill = ' ');
	virtual unsigned int height()const;
	virtual unsigned int width()const;
	virtual ~Frame();
	virtual void draw(ostream& out, unsigned int line, unsigned int w)const;
private:
	char boder;
	Picture m_p;
};

class VPanel :public IPicture
{
public:
	VPanel(const Picture& up, const Picture& center, const Picture& down, short x = 0, short y = 0, char fill = ' ');
	unsigned int height() const;
	virtual unsigned int width()const;
	virtual ~VPanel();
	virtual void draw(ostream& out, unsigned int line, unsigned int w)const;
private:
	Picture m_up, m_center, m_down;
};

class HPanel :public IPicture
{
public:
	HPanel(const Picture& left, const Picture& center, const Picture& right, short x = 0, short y = 0, char fill = ' ');
	unsigned int height() const;
	virtual unsigned int width()const;
	virtual ~HPanel();
	virtual void draw(ostream& out, unsigned int line, unsigned int w)const;
private:
	Picture m_left, m_center, m_right;
};

#endif // !PICTURE_H


