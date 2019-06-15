#ifndef TTTBOARD_H
#define TTTBOARD_H

#include <iostream>
#include <vector>

using namespace std;

class tttboard{
	public:


		tttboard(int n, vector<int>& board);

		vector<tttboard> possibleNextBoards(int turn) const;

		bool operator==(const tttboard& board) const;

		friend ostream& operator<<(ostream& out, const tttboard& p);

	private:
 		vector<int> b_;
		int n_;	
};

#endif 
