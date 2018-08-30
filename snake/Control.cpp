#include "Control.h"

string Control::state_table[] = { "Failed", "Playing"," Pause" };
Control::Control(uint32_t delay, char bd, unsigned int h, unsigned int w, char m_fill,
	unsigned int s_x, unsigned int s_y, Direction d, unsigned int len, char s_fill,
	unsigned int f_x, unsigned int f_y, char f_fill) :
	map(h, w, bd, 0, 0, m_fill), snake(s_x, s_y, d, len), food(f_x, f_y), delay(delay), map_fill(m_fill), snake_fill(s_fill), food_fill(f_fill), state(Start),
	snake_len(len), snake_d(d), snake_x(s_x), snake_y(s_y), score(0)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(handle, &info);
	info.bVisible = false;
	SetConsoleCursorInfo(handle, &info);
}

void Control::reset()
{
	snake.reset(snake_x, snake_y, snake_d, snake_len);
}

void Control::refresh()
{
	map.fill(map_fill);
	map.update_data(snake.get_body(), snake_fill);
	map.update_position(food.get_position(), food_fill);
	map.display(cout);
	cout << "Socre: " << std::setw(5) << std::left << score << " | ";
	cout << "State: " << std::setw(10) << std::left << state_table[(unsigned int)state] << endl;
}

Control::State Control::get_state()const
{
	return state;
}

unsigned int Control::run()
{
	char key = 0;
	static unsigned int counter = 0;
	score = 0;
	bool is_press_dirkey = false;
	bool moved = false;

	system("cls");
	if (state == Start)
		reset();
	refresh();
	pause(Pause);
	while (state == Working)
	{
		if (moved)
		{
			if (map.is_out(snake.get_head()) || snake.is_cross())
			{
				pause(Start);
				system("pause");
				state = Start;
				return score;
			}
				moved = false;
		}
		if (_kbhit())
		{
			key = _getch();
			switch (key)
			{
			case 72:
				snake.turn(U);
				is_press_dirkey = true;
				break;
			case 80:
				snake.turn(D);
				is_press_dirkey = true;
				break;
			case 75:
				snake.turn(L);
				is_press_dirkey = true;
				break;
			case 77:
				snake.turn(R);
				is_press_dirkey = true;
				break;
			case 32:
				pause(Pause);
				break;
			case 27:
				return score;
				break;
			default:
				break;
			}
			if (is_press_dirkey)
			{
				counter = 0;
				is_press_dirkey = false;
				if (snake.get_head() == food.get_position())
				{
					snake.grow();
					score++;
					food.reset(map.width() - 2, map.height() - 2);
				}
				refresh();
				moved = true;
			}
		}
		counter++;
		if (counter == delay)
		{
			counter = 0;
			snake.go();
			refresh();
			moved = true;
			if (snake.get_head() == food.get_position())
			{
				snake.grow();
				score++;
				food.reset(map.width() - 2, map.height() - 2);
			}
		}
	}

	return 0;
}

Control::~Control() {}

void Control::pause(State d)
{
	state = d;
	refresh();
	_getch();
	_getch();
	state = Working;
}
