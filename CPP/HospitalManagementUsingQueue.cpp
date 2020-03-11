/**********************************************************************
	IMPLEMENT PRIORITY QUEUE AND PERFORM THE FOLLOWING OPERATIONS
		1)ADD A PATIENT
		2)SERVE A PATIENT
		3)DISPLAY THE LIST
		4)EXIT
************************************************************************/
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int ID;
	struct node *next;
};

class PriQ
{
	node *q1,*q2,*q3;
	public:
		PriQ()
		{
			q1=q2=q3=NULL;
		}
		void add_patient(int ID,int pri);
		void serve();
		void display();
		node *insert(node *h,int id);
		node *del(node *h);
};

void PriQ::add_patient(int ID,int pri)
{
	if(pri==1)
		q1=insert(q1,ID);
	if(pri==2)
		q2=insert(q2,ID);
	if(pri==3)
		q3=insert(q3,ID);
	cout<<"\nINSERTED \n";
}

node* PriQ::insert(node *h,int id)
{
	node *m,*temp;
	m=new node;
	if(m==NULL)
		cout<<"\nno memory\n";
	m->ID=id;
	m->next=NULL;
	if(h==NULL)
		return m;
	temp=h;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=m;
	return h;
 }

void PriQ::serve()
{
	if(q1!=NULL)
	{
		q1= del(q1);
		return;
	}
	if(q2!=NULL)
	{
		q2= del(q2);
		return;
	}
	if(q3!=NULL)
	{
		q3= del(q3);
		return;
	}
}

node* PriQ::del(node *h)
{
	if(h==NULL)
	{
		cout<<"\nqueue is empty\n";
		getch();
		return h;
	}
	node *temp;
	temp=h;
	h=h->next;
	delete temp;
	return h;
}

void PriQ::display()
{
	node *temp;
	cout<<"patients of 1st priority\n";
	if(q1==NULL)
		cout<<"no patients here\n\n";
	temp=q1;
	while(temp!=NULL)
	{
		cout<<"ID "<<temp->ID<<endl;
		temp=temp->next;
	}
	cout<<"patients of 2nd priority\n";
	if(q2==NULL)
		cout<<"no patients here\n\n";
	temp=q2;
	while(temp!=NULL)
	{
		cout<<"ID "<<temp->ID<<endl;
		temp=temp->next;
	}
	cout<<"patients of 3rd priority\n";
	if(q3==NULL)
		cout<<"no patients here\n\n";
	temp=q3;
	while(temp!=NULL)
	{
		cout<<"ID "<<temp->ID<<endl;
		temp=temp->next;
	}
}

void main()
{
	PriQ a;
	int ch,pri,ID;
	clrscr();
	while(1)
	{
		cout<<"1.Add Patient \n2.Treat \n3.Display\n4.Exit\n";
		cout<<" Option:";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\n\nGive  ID + priority\n";
				cin>>ID>>pri;
				a.add_patient(ID,pri);
				break;
			case 2: a.serve();
				break;
			case 3: a.display();
				break;
			case 4: exit(0);
				break;
		}
	}
	getch();
}