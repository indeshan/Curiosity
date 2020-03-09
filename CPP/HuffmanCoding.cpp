/*
  Huffmun Coding.
*/
#include<stdlib.h>
#include<iostream.h>
#include<string.h>
//structure of tree node
struct treenode {
	float freq;
	char data;
	treenode *node,*right,*left;
};
/*structure of node of linked list*/

struct node {
	treenode *data;
	node *next;
};

node *insert(node *,treenode *);
treenode *create();
void encode();
void decode(treenode*);
int n;
char alphabets[30];
char codes[30][10];
void preorder(treenode *p,int i,char word[]);


int main() {
	int op;char word[10];
	treenode *root=NULL;

	do {
		cout<<"\n\n1)Create expression Tree";
		cout<<"\n\n2)Encode a message";
		cout<<"\n\n3)Decode a message";
		cout<<"\n\n4)Quit";
		cout<<"\n\nEnter u r choice:";
		cin>>op;

		switch(op) {
			case 1:
				n=0;
				root=create();
				cout<<"\nPrefix codes:\n";
				preorder(root,0,word);
				break;
			case 2:
				encode();
				break;
			case 3:
				decode(root);
				break;
		}
	}while(op!=4);
	return 0;
}

void preorder(treenode *p,int i,char word[]) {
	if(p!=NULL) {
		if(p->left==NULL && p->right==NULL) {
			word[i]=0;
			cout<<"\n"<<p->data<<"---"<<word;
			alphabets[n]=p->data;
			strcpy(codes[n++],word);
		}
		word[i]='0';
		preorder(p->left,i+1,word);
		word[i]='1';
		preorder(p->right,i+1,word);
	}
}

treenode *create() {
	treenode *p,*t1,*t2;
	node *head;
	int n,i;
	char x;
	float probability;
	head=NULL;
	cout<<"\nEnter the no. of alphabets:";
	cin>>n;
	for(i=0;i<n;i++) {
		cout<<"\nEnter the alphabets:";
		cin>>x;
		cout<<"\nEnter the frequency:";
		cin>>probability;
		p=new treenode;
		p->left=p->right=NULL;
		p->data=x;
		p->freq=probability;
		head=insert(head,p);
	}

	/*create the final tree by merging of two trees of small weights
	(n-1)merges will be required*/

	for(i=1;i<n;i++) {
		t1=head->data; //first tree
		t2=head->next->data; //second tree
		head=head->next->next; /*remove first 2 trees from linked list*/
		/*merge t1 and t2 with new tree in p */
		p=new treenode;
		p->left=t1;
		p->right=t2;
		p->freq=t1->freq+t2->freq;
		head=insert(head,p);
	}
	return(head->data);
}

node *insert(node *head,treenode *t) {
	node *p,*q;
	p=new node;
	p->data=t;
	p->next=NULL;
	if(head==NULL)
		return(p);
	if(t->freq<head->data->freq) {
		p->next=head;
		return(p);
	}
	q=head;
	while(q->next!=NULL && t->freq>q->next->data->freq)
		q=q->next;
	p->next=q->next;
	q->next=p;
	return(head);
}

void encode() {
	char word[30];
	int i,j;
	cout<<"\nEnter the Message:";
	cin>>word;
	cout<<"\nEncoded message:\n";

	for(j=0;word[j]!='\0';j++) {
		for(i=0;alphabets[i]!='\0';i++) {
			if(word[j]==alphabets[i]) {
				cout<<codes[i];
			}
		}
	}
}

void decode(treenode *p) {
	char word[90];
	int i;
	treenode *q;
	cout<<"\nEnter an Decoded message:";
	cin>>word;
	q=p;
	i=0;
	cout<<"\nDecoded Message=";
	while(word[i]!='\0') {
		if(word[i]=='0')
			q=q->left;
		else
			q=q->right;
		if(q->left==NULL && q->right==NULL) {
			cout<<q->data;
			q=p;
		}
		i++;
	}
}