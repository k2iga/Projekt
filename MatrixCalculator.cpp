//CLASS MATRIXCALCULATOR
#include<iostream>
#include<string>
#include<vector>   
#include<cmath>
#include"MatrixCalculator.h"
#include"Matrix.h"
#include "MatrixReader.h"

using namespace std;

// detault constructor:
MatrixCalculator::MatrixCalculator()
{
}

//Adding matrices
vector<vector<int>> MatrixCalculator::addMatrices()
{
	MatrixReader mr;  
	vector<vector<int>>resultant_matrix;

	//Show how to type
	MatrixReader::printMatrixInputMethod(); 

	//Take values for first matrix
	
	vector<vector<int>>matrix_1 = mr.readMatrix().matrix;

	//Caution
	cout << "\n Matrices should have the same sizes! " << endl << endl;


	//Take values for second matrix
	cout << "\n Please enter the values of latter matrix:" << endl << endl;
	vector<vector<int>>matrix_2 = mr.readMatrix().matrix;


	int r_max = matrix_1.size();    //Number of rows of first matrix 
	int c_max = matrix_1[0].size();  //Number of columns of first matrix

	int r_max2 = matrix_2.size();    //Number of rows  of second matrix
	int c_max2 = matrix_2[0].size();  //Number of columns of second matrix



	//Check if we can add
	if (c_max == c_max2 && r_max == r_max2)          //Check if we can multiply 
	{
		cout << "\n I can add it! " << endl;

		//Matrix addition
		for (int i = 0; i < r_max; i++)
		{
			vector<int> v;
			resultant_matrix.push_back(v);
			// resultant_matrix.push_back(*(new vector<int>));
			for (int j = 0; j < c_max; j++)
			{
				resultant_matrix[i].push_back(matrix_1[i][j] + matrix_2[i][j]);
			}
		}

		//Printout of resultant matrix
		cout << "\n  Values of the resultant matrix: " << endl << endl;
		mr.printoutMatrix(resultant_matrix);                                    //domyœlnie  w MatrixReader

	}
	else
cout  << "\n Sorry, matrix should have the same size: " << endl << endl;

	return resultant_matrix;
}

//***************************************************************************************************************

//Matrix multiplication
vector<vector<int> > MatrixCalculator::multiplyMatrices()
{
	MatrixReader mr;
	vector<vector<int> >resultant_multiply;

	//Show how to type
	MatrixReader::printMatrixInputMethod();

	//Caution
	cout << "\n Number of raws of second matrix should be equal \n to number of columns of first matrix! " << endl << endl;

	//Take values for first matrix
	vector<vector<int>>matrix_1 = mr.readMatrix().matrix;

	//Take values for second matrix
    cout << "\n Please enter the values of latter matrix:" << endl << endl;
	vector<vector<int>>matrix_2 = mr.readMatrix().matrix;

	int r_max1 = matrix_1.size();    //Number of rows, mat 1 
	int c_max1 = matrix_1[0].size();  //Number of columns, mat 1

	int r_max2 = matrix_2.size();    //Number of rows, mat 2 
	int c_max2 = matrix_2[0].size();  //Number of columns, mat 2


	if (c_max1 == r_max2)          //Check if we can multiply 
	{
		cout << "\n I can multiply it! " << endl;

		for (int i = 0; i < r_max1; i++)
		{
			vector<int>rv; //row vector

			for (int j = 0; j < c_max2; j++)

			{
				int mn = 0;

				for (int k = 0; k < r_max2; k++)
				{
					mn += matrix_1[i][k] * matrix_2[k][j]; //mn=mn+ ...

				}
				rv.push_back(mn);
			}

			resultant_multiply.push_back(rv);
		}

		mr.printoutMatrix(resultant_multiply);

	}
	else
		cout << "\n Multiplication can't be done ;/" << endl;

	return resultant_multiply;
}

//*******************************************************************************************************