#include<iostream>
#include<string>
#include <sstream>
#include<vector>   
#include"Matrix.h"

using namespace std;

// Default constructor:
Matrix::Matrix()
{
	
}

//Adding matrices

vector<vector<int>> Matrix::addMatrices()
{

 vector<vector<int>>resultant_matrix;


	cout << " Please enter the values of matrix like this :" << endl << endl;
	cout << " 1,2,3q4,5,6"<<"\t It appears as" << endl << endl;

	cout << " 1 2 3" << endl;
	cout << " 4 5 6" << endl << endl;

 vector<vector<int>>matrix_1 = putin();

 cout << "\n Please enter the values of latter matrix:" << endl << endl;

 vector<vector<int>>matrix_2= putin();


 int r_max = matrix_1.size();      //Number of rows
 int c_max = matrix_1[0].size();   //Number of columns


 //Matrix addition

 for (int i = 0; i < r_max; i++)
 {
	 for (int j = 0; j < c_max; j++)
	 {
		 resultant_matrix[i][j] = matrix_1[i][j] + matrix_2[i][j];
	 }
 }


 cout << "\n  Values of the resultant matrix: " << endl << endl;


 printoutMatrix(resultant_matrix);

 return matrix_1;//resultant_matrix;
}


//Taking values of matrix from user

vector<vector<int>> Matrix::putin()

{
	vector<vector<int>>matrix_one;

	string user_input;

	cin >> user_input;

	vector<string>first_split = split(user_input, 'q');

	
	for (int i = 0; i < first_split.size(); i++)
	{

		vector<string>inputs_vector = split(first_split[i]);

		//Convertion to integer with printing - or not

		vector<int>row_vector;

		for (int i = 0; i < inputs_vector.size(); i++)
		{

			row_vector.push_back(stoi(inputs_vector[i]));           //potworek
			//std::cout << "\t" << row_vector[i];

		}
		//cout << endl;

		matrix_one.push_back(row_vector);
	}

	cout << "\n Congrats, Here is your matrix! " << endl << endl;

	//Printout of user input as a matrix

	printoutMatrix(matrix_one);
	
	
	return  matrix_one;

}


	

//*************************************************************************************************************

std::vector<std::string> Matrix::split(const std::string & s, char delim)
{
	vector<string> elems;

	stringstream ss(s); //creating  string stream object
	string item; //creating string object
	while (std::getline(ss, item, delim))
	{                //as long as getline returns true value it rewrites from stringstream another stringstream  into 'item')
		             //Variables are separated by delim
		elems.push_back(item); //insert 'item' into vector
	}
	return elems; //return vector 

}


//Printout of matrix

void Matrix::printoutMatrix(vector<vector<int>> matrix)
{
	int r_max = matrix.size();      //Number of rows
	int c_max = matrix[0].size();   //Number of columns

	for (int r = 0; r < r_max; r++)
	{
		cout << "\t";
		for (int k = 0; k < c_max; k++)
		{
			cout << "\t";
			cout << matrix[r][k] << " ";
		}
		cout << endl;

	}
}


//void Matrix::printVector(vector<int>)

//for (size_t i = 0; i < inputs_vector.size(); ++i)   //signed/unsigned mismatch so 'int i' changed  to 'size_t i'
//{                                                     //as stackoverflow experts advises
	//std::cout << "\t" << inputs_vector[i];

//}

