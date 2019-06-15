#include <iostream>
#include <fstream>
#include <vector>
#include <set>

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

bool check_same(string line1, string line2){

	vector<string> tokens1, tokens2;
	Tokenize(line1, tokens1, "\t ");
	Tokenize(line2, tokens2, "\t ");
	
	if (tokens1[0]!=tokens2[0])
		return false;
	
	set<string> s1, s2;
	for (int i=1; i<tokens1.size(); i++)
		s1.insert(tokens1[i]);
	for (int i=1; i<tokens2.size(); i++)
                s2.insert(tokens2[i]);

	return (s1==s2);
}

int main(int argc, char** argv){

	if (argc!=3){
		cout << "Usage: executable.o expected_output.txt student_output.txt\n";
		return 1;
	}

	ifstream expected_inf, output_inf;
	expected_inf.open(argv[1]);
	output_inf.open(argv[2]);

	string expected_line1, output_line1, expected_line2, output_line2, expected_line3, output_line3;
	getline(expected_inf, expected_line1);
	getline(expected_inf, expected_line2);
	getline(expected_inf, expected_line3);
	getline(output_inf, output_line1);
	getline(output_inf, output_line2);
	getline(output_inf, output_line3);

	bool same_line1 = check_same(expected_line1, output_line1);
	bool same_line2 = check_same(expected_line2, output_line2);
	bool same_line3 = check_same(expected_line3, output_line3);

	cout << "score: " << (same_line1 + same_line2 + same_line3)/(float)3 << " out of 1." <<endl;

	expected_inf.close();
	output_inf.close();

	return 0;
}
