/*
	Write a non-recursive program to check whether Hamiltonian path exists in undirected graph or not. If exists print it.(backtracking)
*/

#include<iostream.h>
#include<conio.h>
#define V 5
typedef int bool;
#define true 0
#define false 1
int n;
int x[10];
bool graph1[5][5];
bool s[10];

void HamiltonianPath(int n,int x[],bool graph1[][5]) {
	int i,k;
	bool *s=new bool[n];
	for(i=0;i<n;i++) {
		x[i]=-1;
		s[i]=false;
	}
	s[0]=true;
	x[0]=0;
	k=1;
	while(k>=0) {
		x[k]=x[k]+1;
		while(x[k]<n) {
			if((s[x[k]]) && (graph1[x[k-1]][x[k]]))
				break;
			else
				x[k]=x[k]+1;
		}
		if((x[k]<n) && (k!=(n-1))) {
			s[x[k]]=true;
			k=k+1;
		}
		else if((x[k]<n) && (k==(n-1)) && (graph1[x[k]][x[0]]))
			break;
		else {
			x[k]=-1;
			k=k-1;
			s[x[k]]=false;
		}
	}
	delete []s;
	s=NULL;
}


void main() {
	int i;
	//  bool graph1[][3]={{0,1,1},{1,0,1},{0,0,0}};
	bool graph1[][5] = {{0, 1, 0, 1, 0},
						{1, 0, 1, 1, 1},
						{0, 1, 0, 0, 1},
						{1, 1, 0, 0, 1},
						{0, 1, 1, 1, 0}};
	/*bool graph1[][5] = {{0, 1, 0, 1, 0},
						  {1, 0, 1, 1, 1},
						  {0, 1, 0, 0, 1},
						  {1, 1, 0, 0, 0},
						  {0, 1, 1, 0, 0}};*/
	clrscr();
	HamiltonianPath(V,x,graph1);
	for(i=0;i<V;i++)
		cout<<x[i]<<"";
	getch();
}