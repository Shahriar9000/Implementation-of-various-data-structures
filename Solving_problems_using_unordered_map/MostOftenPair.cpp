#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <fstream>
#include "Utility.h"

using namespace std;


unordered_map<n_gram,int,n_gram_hash> most_often_pair_count;

void find_pairs(const n_gram& p1, const n_gram& p2)
{
    unordered_map<n_gram,int,n_gram_hash>::iterator position ; // an iterator p to traverse through map

    position = most_often_pair_count.find(p1);

        if (position!= most_often_pair_count.end())
        {
            most_often_pair_count[p1]++;
            return;
        }

    position= most_often_pair_count.find(p2);

        if(position!= most_often_pair_count.end())
        {
            most_often_pair_count[p2]++;
            return;
        }
        else
            most_often_pair_count[p1]++; 
}


void ReadFile(const char* fname){
    ifstream file;
    file.open(fname);

    
    

    string line;

    while (getline(file, line).good()){
        vector<string> tokens;
        Tokenize(line, tokens, "\t ");

        n_gram pair1 = n_gram(1,{tokens[0]+" "+tokens[1]});

        n_gram pair2 = n_gram(1,{tokens[1]+" "+tokens[0]});
 
        find_pairs(pair1, pair2); // find the most occured pair

    }

    file.close();
}

int main(int argc, char** argv){
    if (argc != 2){
        cout << "usage: executable.o commands.txt\n";
        return 1;
    }

    // Read the given file and find the most occured pair
    ReadFile(argv[1]);
   

  //print the most occured pair
   unordered_map<n_gram,int,n_gram_hash>::iterator p = most_often_pair_count.begin();

    for (auto itr = most_often_pair_count.begin(); itr!=most_often_pair_count.end(); itr++)
    {
        
        if (itr->second >= p->second)
            p=itr;
    }
    
    vector<string> pair_array = p->first.getwords();
    vector<string> tokens;
    string pair_string = pair_array[0];
    Tokenize(pair_string, tokens, " \t");
    
    cout << tokens[0] << " and " << tokens[1] << " occurred together most often: #occurrence=" << p->second << endl;




    return 0;
}
