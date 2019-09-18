#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

struct node
{
	char data;
	struct node *next;
}*top;		//top as pointer for returning address

class pref		//class for prefix
{
	public:pref()		//member function
	{
		top=NULL;		//initial adress of top is NULL
	}

	int empty()		//member function
	{
		if(top==NULL)
			return 1;
		return 0;
	}

	char TOP()
	{
		return(top->data);		//for returning the data
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

	void inf_to_pref(char infix[],char prefix[])
	{
		char temp,rev[30];
		int i,j;
		//condition stating move untill first element in expression
		for(i=strlen(infix)-1,j=0;i>=0;i--,j++)
			rev[j]=infix[i];	//changing the position of 1st with last element
		rev[j]='\0';			//change till last element
		//condition stating reverse till first element
		for(i=0;rev[i]!=0;i++)
		{
			if(rev[i]=='(')
				rev[i]=')';
			else if(rev[i]==')')
				rev[i]='(';
		}
		inf_to_post(rev,prefix);
		//condition stating reverse till last element of prefix expression
		for(i=0,j=strlen(prefix)-1;i<j;i++,j--)
		{
			temp=prefix[i];
			prefix[i]=prefix[j];
			prefix[j]=temp;
		}
	}

	void inf_to_post(char infix[],char postfix[])
	{
		char temp,x;
		int i,j=0;
		for(i=0;infix[i]!='\0';i++)
		{
			temp=infix[i];
			if(isalnum(temp))				//checking for alphabet & numerical
				postfix[j++]=temp;			// increment expression list as alnum comes
			else if(temp=='(')
				push('(');					//pushing to stack
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
		while(!empty())			//still any elemnts in stack? then pop them to
		{						//expression list & increment the expression list
			x=pop();
			postfix[j++]=x;
		}
		postfix[j]='\0';
	}
};

void main()
{
	clrscr();
	pref p;
	char infix[50],prefix[50];
	cout<<"\nEnter infix expression: ";
	cin>>infix;
	p.inf_to_pref(infix,prefix);
	cout<<"\nPrefix expression is: "<<prefix;
	getch();
}