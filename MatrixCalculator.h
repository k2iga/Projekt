#ifndef MATRIXCALCULATOR_H
#define MATRIXCALCULATOR_H

#include<vector>
#include<string>
#include "Matrix.h"

class  MatrixCalculator
{
public:
	MatrixCalculator();
	//std::vector<std::vector<int>>
		Matrix& addMatrices(const Matrix& matrix_1, const Matrix& matrix_2); //const reference -we guarantee to the caller 
		                                                       //that the function won't change the value
		                                                       //of the argument
	    Matrix& multiplyMatrices();

};


#endif