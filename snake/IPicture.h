#pragma once
#ifndef IPICTURE_H
#define IPICTURE_H
#include<iostream>
#include<Windows.h>
using std::endl;
using std::ostream;
//ͼƬ�ӿ���
class IPicture
{
public:
	//ͼƬ�߶�
	virtual unsigned int height()const = 0;

	//ͼƬ���
	virtual unsigned int width()const = 0;

	//fillΪͼƬ�հ�����ַ�
	IPicture(short x = 0, short y = 0, char fill = ' ');

	virtual ~IPicture() {}

	//���ȫ��ͼƬ��Ϣ
	virtual void display(ostream& out)const;


	//ָ������߶�ĳһ��ͼƬ��Ϣ
	//line����ָ���У�����ͼƬ�߶�ʱ����fill_char��䣩��width��������Ŀ�ȣ�����ͼƬ���ʱ����fill_char��䣩
	virtual void draw(ostream& out, unsigned int line, unsigned int width)const = 0;

	//����ͼƬ�հ�����ַ�
	virtual void set_fill(char fill) { fill_char = fill; }

	//������ʾ��λ��
	virtual void set_position(short x, short y) { this->x = x; this->y = y; };
protected:
	//�հ�����ַ�
	char fill_char;
	short x, y;
};
#endif // !IPICTURE_H

