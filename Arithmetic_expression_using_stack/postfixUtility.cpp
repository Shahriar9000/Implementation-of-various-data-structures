#include "postfixUtility.h"

// Function to evaluate Postfix expression and return output

string getPostfix(string expression)
{	
	genericLinkedListStack<char> S;	
	
	
	string postfix = ""; // Initialize postfix as empty string.
	for(int i = 0;i< expression.length();i++) {

		// Scanning each character from left. 
	 
		if(expression[i] == ' ' || expression[i] == ',') continue; 

		 
		else if(IsOperator(expression[i])) 
		{	
			postfix += ' ';
			while(!S.empty() && S.top() != '(' && Priority_of_Operator(expression[i]) <= Priority_of_Operator(S.top()))
			{
				postfix+= S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
	
		else if(IfNumericDigit(expression[i]))
		{	
					
					postfix +=expression[i];
		}

		else if (expression[i] == '(') 
		{
			S.push(expression[i]);
		}

		else if(expression[i] == ')') 
		{
			while(!S.empty() && S.top() !=  '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while(!S.empty()) {
		postfix += S.top();
		S.pop();
	}

	return postfix;
}




float evaluatePostfix(string pexp)
{
	
	genericLinkedListStack<float> S;


	float result=0;

	float a, b = 0.0;

	for (int i =0; i < pexp.length();i++) {
		
	
		if(pexp[i] == ' ' || pexp[i] == ',') continue; 

		else if(IsOperator(pexp[i]))
		{	

			a = S.top(); S.pop();

			b = S.top(); S.pop();

			S.push(Arithmetic_Operation(pexp[i],b,a));


		}
		
		else if(IfNumericDigit(pexp[i]))
		{	
			float value = 0.0;
			
			while (i < pexp.length() && IfNumericDigit(pexp[i]))
			{
				value = (value*10) + (pexp[i]-'0');
				i++;

			}
			
			i--;
			S.push((float)value);
			
		}
	}

	result = S.top(); S.pop();

	return result;
}



// Function to verify whether a character is numeric digit. 
bool IfNumericDigit(char N) 
{
	if(N >= '0' && N <= '9') return true;
	return false;
}


// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence. 
int Priority_of_Operator(char c)
{
	
	if(c == '/')
    	return 4;
    else if(c == '*')
    	return 3;
    else if(c == '+')
    	return 2;
    else if ( c == '-')
 		return 1;   
    else
    	return -1;

}


// Function to perform an operation and return output. 
float Arithmetic_Operation(char c, float operand1, float operand2)
{
	if(c == '+') 
		return operand1 + operand2;
	else if(c == '-') 
		return operand1 - operand2;
	else if(c == '*') 
		return operand1 * operand2;
	else if(c == '/') 
		return operand1 / operand2;
	else 
	 return -1; 
}


