#include <fstream.h>
#include <process.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <iostream.h>
class criminal {
	char name[30],crime_list[100], sex,dob[11],bt[3];
	int U_ID,age;
	float height,weight;

public:
	void disp();
	int get_id() {
		return U_ID; }     //need to access private members
	void enter(); //take data and input into file
	void search_view(); //searcher function
	void del(); //function to delete
	void mod(); //to modify a certain record
	void write();//writes data to file
	}ob1;

void criminal::enter() {
	cout<<"\nEnter name : ";
	gets(name);
	cout<<"\nEnter Unique ID : ";
	cin>>U_ID;
	cout<<"\nSex(M,F or O) : ";
	cin>>sex;
	cout<<"\nEnter DOB(dd/mm/yy) : ";
	gets(dob);
	cout<<"\nBlood Group : ";
	gets(bt);
	cout<<"\nEnter age : ";
	cin>>age;
	cout<<"Enter height (in cm) : ";
	cin>>height;
	cout<<"Enter known crimes/offences/violations : ";
	gets(crime_list);
	write();
	}
void criminal::search_view() {
	cout<<"\n"<<"Enter U_ID to be searched for : ";
	int n;
	cin>>n;
	int res = 0;
	ifstream fin("mainrec.txt",ios::in);
	fin.seekg(0,ios::beg);
	while(!fin.eof()) {
		fin.read((char *) & ob1, sizeof(ob1));
		if(ob1.get_id() == n) {
			ob1.disp();
			res = 1;
			break;
			}}
	if(res == 0) {
		cout<<"\n"<<"Sorry the record was not found. ";
		}
		}
void criminal::disp() {
	clrscr();
	cout<<"\nName : "<<name;
	cout<<"\nSex : "<<sex;
	cout<<"\nDOB : "<<dob;
	cout<<"\nBlood Group : "<<bt;
	cout<<"\nAge : "<<age;
	cout<<"\nHeight : "<<height<<" cm";
	cout<<"\nKnown crimes/offences/violations : ";
	puts(crime_list);
	}
void criminal::write() {
	ofstream fout;
	fout.open("mainrec.txt", ios::out | ios::app);
	fout.write((char*)&ob1, sizeof(ob1));
	fout.close();
	cout<<"\nRecord succesfully enterd.";
	}

void criminal::mod(){  clrscr();
	cout<<"\nEnter the U_ID of the record you want to modify : ";
	int x;
	cin>>x;
	fstream f("mainrec.txt", ios::in|ios::out);
	f.seekg(0, ios::beg);
	f.read((char *) & ob1, sizeof(ob1));
	int a = f.tellg();
	while(!f.eof())
	{
		if(ob1.U_ID == x)
			{       cout<<"\nRECORD : ";cout<<"\n";
				ob1.disp();
				cout<<"\n"<<"\n"<<"\n";
				cout<<"\n1.Change Name."<<"\n2.Change UID.";
				cout<<"\n3.Change Sex."<<"\n4.Change DOB.";
				cout<<"\n5.Change blood group."<<"\n6.Change age.";
				cout<<"\n7.Change height.";
				cout<<"\n8.Change crime list."<<"\n\nEnter your choice : ";
				int p;
				cin>>p;
				switch(p) {
					case 1: cout<<"\nEnter new name : ";
						gets(name);
						break;
					case 2: cout<<"\nEnter new U_ID : ";
						cin>>U_ID;
						break;
					case 3: cout<<"\nEnter new Sex : ";
						cin>>sex;
						break;
					case 4: cout<<"\nEnter new value for DOB : ";
						gets(dob);
						break;
					case 5: cout<<"\nEnter changed blood group : ";
						cin>>bt;
						break;
					case 6: cout<<"\nEnter new age : ";
						cin>>age;
						break;
					case 7: cout<<"\nEnter new list of crimes : ";
						gets(crime_list);
						break;
						}
					f.seekg(a-sizeof(ob1), ios::beg);
					f.write((char*)&ob1, sizeof(ob1));
				}
				f.read((char*)&ob1, sizeof(ob1));
				a=f.tellg();
				cout<<"\nRecord succesfully modified!";
			}
			f.close();
			}
 /*
void criminal::del() {
	ifstream fio("mainrec.dat", ios::in);
	ofstream file("temp.dat", ios::out );
	int UIDdel;
	char found='f', confirm='n';

	cout << "Enter the Unique ID of criminal whose record is to be deleted \n";
	cin >> UIDdel;

	while (!fio.eof()) {
		fio.read((char*)&ob1, sizeof(ob1));
		if (ob1.get_id()==UIDdel){//2
			ob1.disp();
			found='t';
			cout << "\tAre you sure you want to delete this record? (y/n)";
			cin >> confirm ;
			if (confirm == 'n')
				file.write((char*)&ob1, sizeof(ob1));
		}  //2-
		else
			file.write((char*)&ob1, sizeof(ob1));
		}   //1-

		if (found == 'f')
			cout << "Record not found\n";
			fio.close();
			file.close();
			remove("mainrec.txt");
			rename("temp.txt","mainrec.txt");
			fio.open("mainrec.txt", ios::in);
			cout << "\tNow the file contains :";
			while(!fio.eof())
			{	fio.read((char*)&ob1, sizeof(ob1));
				if (fio.eof())break ;
				ob1.disp();
			}
			fio.close();
				}     */

void criminal::del() {
	ifstream fin;
	fin.open("mainrec.txt",ios::in);
	ofstream fout;
	fout.open("temp.txt",ios::out);
	cout<<"\nEnter the UID of the record you want to delete : ";
	int id; cin>>id;
	char found = 'f'; char confirm = 'n';
	while(!fin.eof()) {
		fin.read((char*)&ob1,sizeof(ob1));
		if(ob1.get_id() == id) {
			cout<<"\nRequested record was found.";
			found = 't';
			ob1.disp();
			cout<<"\nDo you want to delete this record ? (y/n)";
			cin>>confirm;
			if(confirm =='n')
			fout.write((char*)&ob1,sizeof(ob1));
			}
		else
			fout.write((char*)&ob1,sizeof(ob1));
			}
		if(found == 'f')
			cout<<"\nThe record was not found.";
		fin.close();
		fout.close();
		remove("mainrec.txt");
		rename("temp.txt","mainrec.txt");
		cout<<"\nRecord deletion succesful.";
		}

void intro() {
	clrscr();
	cout<<"***************************CRIMINAL RECORDS MANAGEMENT SYSTEM****************";
	cout<<"\n"<<"\n"<<"\n"<<"\n";
	cout<<"\n1. Intro.";
	cout<<"\n2. Enter a new record. ";
	cout<<"\n3. View an existing record. ";
	cout<<"\n4. Modify an existing record. ";
	cout<<"\n5. Delete an existing record. ";
	cout<<"\n6. Exit. ";
	}

void intr() {
	clrscr();
	cout<<"**INTRODUCTION**";
	cout<<"\n\nThis is is a record management system which can be used to";
	cout<<" store and process several records. The main menu provides";
	cout<<" several options to enter,delete or modify the records.";
	cout<<"\nFor proper functioning, some details have to be entered ";
	cout<<"in the following specified manner : ";
	cout<<"\nDate of Birth(DOB) should be written in full in the format : ";
	cout<<"dd/mm/yy. For example : ";
	cout<<"\n Enter DOB : 20/03/2000 ";
	cout<<"\n\nEach submenu is easy to follow as intructions will be displayed.";
}

void main() {
	char choice;  clrscr();
	 do {intro(); //do-while begins
	cout<<"\n"<<"\n Enter Choice : ";
	int a;
	cin>>a;
	switch(a) {
		case 1: clrscr();
			intr();
			break;
		case 2: clrscr();
			ob1.enter();
			break;
		case 3: clrscr();
			ob1.search_view();
			break;
		case 4: clrscr();
			ob1.mod();
			break;
		case 5: clrscr();
			ob1.del();
			break;
		case 6: exit(0);
		default: cout<<"\n";
			 cout<<"Sorry that's not an option : ";
			 }

		cout<<"\nEnter 'y' to return to main menu, 'n' to exit (y/n) :";
		cin>>choice;
		clrscr();  } while (choice == 'y');
		cout<<"\nGood bye";
		getch();

 }