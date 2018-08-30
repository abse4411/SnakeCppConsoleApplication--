#pragma once
#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <memory>
#include <string>
#include<stdlib.h>
#include"Picture.h"
#include "Control.h"
using std::shared_ptr;
using std::cout;
using std::cin;
using std::string;
using std::endl;

class UserInterface
{
public:
	UserInterface();

	//The start point
	virtual void start();
private:
	//Display the menu
	virtual void show_menu()const;

	//arg : the args are used used in Control() 
	//is_char : Indicate whether the correspondent arg type is char
	//WARNING : the values of the arg don't check legality , that would make the game produce an unexpected error probably
	//Using is not recommended unless there are some methods to help it
	virtual void get_args(unsigned int arg[],bool is_char[]);

	UserInterface(const UserInterface& ui);
	UserInterface & operator=(const UserInterface& ui);
	shared_ptr<Control> con;
};
#endif // !USERINTERFACE_H
