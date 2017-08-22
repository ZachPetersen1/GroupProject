//	CSC301 Group Assignment
//	
//  Group Members: Katie Delano, Riley Finn, Mohamed Mohamed, Zach Petersen
//  Advanced Calculator


#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string mathFunction(double, string, double);
/*
General Program Outline
Take user input
Validate
Perform mathematical operations
Return the solution
*/

int main()
{
	vector<string> parsedInput;
	string userInput;
	double result;

	// Prompt user for equation
	cout << " Enter in a mathematical expression  : " << endl; // Were asking the user to enter in a mathematical expression.

	getline(cin, userInput); // This saves the user input of the users mathematical expression.

	// Parse each number/operator into an array object (delimiters should be " ", "+", "-", "*", "/"...)

	string sb = "";

	for (unsigned int i = 0; i < userInput.length(); i++)
	{
		string currentChar = userInput.substr(i, 1);
		//sb += currentChar;
		if (currentChar == "+" || currentChar == "-" || currentChar == "/" || currentChar == "*" || currentChar == "(" || currentChar == ")")
		{
			parsedInput.push_back(sb);
			parsedInput.push_back(currentChar);
			sb = "";
		}
		else if (currentChar != " ")
		{
			sb += currentChar;
		}

	}
	parsedInput.push_back(sb);

	for (string s : parsedInput)
		cout << s << endl;

	// Iterate through array looking for operators

	for (unsigned int i = 0; i < parsedInput.size(); i++)
	{
		// When an operator is found, pass it and it's neighboring elements to the mathFunction	


		if (parsedInput[i] == "+" || parsedInput[i] == "-" || parsedInput[i] == "*" || parsedInput[i] == "/")
		{
			string result = mathFunction(stod(parsedInput[i - 1]), parsedInput[i], stod(parsedInput[i + 1]));
			parsedInput.erase(parsedInput.begin() + i - 1);
			parsedInput.erase(parsedInput.begin() + i - 1);
			parsedInput[i - 1] = result;
			i = 0;
			// Replace 3 array elements with the method result

			// Repeat until no operators exist and array length is 1
		}

	}



	// Print the equation and solution for the user
	cout << " The result of your mathematical expression equals to : " << parsedInput[0] << endl; // This will display the result of the mathematical expression.


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
    return to_string(answer);      //casts answer variable to string mathFunction
}
