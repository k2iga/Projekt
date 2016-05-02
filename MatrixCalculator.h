#ifndef MATRIXCALCULATOR_H
#define MATRIXCALCULATOR_H

#include<vector>
#include<string>

class MatrixCalculator
{
public:
	MatrixCalculator();
	std::vector<std::vector<int>> addMatrices();
	std::vector < std::vector<int>> multiplyMatrices();

};


#endif