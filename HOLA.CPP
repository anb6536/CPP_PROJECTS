#include<iostream.h>
#include<process.h>
#include<conio.h>

void main()

{  clrscr();


	int a[10][10],b[10][10],c[10][10];
	int i,j,m,n,p,q;

	//Input Rows and Columns of matrices A[m][n] and B[p][q]

	cout << "\nInput Row and Column of Matrix A\n" ;
	cin >> m >> n ;

	cout << "\nInput Row and Column of Matrix B\n" ;
	cin >> p >> q ;

		if((m==p) && (n==q))     //To check if Matrices can be added.
			cout << "Matrix can be added\n" ;
		else
		{	cout << "Matrix cannot be added\n";
		exit(0);
		}

	cout << "\nInput Matrix A\n";
	for(i=0 ; i<m ; i++)
	{
		for(j=0 ; j<n ; j++)
		cin >> a[i][j] ;
	}
	cout << "\nMatrix A:";
		for(i=0 ; i<m ; i++)
		{	cout << "\n";
			for(j=0 ; j<n ; j++)
				cout << " " << a[i][j];
		}


	cout << "\nInput Matrix B\n";
	for(i=0 ; i<p ; i++)
	{
		for(j=0 ; j<q ; j++)
		cin >> b[i][j] ;
	}
	cout << "\nMatrix A:";
		for(i=0 ; i<p ; i++)
		{	cout << "\n";
			for(j=0 ; j<q ; j++)
				cout << " " << b[i][j];
		}

	for(i=0 ; i<m ; i++)
	{
		for(j=0 ; j<n ; j++)
		c[i][j] = a[i][j] + b[i][j];
	}

	cout << "\nThe Sum of two Matrix is :\n" ;

	for(i=0 ; i<m ; i++)
	{
		cout << "\n";
		for(j=0 ; j<n ; j++)
			cout << " " << c[i][j];
	}
getch();
}