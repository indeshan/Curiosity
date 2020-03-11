#include<iostream.h>
#include<ctype.h>
#include<conio.h>
#include<math.h>
struct node
{
	float data;
	node *next;
}*top;

class evaluate
{
	public:evaluate()
	{
		top=NULL;
	}
	void push(float val)
	{
		node *temp=new node;
		temp->data=val;
		temp->next=top;
		cout<<"\n  Pushed elements is: "<<temp->data;
		cout<<"\n";
		top=temp;
	}

	float pop()
	{
		float val;
		node *s;
		if(top==NULL)
		{
			cout<<"\nStack is empty!!!";
		}
		else
		{
			val=top->data;
			cout<<"\n  Poped element is: "<<top->data;
			s=top->next;
			delete top;
			top=s;
		}
		return val;
	}

	void posteval(const char *postfix)
	{
		int i;
		float b,c;
		for(i=0;postfix[i];i++)
		{
			if((postfix[i]>='A'&&postfix[i]<='Z')||(postfix[i]>='a'&&postfix[i]<='z'))
			{
				cout<<"\nEnter value of "<<postfix[i]<<":";
				cin>>b;
			}
			else
			{
				c=pop();
				b=pop();
				switch(postfix[i])
				{
					case '+':b=b+c;
						break;
					case '-':b=b-c;
						break;
					case '*':b=b*c;
						break;
					case '/':b=b/c;
						break;
					case '^':b=pow(b,c);
						break;
				}
			}
			push(b);
		}
		cout<<"\nResult of Evaluation is: "<<top->data;
	}
};

void main()
{
	char expr[20];
	clrscr();
	cout<<"\n*****Postfix Evaluation****";
	cout<<"\nEnter Postfix expression: ";
	cin>>expr;
	evaluate e;
	e.posteval(expr);
	getch();
}