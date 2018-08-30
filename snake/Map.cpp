#include "Map.h"

Map::Map(unsigned int h, unsigned int w, char bd, short x, short y, char fill) :
	IPicture(x, y, fill), data(NULL), border(bd), h(h), w(w)
{
	data = new char[h*w];
}
unsigned int Map::height() const
{
	return h + 2;
}
unsigned int Map::width() const
{
	return w + 2;
}
Map::~Map() { delete[] data; }
void Map::fill(char fill)
{
	for (unsigned int i = 0; i < h; i++)
		for (unsigned int j = 0; j < w; j++)
			data[i*(this->w) + j] = fill;
}
bool Map::is_out(const Body & bd)const
{
	if (bd.x < 0 || bd.y < 0 || (unsigned int)bd.x >= w || (unsigned int)bd.y >= h)
		return true;
	return false;
}
void Map::update_data(const list<Body>& body, char fill)
{
	for (list<Body>::const_iterator i = body.begin(); i != body.end(); i++)
		if (!is_out(*i))
			data[i->y*(this->w) + i->x] = fill;
}
void Map::update_position(const Body& bd, char fill)
{
	if (!is_out(bd))
		data[bd.y*(this->w) + bd.x] = fill;
}
void Map::draw(ostream & out, unsigned int line, unsigned int w) const
{
	if (line >= 0 && line < height())
	{
		if (line >= 0 && line < height())
		{
			if (line == 0)
				out << string(this->w + 2, border);
			else
				if (line == height() - 1)
					out << string(this->w + 2, border);
				else
				{
					out << border;
					for (unsigned int j = 0; j < this->w; j++)
						out << data[(line - 1)*(this->w) + j];
					out << border;
				}

			if (width() < w)
				out << string(w - width(), fill_char);
		}
	}
	else
		out << string(w, fill_char);
}
