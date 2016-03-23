#pragma once
//Menu class

//Co to jest enum?

// Enum to "typ wliczeniowy" sluzy do latwiejszego operowania nie na liczbach a na slowach

#ifndef MENU_H
#define MENU_H


class Matrix;

using namespace std;

enum chooseMenu { polynomial = 0, matrix = 1, equation = 2, goexit = 3 };


class Menu
{
	
public:
	
	
	void getNumber();       //to get user choice 
	void showMenu();      //to show all menu options
 Menu(); 


};



	
#endif