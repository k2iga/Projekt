#include<iostream>
#include<string>
#include <sstream>
#include<vector>   
#include<cmath>
#include"Matrix.h"
#include"MatrixReader.h"

using namespace std;

// detault constructor:
Matrix::Matrix()
{
	
}

//*************************************************************************************************************
//Determinant of matrix-taking values
int Matrix::detMatrix()
{
	MatrixReader mr;

	//Show how to type
	MatrixReader::printMatrixInputMethod();

	//Caution
	  cout << "\n Please type the values of matrix, remember that matrix must be square " <<   endl <<   endl;

	//Take values for first matrix
	vector<vector<int>>mat = mr.readMatrix().matrix;


	int r_max1 = mat.size();    //Number of rows, mat 1 
	int c_max1 = mat[0].size();  //Number of columns, mat 1



	if (r_max1 == c_max1)
	{
		
		  cout << "Determinant of given matrix is: " << determinant(mat,r_max1) <<   endl <<   endl;
	}
	
	else
		  cout << "I can't count it ;( matrix must be square" <<   endl;


	return 1;
}

// Determinant of matrix-specific calculation

double Matrix::determinant(vector<vector<int> > mat, int r_max1)
{
	double det = 0;
	if (r_max1 == 1) return mat[0][0];
	else
	{

		for (int i = 0; i < r_max1; i++)
		{

			int j, k;
			vector<vector<int> > detmat;
			//vector<vector<int> > detmat(r_max1 - 1); //zamiast pushbackowania "row" mogê podaæ rozmiar pierwszego)
			
			for (j = 0; j < r_max1 - 1; j++) // 'j' iterates for rows 
			{
				vector<int> row;         //row vector
				detmat.push_back(row);
				for (k = 0; k < r_max1 - 1; k++)
				{
					if (k < i)
					{
						detmat[j].push_back(mat[j + 1][k]);
					}
					if (k >= i)
					{
						detmat[j].push_back(mat[j + 1][k + 1]);
					}
				}
			}
				det = det + (mat[0][i] * pow(-1, i + 2)*determinant(detmat, r_max1 - 1));
			
		}


	}
	return det;
}


