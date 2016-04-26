/**************************************************************************************************************
Title: Matrix Sum
Author: Ada Chen
Created On: December 2nd, 2014
Description: Program reads a given input file and finds the maximum number in each row of the given matrix, then 
adds them up to get the sum.
Purpose: Practice using dynamic array allocation, array parsing and pointers. Pointer to pointer method and command 
line to read files.
Usage: User types in the file name with the matrix and program outputs the sum of largest numbers of each row.
***************************************************************************************************************/
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;

//command line implementation
int main(int argc, char *argv[])
{
    //variable declarations
    string file;
    fstream infile;
    int sizeRow = 15;
    int sizeCol = 15;
    int content;
    int max = 0;
    int sum = 0;

    //checks to make sure there is no more or no less than 2 arguments. If there is,
    // outputs an error message.
    if(argc != 2){
        cout << "Error opening file. ";
        return 0;
    }
    
    //if there are two arguments, program will run the file and state whether it has opened successfully or not
    if(argc == 2){
        file = argv[1];
        //opens file
        infile.open(file.c_str());
        if(infile.is_open()){
            cout << "File opened successfully." << endl;
        }
        else{
            cout << "File has not been opened.";
        }
    }
    
    //declaration of the 2D dynamic array
    int **array = new int*[sizeRow];
        for(int i=0; i<sizeRow; i++){
            array[i] = new int[sizeCol];
        }
        
        //while it is not the end of the file, loop fills the contents of the file into an array
        while(! infile.eof()){
            for(int row=0; row<sizeRow; row++){
                for (int col=0; col<sizeCol; col++){
                    infile>>content;
                    //setting the content to the array
                    array[row][col] = content;
                }
            }
        }
        
        //loops through the array and finds the maximum number, if it is greater than 0, it becomes the max
        for(int row=0; row<sizeRow; row++){
            for(int col=0; col<sizeCol; col++){
                if(array[row][col] > max){
                    max = array[row][col];
                }
            }
            //adds that maxiumum number found to the sum (which starts at 0)
            sum = sum+max;
            //sets the max back to 0 so it can find the maximum number in the 2nd column and columns after that
            max = 0;
        }
        
        //outputs the sum of the max's in the matrix
        cout << "This is the sum of all the maximum's of each row in the Matrix: " << sum << endl;

    return 0;
}
