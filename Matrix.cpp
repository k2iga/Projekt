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

 //Show how to type
 printMatrixInputMethod();

 //Take values for first matrix
 vector<vector<int>>matrix_1 = putin();

 //Take values for second matrix
 cout << "\n Please enter the values of latter matrix:" << endl << endl;
 vector<vector<int>>matrix_2= putin();

 int r_max = matrix_1.size();    //Number of rows (assuming is the same for both matrices) 
 int c_max = matrix_1[0].size();  //Number of columns

 //Matrix addition
 for (int i = 0; i < r_max; i++)
 {
	 vector<int> v;
	 resultant_matrix.push_back(v);
	 // resultant_matrix.push_back(*(new vector<int>));
	 for (int j = 0; j < c_max; j++)
	 {
		 resultant_matrix[i].push_back( matrix_1[i][j] + matrix_2[i][j]);
	 }
 }
 
 //Printout of resultant matrix
 cout << "\n  Values of the resultant matrix: " << endl << endl;
 printoutMatrix(resultant_matrix);

 return resultant_matrix;
}

//Taking values of matrix from user   

vector<vector<int>> Matrix::putin()
{
	vector<vector<int>>matrix_one;
	vector<string>first_split;
	string::size_type search_for_q;

	string user_input;

	int size_of_row = 1;// default lenght of the shortest row in matrix, assumes at least 1 value

	do
	{
		cin >> user_input; // take string from user
		search_for_q = user_input.find("q"); // search for "q" in this string ***

		//Split string and get vector with values: string"1,2,3,q" => vector<string> ={1,2,3,q}
			first_split = split(user_input);

        //Get rid of "q"(if there is any): vector ={1,2,3,q} => vector ={1,2,3}
			for (int i = 0; i < first_split.size(); i++)
			{
				if (first_split[i]=="q")
				{
					first_split.resize(first_split.size()-1);
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

			//*Check if created vector is longest than previous one (default size is set to 1) 
			if (size_of_row < row_vector.size())
			{
				size_of_row = row_vector.size(); //* if it is longest - we set a new value for size_of_row    
			}                                    //* so "size_of_row" is maximal length of vector

			matrix_one.push_back(row_vector);

	} while (search_for_q == string::npos); //*** loop will end when user types "q", 
                                            //*** "find" function return position of searched substring, "Aq47"--> return 2
											//*** if it doesn't find it returns "npos" -largest int (4294967295)  

//*Resize all vectors in matrix to have the same size - which is specifed by "size_of_row"
 for (int i = 0; i < matrix_one.size(); i++)
	{
		if (matrix_one[i].size() < size_of_row)

		{
			matrix_one[i].resize(size_of_row, 0); // resize vectors and fill extra place with zeros 
		}
	}

 //Printout of user input as a matrix
            cout << "\n Congrats, Here is your matrix! " << endl << endl;
			printoutMatrix(matrix_one);

	return  matrix_one;

}

//*************************************************************************************************************

//Split string with delimeter

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

