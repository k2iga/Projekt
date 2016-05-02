#ifndef MATRIX_H
#define MATRIX_H
#include<vector>
#include<string>
	
class Matrix
{
public:
	std::vector<std::vector<int>> matrix;
	int a;
	std::string user_input;
	Matrix();
	double determinant(std::vector<std::vector<int>> mat, int r_max1);
	int detMatrix();
		
};

#endif




