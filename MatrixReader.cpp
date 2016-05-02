//CLASS MATRIXREADER
#include<iostream>
#include<string>
#include <sstream>
#include<vector>   
#include<cmath>
#include"MatrixReader.h"
#include"Matrix.h"

using namespace std;

// detault constructor:
MatrixReader::MatrixReader()
{

}

//Information for the user how matrix should be entered

void MatrixReader::printMatrixInputMethod()
{
	static const string pMIM =
		" Please enter the values of matrix like this : \n \n"
		" 1,2,3  \t press enter \n"
		" 4,,6   \t press enter \n"
		" 7,8,9q \t press 'q',press enter, \"q\" informs that this is last row \n\t\t of matrix \n \n"

		"\t It prints out the  following output: \n "
		" 1 2 3 \n " 
		" 4 0 6 \n "
		" 7 8 9 \n ";

		 cout << pMIM;
}

//Taking values of matrix from user   

Matrix MatrixReader::readMatrix()
{
	Matrix matrix_one;
    //vector<vector<int>>matrix_one;
	vector<string>first_split;
	string::size_type search_for_q;

	 string user_input;

	int size_of_row = 1;// detault lenght of the shortest row in matrix, assumes at least 1 value

	do
	{
		 cin >> user_input; // take string from user
		search_for_q = user_input.find("q"); // search for "q" in this string ***

											 //Split string and get vector with values: string"1,2,3,q" => vector<string> ={1,2,3,q}
		first_split = split(user_input);

		//Get rid of "q"(if there is any): vector ={1,2,3,q} => vector ={1,2,3}
		for (int i = 0; i < first_split.size(); i++)
		{
			if (first_split[i] == "q")
			{
				first_split.resize(first_split.size() - 1);
			}
		}

		//Fill empty spaces with zeros: {2,,3} => {2,0,3}
		for (int i = 0; i < first_split.size(); i++)
		{
			if (first_split[i].empty())
			{
				first_split[i] = "0";
			}
		}

		//Convertion strings to integers-"stoi" and push numbers to row vector, 
		vector<int>row_vector;

		for (int i = 0; i < first_split.size(); i++)
		{
			row_vector.push_back(stoi(first_split[i]));           //potworek
																  //cout << "\t" << row_vector[i];   //not
		}

		//*Check if created vector is longest than previous one (detault size is set to 1) 
		if (size_of_row < row_vector.size())
		{
			size_of_row = row_vector.size(); //* if it is longest - we set a new value for size_of_row    
		}                                    //* so "size_of_row" is maximal length of vector

	(matrix_one.matrix).push_back(row_vector);

	} while (search_for_q == string::npos); //*** loop will end when user types "q", 
											//*** "find" function return position of searched substring, "Aq47"--> return 2
											//*** if it doesn't find it returns "npos" -largest int (4294967295)  

											//*Resize all vectors in matrix to have the same size - which is specifed by "size_of_row"
	for (int i = 0; i < (matrix_one.matrix).size(); i++)
	{
		if ((matrix_one.matrix)[i].size()< size_of_row)

		{
			(matrix_one.matrix)[i].resize(size_of_row, 0); // resize vectors and fill extra place with zeros 
		}
	}


	//Printout of user input as a matrix
	cout << "\n Congrats, Here is your matrix! " <<  endl <<  endl;
	printoutMatrix((matrix_one.matrix));


	return  matrix_one;

}

//*************************************************************************************************************

//Split string with delimeter

vector< string> MatrixReader::split(const  string & s, char delim)
{
	vector< string> elems;

	 stringstream ss(s); //creating  string stream object
	 string item; //creating string object
	while ( getline(ss, item, delim))
	{                //as long as getline returns true value it rewrites from stringstream another stringstream  into 'item')
					 //Variables are separated by delim
		elems.push_back(item); //insert 'item' into vector
	}
	return elems; //return vector 

}

//Printout of matrix

void MatrixReader::printoutMatrix(vector<vector<int>> matrix)
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
		 cout <<  endl;

	}
}