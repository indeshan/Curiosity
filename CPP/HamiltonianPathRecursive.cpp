/*
	Write a recursive program to check whether Hamiltonian path exists in undirected graph or not. If exists print it.(backtracking)
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int x[20];

void next(int g[10][10],int n ,int k) {
	int i,j;
	while(1) {
		x[k]=(x[k]+1)%(n+1);
		if(x[k]==0)
			return;
		if(g[x[k-1]][x[k]]!=0) {
			for(j=1;j<=k-1;j++) {
				if(x[j]==x[k])
					break;
			}
			if(j==k) {
				if((k<n)||((k==n))&&(g[x[n]][x[1]]))
					return;
			}
		}
	}
}

void hamiltonianPath(int g[10][10],int n,int k) {
	int i;
	while(1) {
		next(g,n,k);
		if(x[k]==0) {
			return;
		}
		if(k==n) {
			printf("\n");
			for(i=1;i<=n;i++) {
				printf("%d",x[i]);
			}
			printf("%d",x[1]);
		}
		else
			hum(g,n,k+1);
	}
}

void main() {
	int i,j,n,g[10][10];
	clrscr();
	printf("\nEnter vertexn:");
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			g[i][j]=0;
			x[i]=0;
		}
	}
	printf("\nEnter matrix\n");
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			scanf("%d",&g[i][j]);
		}
	}
	x[1]=1;
	printf("\nHamiltonian cycle:\n");
	hamiltonianPath(g,n,2);
	getch();
}