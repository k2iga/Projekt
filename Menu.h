#ifndef MENU_H
#define MENU_H
#include<vector>

class Matrix;

// Enum to "typ wliczeniowy" sluzy do latwiejszego operowania nie na liczbach a na slowach
enum chooseMenu { goexit= 0, matrix , equation , polynomial };
enum chooseMatrix{add = 1, multiply , determinant };

class Menu
{
	
public:
	
	void start(); //to start the program
	void askForChoice();       //to get user choice 
	void showMenu(std::vector<std::string>);      //to show all menu options
	void Matrix_submenu(); // to show matrices menu options
 Menu(); 

};



	
#endif