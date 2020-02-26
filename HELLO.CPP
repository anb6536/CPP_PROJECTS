#include<iostream.h>
#include<conio.h>
#include<stdio.h>

const int LEN=25 ;

class PERSON {
	private :
		char name[LEN];
		int age;

	public :
		void readperson(void);
		void displayperson(void)
		{	cout << " Name : ";
			gets(name);
			cout << "\tAge : " << age << "\n" ;
		}
	     };

void PERSON::readperson(void)
{	for (int i=0 ; i<LEN ; i++)
	name[i]=' ';
	cout << "Enter Name of the Person : ";
	gets(name);
	cout << "Enter age : " ;
	cin >> age;
}

class STUDENT : public PERSON {
	private :
		int RollNo ;
		float Average ;

	public :
		void readstudent(void)
		{	readperson();
			cout << "Enter Roll No. : " ;
			cin >> RollNo ;

			cout << "\nEnter Average marks : " ;
			cin >> Average ;
		}

		void disp_rollno(void)
		{	cout << "\Roll No. : " << RollNo << "\n" ;
		}

		float getaverage(void)
		{	return Average ;
		}

			      };

class GradStudent : public STUDENT {
	private :
		char subject[LEN];
		char working ;

	public :
		void readit(void);
		void displaysubject(void)
		{	cout << "Subject : ";
			gets(subject);
		}

		char workstatus(void)
		{	return working ;
		}
				   };

void GradStudent::readit(void)
{	readstudent();
	for(int i=0 ; i<LEN ; i++)
	subject[i]=' ' ;
	cout << "Enter Main Subject : ";
	gets(subject);
	cout << "Working? (Y/N) : ";
	cin >> working ;
}


int main()
{	clrscr();
	const int size=5;	//size stores no. of graduates
	GradStudent grad[size] ;
	int year , num_working=0, non_working=0 , div1=0 , total=0 ;
	float topscore = 0 , score , number , wperc , nwperc ;

/**********************************************************************************
num_working		stores the number of working Graduates
non_working 		stores the number of non working Graduates
div1			stores the number of first divisioner
total 			stores the total number of Graduates
topscore 		stores the highest Average
score 			stores the average number of Graduate Students
number 			stores the ith number of the Graduates in the list
***********************************************************************************************/

cout << "Enter Year : ";
cin >> year ;

//Loop for processing graduates information
for (int i = 0 ; i < size ; i++)	//to read information for ith graduate
{	cout << "Enter Details for Graduate " << (i+1) << "\n";
	grad[i].readit();
	total++;		//add to total
	//Loop to count number of working and non working students
	if ((grad[i].workstatus()=='y')||(grad[i].workstatus()=='Y'))
		num_working++;
	else non_working++;

	//Determine the top scorer
	score = grad[i].getaverage();
	if (score>topscore)
	{	topscore=score ;
		number = i;
	}

	//count the number of First Divisioner
	if (score>=60 )
	div1++;
	}//end of loop
//now Print the Report
i=number ;

cout << "\n" << "\t\tReport of the Year " << year << "\n";
cout << "\t\t-------------------------------------------------------\n";
cout << "\nWorking Graduates :" << num_working ;
cout << "\tNon Working Graduates :" << non_working << "\n" ;
cout << "\nDetails of the Top Scorer :\n";
grad[i].displayperson();
grad[i].displaysubject();
nwperc=((float)non_working/(float)total)*100;
wperc=((float)div1/(float)total)*100;

cout << "\tAverage Marks :" << grad[i].getaverage() << "\n" ;
cout << "\t" << nwperc << "% of Graduates this year are not working and \n"
<< wperc << "% are first divisioners \n";

return 0 ;
}		//end of main()