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

int getTurn(vector<int> b){
	int s = 0; 
	for (int i=0; i<b.size(); i++)
		s+=b[i];
	if (s==0)
		return 1;
	else 
		return -1;
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

        tttboard p(n,board);
	int turn = getTurn(board);
	vector<tttboard> v = p.possibleNextBoards(turn);	

	cout <<"children of the given board:" << endl;
	for (int i=0; i<v.size(); i++)
		cout << v[i] << endl;

	return 0;

}