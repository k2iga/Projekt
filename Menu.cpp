#include<iostream>
#include<string>
#include<vector>       
#include<cstdlib>  //for exit
#include "Menu.h"
#include "Matrix.h"
class Matrix;


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

	Matrix mat;



	//Choose of the number
	int chosen_number;
	std::cin >> chosen_number;

	switch (chosen_number)
	{
	case polynomial:
		cout << "\n You choose poly" << endl;
		//function of poly
		break;

	case matrix:
		cout << "\n You choose matrix" << endl<<endl;
	
		mat.addMatrices();
		//mat.putin();
	//
			break;


		//function of matrix
	case equation:
		cout << "\n You choose equation" << endl;
		//function of 

		break;

	case goexit:
		exit(1);

	default:
		
		cout << "\n O o o try again" << endl;
		
		//Menu again;
		//again.showMenu;  zrobic cos zeby dzialalo - znowu wywoluje getNumber czyli troche rekurencja-czy zwraca warosc?
	
	}

}
