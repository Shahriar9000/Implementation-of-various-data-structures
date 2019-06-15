#include <vector>
#include <fstream>
#include <algorithm>
#include <boost/lexical_cast.hpp>
#include "loan_application.h"





using namespace std;
// global variables
const int max_active_applicants = 5000;

int size_of_active_applicants =0;	//to keep track of the number of applicantions in process
int size_of_denied_applicants =0;	//to keep track of the number of applicantions denied
int size_of_approved_applicants = 0; //to keep track of the number of applicantions approved 
int budget=0; // to calculate given budget

SortedArrayList<loan_application> active(max_active_applicants);
SortedArrayList<loan_application> approved(max_active_applicants);
ArrayList<loan_application> denied(max_active_applicants);

void Tokenize(string line, vector<string> & tokens, string delimiters = "\t "){
string token = "";
        string OneCharString = " ";
        for (int i=0; i<line.size(); i++)
                if (find(delimiters.begin(), delimiters.end(), line[i])!=delimiters.end()) // line[i] is one of the delimiter characters
                {
			if (token.size()>0)
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

void SaveApplication(const vector<string>& tokens){


	string name = tokens[1];
	int education = atoi(tokens[2].c_str());
	int work_experience = atoi(tokens[3].c_str()); 
 	int loan_amount = atoi(tokens[4].c_str());
	int pr=0;	
	
	int s = 0;
	for (int i =5; i < tokens.size(); i++) 	
	{ 	
		pr = pr + (atoi(tokens[i].c_str())/(s+1)); 
		s++;
	}
	
	loan_application object(name, education, work_experience, loan_amount, pr);

	active.add(object);

	size_of_active_applicants++;
}

void decision(const vector<string> &tokens)
{
	string gap = " "; 				// Needed a gap for sepearating month day and year 
	
	budget= budget + atoi(tokens[4].c_str());
	string date = tokens[1]+gap+tokens[2]+gap+tokens[3];
	
	
	for (int i=0; i<active.count(); )
	{
		if (active[i].years_of_relevant_education + active[i].years_of_relevant_experience < 10)
		{
			denied[size_of_denied_applicants]=active[i];
			active.removeFirst(active[i]);
			size_of_active_applicants;
			denied[size_of_denied_applicants].decision_date = date;
			size_of_denied_applicants++;
			continue;
		}
		if ((active[i].years_of_relevant_education + active[i].years_of_relevant_experience >= 10) && (active[i].loan_amount <= budget))
		{
			approved[size_of_approved_applicants]=active[i];
			budget = budget - approved[size_of_approved_applicants].loan_amount;
			active.removeFirst(active[i]);
			size_of_active_applicants;
			approved[size_of_approved_applicants].decision_date = date;
			size_of_approved_applicants++;
			continue;
		}
		i++;
	}
}	


void prints(){

	// PRINTS ACTIVE APPLICANTS
	cout << "active_applications\t";
	for (int i=0; i<size_of_active_applicants; i++)
	{
		cout << "(" << active[i].applicant_full_name << "," << active[i].loan_amount << ")\t";
	}
	cout << endl;

	// PRINTS APPROVED APPLICANTS
	cout << "approved_applications\t";
	for (int i=0; i<size_of_approved_applicants; i++)
	{
		cout << "(" << approved[i].applicant_full_name << "," << approved[i].loan_amount << "," << approved[i].decision_date  << ")\t";
	}
	cout << endl;

	// PRINTS DENIED APPLICANTS
	cout << "denied_applications\t";
	for (int i=0; i<size_of_denied_applicants; i++)
	{
		cout << "(" << denied[i].applicant_full_name << "," << denied[i].loan_amount << "," << denied[i].decision_date << ")\t";
	}
	cout << endl;
}

void ReadFile(const char* fname){
	ifstream file;
	file.open(fname);

	string line;
	while (getline(file, line).good()){
		vector<string> tokens;
		Tokenize(line, tokens, "\t ");
		if (tokens.size()==0)
			continue;
		
		if (tokens[0]=="save_application")
			SaveApplication(tokens);			
		
		else if (tokens[0]=="make_decisions")
			decision (tokens);
			
			
		else if (tokens[0]=="print")
			prints();
	}

	file.close();
}

int main(int argc, char** argv){
	if (argc != 2){
		cout << "usage: executable.o commands.txt\n";
		return 1;
	}

	ReadFile(argv[1]);
	return 0;
}


