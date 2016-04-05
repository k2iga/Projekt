#include<iostream>
#include<string>
#include <sstream>
#include<vector>   
#include"Matrix.h"


// Default constructor:
Matrix::Matrix()
{	
}

//Adding matrices

vector<vector<int>> Matrix::addMatrices()
{

 vector<vector<int>>resultant_matrix;

 printMatrixInputMethod();

 vector<vector<int>>matrix_1 = putin();

 cout << "\n Please enter the values of latter matrix:" << endl << endl;

 vector<vector<int>>matrix_2= putin();


 int r_max = matrix_1.size();      //Number of rows
 int c_max = matrix_1[0].size();   //Number of columns


 //Matrix addition

 for (int i = 0; i < r_max; i++)
 {
	 vector<int> v;
	 resultant_matrix.push_back(v);
	 //resultant_matrix.push_back(*(new vector<int>));
	 for (int j = 0; j < c_max; j++)
	 {
		 resultant_matrix[i].push_back( matrix_1[i][j] + matrix_2[i][j]);
	 }
 }

 cout << "\n  Values of the resultant matrix: " << endl << endl;

 printoutMatrix(resultant_matrix);

 return resultant_matrix;
}

//Taking values of matrix from user  PUTIN 

vector<vector<int>> Matrix::putin()

{
	vector<vector<int>>matrix_one;
	vector<string>first_split;
	string::size_type position;

	string user_input;

	int size_of_row = 1;//moze na dol

	do
	{
		cin >> user_input;
		position = user_input.find("q"); // search for "q"

			first_split = split(user_input);

        //Resize vector if there is "q" inside, cause q can't be transform into integer
			for (int i = 0; i < first_split.size(); i++)
			{
				if (first_split[i]=="q")
				{
					first_split.resize(first_split.size()-1);
				}

			}

          
		//Fill empty spaces with zeros
			for (int i = 0; i < first_split.size(); i++)
			{
				if (first_split[i].empty())
				{
					first_split[i] = "0";
				}
				
			}
			
			//Convertion to integers and push to row vector
			vector<int>row_vector;

			for (int i = 0; i < first_split.size(); i++)
			{
				row_vector.push_back(stoi(first_split[i]));           //potworek
				//cout << "\t" << row_vector[i];   //not
			}

			if (size_of_row < row_vector.size())
			{
				size_of_row = row_vector.size();
			}

			matrix_one.push_back(row_vector);

	} while (position == string::npos);


	//Resize to have the same length of rows

	for (int i = 0; i < matrix_one.size(); i++)
	{
		if (matrix_one[i].size() < size_of_row)

		{
			matrix_one[i].resize(size_of_row, 0);
		}
	}



			std::cout << "\n Congrats, Here is your matrix! " << endl << endl;

			//Printout of user input as a matrix

			printoutMatrix(matrix_one);

	return  matrix_one;

}


//*************************************************************************************************************

vector<string> Matrix::split(const string & s, char delim)
{
	vector<string> elems;

	stringstream ss(s); //creating  string stream object
	string item; //creating string object
	while (getline(ss, item, delim))
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


//Information for the user how matrix should be entered

void Matrix::printMatrixInputMethod()
{

	cout << " Please enter the values of matrix like this :" << endl << endl;
	cout << " 1,2,3  \t press enter " << endl;
	cout << " 4,,6   \t press enter " << endl;
	cout << " 7,8,9q \t press enter, \"q\" informs that this is last row of matrix" << endl;
		

	cout<<"\t It prints out the  following output:" << endl << endl;

	cout << " 1 2 3" << endl;
	cout << " 4 0 6" << endl;
	cout << " 7 8 9" << endl<< endl;


}



//void Matrix::printVector(vector<int>)

//for (size_t i = 0; i < inputs_vector.size(); ++i)   //signed/unsigned mismatch so 'int i' changed  to 'size_t i'
//{                                                     //as stackoverflow experts advises
	//std::cout << "\t" << inputs_vector[i];

//}

