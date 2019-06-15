#include <iostream>
#include <string>
#include "SortedArrayList.h"
using namespace std;

class loan_application
{
public:
	string applicant_full_name;
	int years_of_relevant_education;
	int years_of_relevant_experience;
	int loan_amount;
	int priority;
	string decision_date;

	loan_application();
	loan_application (string applicant_full_name, int years_of_relevant_education, int years_of_relevant_experience, int loan_amount, int priority);


	loan_application (const loan_application &applicant);
	
	friend void make_decisions (string decision_date, int budget, ArrayList<loan_application> &denied, SortedArrayList<loan_application> &active, SortedArrayList<loan_application> &approved);
	loan_application& operator= (const loan_application &applicant);

	bool operator< (const loan_application &applicant) const;

	bool operator== (const loan_application &applicant) const;

	bool operator> (const loan_application &applicant) const;

	bool operator>= (const loan_application &applicant) const;

	bool operator<= (const loan_application &applicant) const;

	bool operator!= (const loan_application &applicant) const;
	
	friend ostream& operator<< (ostream &out, const loan_application &applicant);
};