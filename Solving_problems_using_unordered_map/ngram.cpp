#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include "Utility.h"

using namespace std;

int main(){

	unordered_map<n_gram,int,n_gram_hash> bigram_counts;
	unordered_map<string,int> unigram_counts;

	ifstream inf("corpus.txt");
	string line;
	while (getline(inf,line).good()){
		vector<string> tokens;
		Tokenize(line, tokens, " \t");
		int s= tokens.size();
		for (int i=0; i<s; i++)
			unigram_counts[tokens[i]]++;
			
		for (int i=1; i<s; i++){
                	n_gram x = n_gram(2,{tokens[i-1],tokens[i]}); 
			bigram_counts[x]++;	
		}
	}
	
	ofstream outf1, outf2;
	outf1.open("unigrams.txt");
	outf2.open("bigrams.txt");

	for (auto itr1=unigram_counts.begin(); itr1!=unigram_counts.end(); itr1++)
		outf1 << itr1->first << " : " << itr1->second << endl;
	
	for (auto itr2=bigram_counts.begin(); itr2!=bigram_counts.end(); itr2++)
               outf2 << itr2->first << " : " << itr2->second << endl;	

	outf1.close();
	outf2.close();

}
