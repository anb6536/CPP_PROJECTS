/******************************************************************************
********************            Calculator            ************************************
*****************************************************************************/

#include<iostream.h>
#include<conio.h>

void main ()
{	clrscr();

	int A[3][3];
	int B[3][3];

	cout << "This is a program to transpose a Matrix ";
	cout << "\nEnter data into a 3X3 matrix ";

	for ( int i=0 ; i<3 ; i++)
		for (int j=0 ; j<3 ; j++)
		{	cin >> A[i][j];
		}

	cout << "\nYou have entered the following Matrix\n";

	for ( i=0 ; i<3 ; i++)
	       {	for ( j=0 ; j<3 ; j++)
			{	cout <<" "<< A[i][j] << " " ;
			}
			cout << "\n";
	       }
}
