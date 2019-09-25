#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
int b1_x, b1_y,user_x,user_y,b2_x,b2_y ;
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

	getch();

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

	b2_x = random(6)+1;

	b2_y = random(6)+1;

	}


void mgmt_input(void) {
	int countx1 = 3;
	int county1 = 3;
	int countx2 = 3;
	int county2 = 3;

	cout<<"You have 3 tries. \n";
	for(int i = 0; i < 3; i++) {      countx1--;
		cout<<"Enter the guessed row no. :- ";
		cin>>user_x;
		if(user_x == b1_x) {
			cout<<"Correct row number,now find the right column. \n";
			cout<<"You will get 3 tries. \n";
			cout<<"Enter the guessed column no :- ";
		for(int j = 0; j < 3; j++) { county1--;
			cin>>user_y;
			if (user_y ==  b1_y) {
				a[b1_x-1][b1_y-1] = 'X';
				clrscr();
				field();
				cout<<"\n\n\nYou have found the battleship"<<"\n";
				break;
				      }
			else if (user_y != b1_y) {
				if (county1==0)
				cout<<"Better luck next time ";
				else
				cout<<"Not that one, try again \n";
				continue;
				}
				}break;  }
		else if(user_x != b1_x) {
			if (countx1==0)
			cout<<"You have run out of tries!! \n";
			else
			cout<<"Oops wrong row number, try again \n";
			continue;
			}
			}
	cout<<"You have more 3 tries. \n";
	for(i = 0; i < 3; i++) {      countx2--;
		cout<<"Enter the guessed row no. :- ";
		cin>>user_x;
		if(user_x == b2_x) {
			cout<<"Correct row number,now find the right column. \n";
			cout<<"You will get 3 tries. \n";
			cout<<"Enter the guessed column no :- ";
		for(int j = 0; j < 3; j++) { county2--;
			cin>>user_y;
			if (user_y ==  b2_y) {
				a[b2_x-1][b2_y-1] = 'X';
				clrscr();
				field();
				cout<<"\n\n\nYou have found the battleship"<<"\n";
				break;
				      }
			else if (user_y != b2_y) {
				if (county1==0)
				cout<<"Better luck next time ";
				else
				cout<<"Not that one, try again \n";
				continue;
				}
				}break;  }
		else if(user_x != b2_x) {
			if (countx2==0)
			cout<<"You have run out of tries!! \n";
			else
			cout<<"Oops wrong row number, try again \n";
			continue;
			}
			}

}

void welcome(void) {
	int i,k;
	cout<<"\t"<<"\t"<<"\t"<<"Welcome to the Battleship Project ";
	cout<<"\n"<<"\n"<<"\n";
	cout<<"1. Play the game. ";
	cout<<"\n"<<"2. Tutorial. ";
	cout<<"\n"<<"Enter your choice : ";
	cin>>i;
	switch(i) {
		case 1:
			cout<<"\n"<<"\n"<<"\n"<<"\n";
			field();
			cout<<"\n"<<"\n";
			bs_placer();
			cout<<"\n"<<"\n";
			mgmt_input();
			getch();
			break;
		case 2:
		       clrscr();
		       cout<<"Welcome to battleship. This game is about finding"<<"\n";
		       cout<<"the battleships hidden in a grid of dimensions 6x6"<<"\n";
		       cout<<"the goal is to guess where the battleships are hidden."<<"\n";
		       cout<<"There are a total of 2 Battleships that are needed to be searched for .";
		       cout<<"Guess the coordinates of the Battleship by entering them . ";
		       cout<<"\n"<<"\n"<<"\n"<<"Press 1 to return to the main menu.";
		       cout<<"\n"<<"Press 2 to exit.";
		       cout<<"\n"<<"Enter your choice. ";
		       cin>>k;
		       switch(k) {
				case 1:
					clrscr();
					welcome();
					break;
				case 2:
					exit(0);}
		       break;

		default:
			cout<< "Oops that's not an option."<<endl;
			exit(0);
			     }
			     }

