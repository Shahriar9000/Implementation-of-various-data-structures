#include "genericLinkedListStack.h"
#include <cstdlib>
#include <boost/lexical_cast.hpp>
#include <fstream>
#include <algorithm>

using namespace std;

// Function to convert Infix expression to postfix 
string getPostfix(string);

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C);

// Function to evaluate Postfix expression and return output
float evaluatePostfix(string expression);

// Function to perform an operation and return output. 
float Arithmetic_Operation(char operation, float operand1, float operand2);

// Function to verify whether a character is numeric digit. 
bool IfNumericDigit(char C);

//Function to determine the priority level of operator
int Priority_of_Operator(char c);



