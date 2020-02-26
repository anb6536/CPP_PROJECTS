//                   HEADER FILE USED IN PROJECT

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<ctype.h>


//                   CLASS FOR PROJECT

class account
{
		int acno;
		char name[100];
		int deposit, withdraw;
		char type;
	public:
		void create_ac();
		void show_ac();
		void modify_ac();
		void dep(int x)
		{
			deposit+=x;
		}
		void draw(int x)
		{
			deposit-=x;
		}
		void report()
		{
			cout<<acno<<"\t"<<name<<"\t\t"<<type<<"\t\t"<<deposit<<endl;
		}
		int  retacno()
		{
			return acno;
		}
		float retdeposit()
		{
			return deposit;
		}
		char rettype()
		{
			return type;
		}
};

void account :: create_ac()
{
	cout <<"\nEnter the account number : ";
	cin >>acno;
	cout <<"\nEnter the name of the account holder : ";
	gets(name);
	cout <<"\nEnter type of the account (C/S) : ";
	cout <<"\n(C for current account, S for savings account)\n";
	cin >>type;
	type=toupper(type);
	cout <<"\nEnter the initial amount :\n(>=500 for Saving and >=1000 for current)\n";
	cin >>deposit;
	if(type=='C')
	{
		clrscr();
		while(deposit<1000)
		{	cout << "\nThe minimum initial amount for current account is 1000.";
			cout << "\nEnter a valid amount : ";
			cin >>deposit;
		}
	}
	if(type=='S')
	{
		clrscr();
		while(deposit<500)
		{	cout << "\nThe minimum initial amount for savings account is 1000.";
			cout << "\nEnter a valid amount : ";
			cin >>deposit;
		}
	}
	cout << "\nCreated account..";
	cout <<"\nPress any key to go back to Main Menu..";
}

void account :: show_ac()
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : ";
	puts(name);
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
}

void account :: modify_ac()
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nModify Account Holder Name : ";
	gets(name);
	cout<<"\nModify type of Account : ";
	cin>>type;
	cout<<"\nModify balance amount : ";
	cin>>deposit;
	cout <<"\nPress any key to go back to Main Menu..";
}



//    	global declaration for stream object

 fstream fp;
 account ac;


//    	function to write in file

void write_ac()
{
    fp.open("account.dat",ios::out|ios::app);
    ac.create_ac();
    fp.write((char*)&ac,sizeof(account));
    fp.close();
}


//    	function to read specific record from file

void display_sp(int n)
{
    clrscr();
    cout<<"\nBALANCE DETAILS\n";
    int flag=0;
    fp.open("account.dat",ios::in);
    while(fp.read((char*)&ac,sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_ac();
			flag=1;
		}
	}
    cout <<"\nPress any key to go back to Main Menu..";
    fp.close();
    if(flag==0)
    {
	cout<<"\n\nAccount number does not exist.";
	cout <<"\nPress any key to go back to Main Menu..";
    }
    getch();
}


//    	function to modify record of file

void modify_ac()
{
    int no,found=0;
    clrscr();
    cout<<"\n\n\tTo Modify ";
    cout<<"\n\n\tEnter the account no. : ";
    cin>>no;
    fp.open("account.dat",ios::in|ios::out);
    while(fp.read((char*)&ac,sizeof(account)) && found==0)
	{
	    if(ac.retacno()==no)
		{
		    ac.show_ac();
		    cout<<"\nEnter the new details of account : "<<endl;
		    ac.modify_ac();
		    int pos=-1*sizeof(ac);
		    fp.seekp(pos,ios::cur);
		    fp.write((char*)&ac,sizeof(account));
		    cout<<"\n\n\t Record Updated...";
		    cout <<"\nPress any key to go back to Main Menu..";
		    found=1;
		}
	}
    fp.close();
    if(found==0)
    cout<<"\n\n Record Not Found. ";
    cout <<"\nPress any key to go back to Main Menu..";
    getch();
}


//    	function to delete record of file

void delete_ac()
{
    int no;
    clrscr();
    cout<<"\n\n\n\tDelete Record ";
    cout<<"\n\nEnter the account no. of the account you want to delete : ";
    cin>>no;
    fp.open("account.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&ac,sizeof(account)))
	{
		if(ac.retacno()!=no)
		{
			fp2.write((char*)&ac,sizeof(account));
		}
	}
    fp2.close();
    fp.close();
    remove("account.dat");
    rename("Temp.dat","account.dat");
    cout<<"\n\n\tRecord Deleted ..";
    cout <<"\nPress any key to go back to Main Menu..";
    getch();
}


//    	function to display all accounts deposit list

void display_all()
{
    clrscr();
    fp.open("account.dat",ios::in);
    if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
		getch();
	return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.\tNAME\t\tType\t\tBalance\n";
	cout<<"====================================================\n";
	while(fp.read((char*)&ac,sizeof(account)))
	{
		ac.report();
	}
	cout <<"\n\n\nPress any key to go back to Main Menu..";
    fp.close();
}


//    	function to deposit and withdraw amounts

void deposit_withdraw(int option)
{
	int no,found=0,amt;
    clrscr();
    cout<<"\n\n\tEnter the account No. : ";
    cin>>no;
    fp.open("account.dat",ios::in|ios::out);
    while(fp.read((char*)&ac,sizeof(account)) && found==0)
    {
		if(ac.retacno()==no)
	    {
		    ac.show_ac();
		    if(option==1)
		    {
				cout<<"\n\n\tTO DEPOSIT AMOUNT ";
				cout<<"\n\nEnter the amount to be deposited : ";
				cin>>amt;
				ac.dep(amt);
		    }
		    if(option==2)
		    {
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdrawn : ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
				cout<<"Insufficience balance.";
				else
				ac.draw(amt);
		    }
			int pos=-1*sizeof(ac);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&ac,sizeof(account));
			cout<<"\n\n\t Record Updated...";
			cout <<"\nPress any key to go back to Main Menu..";
			found=1;
	    }
    }
    fp.close();
    if(found==0)
	cout<<"\n\n Record Not Found. ";
    cout <<"\nPress any key to go back to Main Menu..";
    getch();
}


//    	INTRODUCTION FUNCTION

void intro()
{
	clrscr();
	cout <<"\n\n";
	for(int i=0; i<78; i++)
	{
		cout <<"=";
	}
	gotoxy(33,5);
	cout<<"BANKING SYSTEM\n\n";
	cout<<"\n\n\n\nMADE BY : Manak Mishra & Abhishek Das";
	cout<<"\nSCHOOL : Somerville School\n\n\n\n\n\n";
	cout<<"\nPress Enter to continue...\n\n";
	for(i=0; i<78; i++)
	{
		cout <<"=";
	}
	getch();
}


//    	THE MAIN FUNCTION OF PROGRAM

void main()
{
	char ch;
	intro();
	do
    {
		clrscr();
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8) ";
		cin>>ch;
		switch(ch)
		{
			case '1': clrscr();
			          write_ac();
			          getch();
				  break;
			case '2': clrscr();
				  deposit_withdraw(1);
				  break;
			case '3': clrscr();
				  deposit_withdraw(2);
				  getch();
				  break;
			case '4': int num;
				  clrscr();
				  cout<<"\n\n\tEnter the account no. ";
				  cin>>num;
				  display_sp(num);
				  break;
			case '5': clrscr();
				  display_all();
				  getch();
				  break;
			case '6': delete_ac();
				  break;
			case '7': clrscr();
			      	  modify_ac();
				  getch();
				  break;
			case '8': clrscr();
				  cout<<"\nPress Enter to exit...\n";
				  getch();
				  exit(0);
			default : cout<<"\a";
		}
    }	while(ch!='8');
}


//    			END OF PROJECT

