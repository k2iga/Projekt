#pragma once
//Menu class

//Co to jest enum?

// Enum to "typ wliczeniowy" sluzy do latwiejszego operowania nie na liczbach a na slowach

#ifndef MENU_H
#define MENU_H

#include<vector>
class Matrix;

using namespace std;

enum chooseMenu { goexit= 0, matrix = 1, equation = 2, polynomial = 3 };
enum chooseMatrix{add = 1, multiply = 2, determinant = 3 };

class Menu
{
	
public:
	
	void start(); //to start the program
	void getNumber();       //to get user choice 
	void showMenu(vector<string>);      //to show all menu options
	void Matrix_submenu(); // to show matrices menu options
 Menu(); 


};



	
#endif