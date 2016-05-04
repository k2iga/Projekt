#ifndef MATRIX_H
#define MATRIX_H
#include<vector>
#include<string>
//#include"MatrixReader.h"
	
class Matrix //:public MatrixReader
{
public:
	std::vector<std::vector<int>> matrix;

	int r_max = matrix.size();    //Number of rows, 
	int c_max = matrix[0].size();  //Number of columns


	int a;
	std::string user_input;
	Matrix();
	double determinant(std::vector<std::vector<int>> mat, int r_max1);
	int detMatrix();
		
};

#endif




