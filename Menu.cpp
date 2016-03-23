#include<iostream>
#include<string>
#include<vector>       
#include<cstdlib>  //for exit
#include "Menu.h"
//#include "Matrix.h"


vector<string>choose;



//default constructor
Menu::Menu()
{
	
	choose.push_back("\t  - \t solve polynomial equations \n");
	choose.push_back("\t  - \t do matrix operation \n ");
	choose.push_back("\t  - \t find the value of function at point \n");
	choose.push_back("\t  - \t exit program \n");


}

void Menu::showMenu()
{
	cout << "\t         MENU" << endl << endl;
	cout << "\t You must choose, but choose wisely. \n" << endl;

	for (size_t i = 0; i <choose.size(); ++i)   //signed/unsigned mismatch so 'int i' changed  to 'size_t i'
	{                                           //as stackoverflow experts advises
		cout << "\t" << i << choose[i];

	}

	getNumber();

}



void Menu::getNumber()
{


	int chosen_number;
	cin >> chosen_number;

	switch (chosen_number)
	{
	case polynomial:
		cout << "You choose poly" << endl;
		//function of poly
		break;
	case matrix:
		cout << "You choose matrix" << endl;
		break;



		//function of matrix
	case equation:
		cout << "You choose equation" << endl;
		//function of 

		//Matrix mat;
		//mat.putin();
		break;

	case goexit:
		exit(1);

	default:
		cout << "O o o try again" << endl;

	}

}