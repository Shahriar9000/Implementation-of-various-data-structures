#include "tttboard.h"
#include "gTree.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void Tokenize(string line, vector<string> & tokens, string delimiters = "\t "){
string token = "";
        string OneCharString = " ";
        for (int i=0; i<line.size(); i++)
                if (find(delimiters.begin(), delimiters.end(), line[i])!=delimiters.end()) // line[i] is one of the delimiter characters
                {
                        if (token != "")
                                tokens.push_back(token);
                        token = "";
                }
                else
                {
                        OneCharString[0] = line[i];
                        token +=OneCharString;
                }

        if (token != "")
                tokens.push_back(token);
}


int main(int argc, char** argv){
	if (argc!=3){
		cout << "usage: executable.o n board\n example of board:(\"{0,0,1,0,0,-1,1,0,0}\")";
		return 1;
	}

	int n= atoi(argv[1]);
	string str_board = argv[2];
	vector<string> tokens;
	Tokenize(str_board,tokens," {,}");
	vector<int> board;
	for (int i=0; i<tokens.size(); i++){
		board.push_back(atoi(tokens[i].c_str()));
	}
	if (n*n!= board.size()){
		cout<< "n and board are not consistent!\n";
		return 1;
	}

        gTree<tttboard> tttTree;
        tttboard root(n,board);
        tttTree.addNode(root, NULL);	

	gTNode<tttboard>* p = findItem(tttTree.getRoot(), root);

	if (board[0]==0)	
		board[0]=1;
	else
		board[0]*=-1;

	tttboard child(n, board);

	tttTree.addNode(child, p);

	cout << "preorder:\n" ;
	preorderPrint(tttTree.getRoot());
	cout <<"\npostorder:\n";
	postorderPrint(tttTree.getRoot());
	cout << "\nsize:" << size(tttTree.getRoot())<< endl;
	
	return 0;

}
