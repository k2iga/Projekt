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
	vector<vector<int>> addMatrices();
	vector<vector<int>> putin();

	void printoutMatrix(vector<vector<int>> matrix);
	vector < vector<int>> multiplyMatrices();
	int detMatrix();
	vector<string> split(const string &s, char delim=',');
	void printMatrixInputMethod();
	
};

#endif




