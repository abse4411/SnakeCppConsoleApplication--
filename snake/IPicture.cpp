#include "IPicture.h"

IPicture::IPicture(short x, short y, char fill):fill_char(fill), x(x), y(y) {}
void IPicture::display(ostream & out) const
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD xy = { x, y };
	for (unsigned int i = 0; i < height(); i++)
	{
		SetConsoleCursorPosition(hOut, xy);
		draw(out, i, width());
		xy.Y++;
		out << endl;
	}
}
