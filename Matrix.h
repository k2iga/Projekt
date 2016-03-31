#pragma once

#ifndef MATRIX_H
#define MATRIX_H
#include<vector>
#include<string>
using namespace std;
	
class Matrix
{
public:
	int a;
	string user_input;
	Matrix();
	vector<vector<int>> Matrix::addMatrices();
	vector<vector<int>> Matrix::putin();
	
	void Matrix::printoutMatrix(vector<vector<int>> matrix);
	
	std::vector<std::string> split(const std::string &s, char delim=',');


	

};

#endif




