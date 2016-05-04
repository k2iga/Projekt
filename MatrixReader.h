#ifndef MATRIXREADER_H
#define MATRIXREADER_H
#include<vector>
#include<string>
#include"Matrix.h"

class MatrixReader
{
public:
	MatrixReader();
	std::vector<std::vector<int>> matrix;
	 static void printMatrixInputMethod();
	 Matrix& readMatrix();
	 void printoutMatrix(std::vector<std::vector<int>> matrix);
	 std::vector<std::string> split(const std::string &s, char delim = ',');
};


#endif
