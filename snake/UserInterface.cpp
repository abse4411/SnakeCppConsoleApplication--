#include "UserInterface.h"

UserInterface::UserInterface() :
	con(new Control()) {}

void UserInterface::show_menu() const
{
	system("cls");
	static Picture p = new StringPicture("Enter : Start or continue the game . @s     : Set args and start ganme .@h     : Help .@Esc   : Quit or back .", '@');
	static Picture p0 = new StringPicture(" @ @           Snake(V 1.0.0)           @             By:xuefeng              @ @ ", '@');
	static Frame info(p0, '+');
	static Frame frame(p, '-', 0, info.height());
	info.display(cout);
	frame.display(cout);
}

void UserInterface::start()
{
	char key;
	unsigned int arg[] = { 5000 ,'+',12,37,' ',5,5,R,2,'@',5,6,'#' };
	static bool is_char[] = { 0,1,0,0,1,0,0,0,0,1,0,0,1 };
	while (true)
	{
		show_menu();
		cout << "Press a key to start : ";
		key = _getch();
		if (key == 13)
		{
			con->run();
		}
		if (key == 'h')
		{
			cout << "\nUse arrow keys to control the snake. Press space key to pause and esc key to quit .\n";
			cout << "V 1.0.0 (2018/8/30)\nAbout : QQ:1834674034\nMail:shen_zhifeng@outlook.com\n\n";
			system("pause");
		}
		if (key == 's')
		{
			get_args(arg, is_char);
			shared_ptr<Control> p(new Control(arg[0], (char)arg[1], arg[2], arg[3], (char)arg[4], arg[5], arg[6], (Direction)arg[7],
				arg[8], (char)arg[9], arg[10], arg[11], (char)arg[12]));
			con = p;
		}
		if (key == 27)
			return;
	}


}

void UserInterface::get_args(unsigned int arg[], bool is_char[])
{
	static string help[] = {
	"Delay(The smaller the number, the faster the snake moves . ) :",
	"Border(The map is surrounded by the char . ):",
	"Height(The height of map . ):",
	"Width(The width of map . ):",
	"Map_fill(The map is filled by the char . ):",
	"Snake_pointX(The primary point X of the snake . ):",
	"Snake_pointY(The primary point Y of the snake . ):",
	"Snake_orientation(The primary orientation of the snake . Left=0 , Up=1 , Right=2 , Down=3):",
	"Snake_length(The primary length of the snake. ):",
	"Snake_fill(The snake's body is filled by the char . ):",
	"food_pointX(The primary point X of the food . ):",
	"food_pointY(The primary point Y of the food . ):",
	"food_fill(The map is filled by the char . ):",
	};
	system("cls");
	for (int i = 0; i < 13; i++)
	{
		unsigned int tmp;
		char ch;
		cout << help[i];
		//There should be some  methods to check legality , but it isn't
		//Be careful
		if (is_char[i])
		{
			cin >> std::noskipws >> ch;
			arg[i] = ch;
		}
		else
		{
			cin >> tmp;
			arg[i] = tmp;
		}
		getchar();
		cout << "Accepted\n\n";
	}
}
