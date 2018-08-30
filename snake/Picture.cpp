#include"Picture.h"

ostream& operator<<(ostream& out, const Picture& p)
{
	p.m_p->display(out);

	return out;
}

//Picture
Picture::Picture(IPicture* i) :m_p(i) {}
unsigned int Picture::height()const
{
	return m_p->height();
}
unsigned int Picture::width()const
{
	return m_p->width();
}
Picture::~Picture() {  }
void Picture::draw(ostream& out, unsigned int line, unsigned int w)const
{
	m_p->draw(out, line, w);
}

//StringPicture
StringPicture::StringPicture(const string& soure, char sp, short  x, short y,  char fill) :
	IPicture(x,y,fill), max_len(0)
{
	unsigned int i = 0, j = 0;
	string tmp;

	while (i < soure.length())
	{
		while (i < soure.length() && soure[i] == sp)
			i++;
		j = i;
		while (j < soure.length() && soure[j] != sp)
			j++;
		tmp = soure.substr(i, j - i);
		data.push_back(tmp);
		max_len = tmp.length() > max_len ? tmp.length() : max_len;
		i = j;
	}
}
unsigned int StringPicture::height()const
{
	return data.size();
}
unsigned int StringPicture::width()const
{
	return max_len;
}
void StringPicture::draw(ostream& out, unsigned int line, unsigned int w)const
{
	if (line >= 0 && line < height())
	{
		out << data[line];
		if (data[line].length() < width())
			out << string(width() - data[line].length(), fill_char);
		if (width() < w)
			out << string(w - width(), fill_char);
	}
	else
		out << string(w, fill_char);
}
StringPicture:: ~StringPicture() {}

//Frame
Frame::Frame(const Picture& p, char bd, short  x, short y,  char fill) :
	IPicture(x, y, fill), boder(bd), m_p(p) {}
unsigned int Frame::height()const
{
	return m_p.height() + 2;
}
unsigned int Frame::width()const
{
	return m_p.width() + 2;
}
void Frame::draw(ostream& out, unsigned int line, unsigned int w)const
{
	if (line >= 0 && line < height())
	{
		if (line == 0 || line == height() - 1)
			out << string(width(), boder);
		else
		{
			out << boder;
			m_p.draw(out, line - 1, m_p.width());
			out << boder;
		}
		if (width() < w)
			out << string(w - width(), fill_char);
	}
	else
		out << string(w, fill_char);
}
Frame::~Frame() {}


//VPanel
VPanel::VPanel(const Picture& up, const Picture& center, const Picture& down, short  x, short y, char fill):
	IPicture(x,y,fill), m_up(up), m_center(center), m_down(down) {}
unsigned int VPanel::height()const
{
	return m_up.height() + m_center.height() + m_down.height();
}
unsigned int VPanel::width()const
{
	unsigned int a = m_up.width() > m_center.width() ? m_up.width() : m_center.width();

	return a > m_down.width() ? a : m_down.width();
}
void VPanel::draw(ostream& out, unsigned int line, unsigned int w)const
{
	if (line >= 0 && line < height())
	{
		if (line < m_up.height())
			m_up.draw(out, line, width());
		else
		{
			line -= m_up.height();
			if (line < m_center.height())
				m_center.draw(out, line, width());
			else
			{
				line -= m_center.height();
				if (line < m_down.height())
					m_down.draw(out, line, width());
			}
		}
		if (width() < w)
			out << string(w - width(), fill_char);
	}
	else
		out << string(w, fill_char);
}
VPanel::~VPanel() {}


//HPanel
HPanel::HPanel(const Picture& left, const Picture& center, const Picture& right, short  x, short y, char fill) :
	IPicture(x, y, fill), m_left(left), m_center(center), m_right(right) {}
unsigned int HPanel::height()const
{
	unsigned int a = m_left.height() > m_center.height() ? m_left.height() : m_center.height();

	return a > m_right.height() ? a : m_right.height();

}
unsigned int HPanel::width()const
{
	return m_left.width() + m_center.width() + m_right.width();
}
void HPanel::draw(ostream& out, unsigned int line, unsigned int w)const
{
	if (line >= 0 && line < height())
	{
		if (line < m_left.height())
		{
			m_left.draw(out, line, m_left.width());
		}
		else
			out << string(m_left.width(), fill_char);
		if (line < m_center.height())
		{
			m_center.draw(out, line, m_center.width());
		}
		else
			out << string(m_center.width(), fill_char);
		if (line < m_right.height())
		{
			m_right.draw(out, line, m_right.width());
		}
		else
			out << string(m_right.width(), fill_char);
		if (width() < w)
			out << string(w - width(), ' ');
	}
	else
		out << string(w, fill_char);
}
HPanel::~HPanel() {}
