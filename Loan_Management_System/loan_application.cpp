#include "loan_application.h"

using namespace std;

loan_application:: loan_application(){};

loan_application::loan_application (string applicant_full_name, int years_of_relevant_education, int years_of_relevant_experience, int loan_amount, int priority)
{
	this->applicant_full_name = applicant_full_name;
	this->years_of_relevant_education = years_of_relevant_education;
	this->years_of_relevant_experience = years_of_relevant_experience;
	this->loan_amount = loan_amount;
	//this->decision_date = "0";
	this->priority = priority;
	//calculate_priority ();
}


loan_application::loan_application (const loan_application &applicant) 
{
	this->applicant_full_name = applicant.applicant_full_name;
	this->years_of_relevant_education = applicant.years_of_relevant_education;
	this->years_of_relevant_experience = applicant.years_of_relevant_experience;
	this->loan_amount = applicant.loan_amount;
	//this->decision_date = applicant.decision_date;
	this->priority = applicant.priority;

}
loan_application& loan_application::operator= (const loan_application &applicant)
{
	if (this == &applicant)
		return *this;
	else
	{
		this->applicant_full_name = applicant.applicant_full_name;
		this->years_of_relevant_education = applicant.years_of_relevant_education;
		this->years_of_relevant_experience = applicant.years_of_relevant_experience;
		this->loan_amount = applicant.loan_amount;
		//this->decision_date = applicant.decision_date;
		this->priority = applicant.priority;

	}
}

bool loan_application::operator< (const loan_application &applicant) const
{
	if (this->priority > applicant.priority)
		return true;
	else
		return false;
}
bool loan_application::operator== (const loan_application &applicant) const
{
	if (this->priority == applicant.priority)
		return true;
	else
		return false;
}
bool loan_application::operator> (const loan_application &applicant) const
{
	if (this->priority < applicant.priority)
		return true;
	else
		return false;
}
bool loan_application::operator>= (const loan_application &applicant) const
{
	if (this->priority <= applicant.priority)
		return true;
	else
		return false;
}
bool loan_application::operator<= (const loan_application &applicant) const
{
	if (this->priority >= applicant.priority)
		return true;
	else
		return false;
}
bool loan_application::operator!= (const loan_application &applicant) const
{
	if (this->priority != applicant.priority)
		return true;
	else
		return false;
}
ostream& operator<< (ostream &out, const loan_application &applicant)
{
	out << applicant.applicant_full_name << endl;
	out << applicant.years_of_relevant_education << endl;
	out << applicant.years_of_relevant_experience << endl;
	out << applicant.loan_amount << endl;

	return out;
}



