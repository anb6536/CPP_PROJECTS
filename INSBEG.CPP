Node* Create_New_Node(int n)
{ptr = new Node;
ptr -> info = n;
ptr -> next = NULL ;
return ptr ;
}

void Insert_Beg(Node *np)
	 {
		if ( start == NULL )
		start = np ;
		else
		{	 save = start;
			 start = np ;
			 np -> next = save ;
}}

void Insert_End ( Node *np)
	{	if ( start == NULL )
		start = rear = np;
		else
		{ rear -> next = np ;
		rear = np ;
		}
	}

void DelNode()
{	if ( start == NULL )
	cout << "Underflow !!!\n";
	else
	{ ptr = start;
	start = start -> next;
	delete ptr ;
}

void display ( Node *np )
{	while ( np != NULL)
	{ cout << np -> info << "->";
	  np = np -> next ;
	}
}

