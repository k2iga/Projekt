#include<iostream>
#include<string>
#include<vector>       
#include<cstdlib>  //for exit
#include "Menu.h"
#include "Matrix.h"
class Matrix;

vector<string>choose;
vector<string>choose_in_matrix;

//default constructor
Menu::Menu()
{
	choose.push_back("\t  - \t exit program \n");
	choose.push_back("\t  - \t Do matrix operation \n "); 
	choose.push_back("\t  - \t Find the value of function at point \n");
	choose.push_back("\t  - \t Solve polynomial equations \n");
	

	choose_in_matrix.push_back("\t  - \t exit program \n");
	choose_in_matrix.push_back("\t  - \t Add Matrices \n");
	choose_in_matrix.push_back("\t  - \t Multiply Matrices \n");
	choose_in_matrix.push_back("\t  - \t Count Determinant \n");
}

void Menu::start()
{
	showMenu(choose);
	getNumber();
}

void Menu::Matrix_submenu()
{
	Matrix mat;
	showMenu(choose_in_matrix);

	int choice;
	cin >> choice;

	switch (choice)
	{
	case goexit:
		exit(1);
		break;
	case add:
		mat.addMatrices();
		Matrix_submenu();
		break;
	case multiply:
		mat.multiplyMatrices();
		//Matrix_submenu();
		break;
	case determinant:
		mat.detMatrix();
		//Matrix_submenu();
		break;
	default:
		cout << "\n O o o try again" << endl;
		Matrix_submenu(); //Uwaga! funkcja wywo³uje sam¹ siebie! 
	}
}

void Menu::showMenu(vector<string> choose)
{
	cout << "\t         MENU" << endl << endl;
	cout << "\t You must choose, but choose wisely. \n" << endl;

	for (size_t i = 0; i <choose.size(); ++i)   //signed/unsigned mismatch so 'int i' changed  to 'size_t i'
	{                                           //as stackoverflow experts advises
		cout << "\t" << i << choose[i];
	}

}

void Menu::getNumber()
{

	Matrix mat;

	//Choose of the number
	int chosen_number;
	std::cin >> chosen_number;

	switch (chosen_number)
	{
	case goexit:
		exit(1);
		break;

	case matrix:
		cout << "\n You choose matrix" << endl << endl;
		Matrix_submenu();
		break;

	case equation:
		cout << "\n You choose equation" << endl;
		//function of 
		break;

	case polynomial:
		cout << "\n You choose poly" << endl;
		//function of poly
		break;

	default:

		cout << "\n O o o try again" << endl;
		start();

	}
}

