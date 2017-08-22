//	CSC301 Group Assignment
//	
//  Group Members: Katie Delano, Riley Finn, Mohamed Mohamed, Zach Petersen
//  Advanced Calculator


#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
General Program Outline
Take user input
Validate
Perform mathematical operations
Return the solution
*/

int main()
{
	int arrayLength;
	vector<string> parsedInput;
	
	// Prompt user for equation
	/*  (Copied from Mohamed's repository)
	string mathExpression;

	string userInput;

	double result;

	cout << " Enter in a mathematical expression  : " << endl; // Were asking the user to enter in a mathematical expression.

	getline(cin, userInput); // This saves the user input of the users mathematical expression.


	// This is the validation part to see if the user enters a valid number or not.


	if (userInput==mathExpression)
	{
		cout << " The number you enterd is a valid mathematical expression ";
	}

	else {

		cout << " The number you enterd is invalid. Please re-enter a valid mathematical expression";
	}

	cout << " The result of your mathematical expression equals to : " << result << endl; // This will display the result of the mathematical expression.


	*/

	
	
	// Parse each number/operator into an array object (delimiters should be " ", "+", "-", "*", "/"...)
	

	parsedInput.push_back("Test");
	parsedInput.push_back("Test2");

	
	// Iterate through array looking for operators

	for (int i = 0; i < parsedInput.size(); i++)
	{
		// When an operator is found, pass it and it's neighboring elements to the mathFunction	


		if (parsedInput[i] == "+" || parsedInput[i] == "-" || parsedInput[i] == "*" || parsedInput[i] == "/")
		{
			string result = mathFunction(stod(parsedInput[i - 1]), (parsedInput[i]), stod(parsedInput[i + 1]));
			parsedInput[i - 1].erase();
			parsedInput[i + 1].erase();
			parsedInput[i] = result;
			i = 0;
			// Replace 3 array elements with the method result

			// Repeat until no operators exist and array length is 1
		}

	}

	
	// Print the equation and solution for the user
	
	
	
	cout << "Testing 1,2,3" << endl;
	cout << "Testing 4,5,6" << endl;
	//This is a placeholder
}

string mathFunction(double value1, string op, double value2)    /*declare variables needed for mathFunction, using string becuase it contains multiple characters*/
{
    double answer = 0;  //initialize answer variable
    
    if (op == "+")  //if +
    {
        answer = value1 + value2;   //addition equation
    }
    
    else if (op == "-")     //if -
    {
        answer = value1 - value2;   //subtraction equation
    }
    
    else if (op == "*")     //if *
    {
        answer = value1 * value2;        // multiplication equation
    }
    else if (op == "/")         // if /
    {
        answer = value1 / value2;   // division equation
    }
    return answer.to_string();      //displays answer to equation
}
