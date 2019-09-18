#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

struct node
{
	char data;
	struct node *next;
}*top;				//top as pointer for returning address

class post			//class for prefix
{
	public:post()	//member function
	{
		top=NULL;	//initial adress of top is NULL
	}

	int empty() //member function
	{
		if(top==NULL)
			return 1;
		return 0;
	}

	char TOP()
	{
		return(top->data);			//for returning the data
	}

	void push(char x)
	{
		node *p;
		p=new node;			//creation of new node
		p->data=x;
		p->next=top;		//top points to the last inserted element
		top=p;
	}

	char pop()
	{
		char x;
		node *p;
		p=top;
		top=top->next;		//top pointing to last element
		x=p->data;
		delete p;			//deleting p
		return(x);			//keeping track of poped elements
	}

	int preced(char x)
	{
		if(x=='(')
			return(0);
		if(x=='+'||x=='-')
			return(1);
		if(x=='*'||x=='/'||x=='%')
			return(2);
		return(3);
	}

	void inf_to_post(char infix[],char postfix[])
	{
		char temp,x;
		int i,j=0;
		for(i=0;infix[i]!='\0';i++)
		{
			temp=infix[i];
			if(isalnum(temp))			//checking for alphabet & numerical
				postfix[j++]=temp;		// increment expression list as alnum comes
			else if(temp=='(')
				push('(');				//pushing to stack
			else if(temp==')')
				while((x=pop())!='(')		//poping elements till ( comes
					postfix[j++]=x;			//incrementing list
			else
			{
				while(preced(temp)<preced(TOP())&&!empty())
				{
					x=pop();
					postfix[j++]=x;
				}
				push(temp);
			}
		}
		while(!empty())				//still any elemnts in stack? then pop them to
		{							//expression list & increment the expression list
			x=pop();
			postfix[j++]=x;
		}
		postfix[j]='\0';
	}
};

void main()
{
	clrscr();
	post p;
	char infix[50],postfix[50];
	cout<<"\nEnter infix expression: ";
	cin>>infix;
	p.inf_to_post(infix,postfix);
	cout<<"\nPostfix expression is: "<<postfix;
	getch();
}