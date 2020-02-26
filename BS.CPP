#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
int b1_x, b1_y,user_x,user_y;
char a[7][6] = {'o','o','o','o','o','o','o','o','o',
		'o','o','o','o','o','o','o','o','o'
		,'o','o','o','o','o','o','o','o','o'
		,'o','o','o','o','o','o','o','o','o' };
void welcome(void);
void mgmt_input(void);  //The mgmt function
void field(void); //grid printer
void bs_placer(void);    //randomises co-ordinates of the battleships
void main() { clrscr();

	welcome();
	clrscr();


	}

void field(void) {

	for(int i = 0; i < 6; i++) {
		cout<<"\n"<<"\n";
		for(int j = 0; j <  6; j++) {
			cout<<" "<<" "<<a[i][j];
			}	}
			}

void bs_placer(void) {

	randomize();
	b1_x = random(6)+1;

	b1_y = random(6)+1;

	cout<<b1_x<<" "<<b1_y;

	}


void mgmt_input(void) {
	int countx = 3;
	int county = 3;
	int score = 0;
	cout<<"You have 3 tries. \n";
	for(int i = 0; i < 3; i++) {      countx--;
		cout<<"Enter the guessed row no. :- ";
		cin>>user_x;
		if(user_x == b1_x) {
			cout<<"Correct row number,now find the right column. \n";
			cout<<"You will get 3 tries. \n";
			cout<<"Enter the guessed column no :- ";
		for(int j = 0; j < 3; j++) { county--;
			cin>>user_y;
			if (user_y ==  b1_y) {
				a[b1_x-1][b1_y-1] = 'X';
				clrscr();
				field();
				cout<<"\n\n\nYou have found the battleship"<<"\n";
				break;
				      }
			else if (user_y != b1_y) {
				if (county==0)
				cout<<"Better luck next time ";
				else
				cout<<"Not that one, try again \n";
				continue;
				}
				}break;  }
		else if(user_x != b1_x) {
			if (countx==0)
			cout<<"You have run out of tries!! \n";
			else
			cout<<"Oops wrong row number, try again \n";
			continue;
			}
			}

}

void welcome(void) {
	int i;
	cout<<"\t"<<"\t"<<"\t"<<"Welcome to the Battleship Project ";
	cout<<"\n"<<"\n"<<"\n";
	cout<<"i. Tutorial. ";
	cout<<"\n"<<"ii. Play Game. ";
	cout<<"\n"<<"Enter your choice : ";
	cin>>i;
	switch(i) {
		case 2:
		       { cout<<"\n"<<"\n"<<"\n"<<"\n";
			field();
			cout<<"\n"<<"\n";
			bs_placer();
			cout<<"\n"<<"\n";
			mgmt_input();
			getch();
			break;}
		case 1:
		      { cout<<"Welcome to battleship. This game is about finding"<<"\n";
		       cout<<" the battleships hidden in a grid of dimensions m x n"<<"\n";
		       cout<<" the goal is to guess where the battleships are hidden."<<"\n";
		       break;}

		default:
			cout<< "Oops that's not an option."<<endl;
			exit(0);
			     }
			     }

