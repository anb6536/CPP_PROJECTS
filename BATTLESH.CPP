#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
int b1_x, b1_y,user_x,user_y;
char a[7][6] = {'o','o','o','o','o','o','o','o','o',
		'o','o','o','o','o','o','o','o','o'
		,'o','o','o','o','o','o','o','o','o'
		,'o','o','o','o','o','o','o','o','o' };
void mgmt_input(void);  //The mgmt function
void intro(void);
void field(void); //grid printing
void bs_placer(void);            //randomises places of the battleships
void main() { clrscr();
	intro();
	cout<<"\n"<<"\n"<<"\n"<<"\n";
	field();
	cout<<"\n"<<"\n";
	bs_placer();
	cout<<"\n"<<"\n";
	mgmt_input();
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
	b1_x = random(7);

	b1_y = random(6);


	cout<<"\n"<<b1_x;

	cout<<"\n"<<b1_y;

	}
void intro(void) {
	cout<<"Welcome to the battleship project,this is an interesting game " ;
	cout<<"which is played on a grid .The goal of this game is to guess";
	cout<<" the positions of the two battleships(or objects) ";
	cout<<"hidden in the grid.Each ship has an x and a y coordinate.";
	}

void mgmt_input(void) {
	int count = 3;
	cout<<"You have 3 tries \n";
	for(int i = 0; i < 3; i++) {      count--;
		cout<<"Enter the guessed row no. :- ";
		cin>>user_x;
		if(user_x == b1_x) {
			cout<<"Correct row number,now find the right column \n";
			cout<<"You will get 3 tries \n";
		for(int j = 0; j < 3; j++) {
			cin>>user_y;
			if (user_y ==  b1_y) {
				cout<<"You have found the battleship"<<"\n";
				a[b1_x][b1_y] = 'X';
				clrscr();
				field();
				break;
				      }
			else if (user_y != b1_y) {
				cout<<"Not that one, try again \n";
				continue;
				}
				}break;  }
		else if(user_x != b1_x) {
			cout<<"Oops wrong row number, try again \n";
			continue;
			}
			}
       if(count == 0) {
	cout<<"You have run out of tries! \n";
	exit(0);       }
}


