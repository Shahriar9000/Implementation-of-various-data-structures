#include "postfixUtility.h"



int main(int argc, char** argv) {                // main HTML tester
   if (argc!=2){
   	cout << "Usage: executable.o 'an expression'" << endl;
	return 1;
   }

	string postfixexpression = getPostfix(argv[1]);

	cout<< evaluatePostfix(postfixexpression) << endl;
	

	return 0;
}


