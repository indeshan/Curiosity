#include<stdio.h>
#include<conio.h>

void floydWarshall(int weight[10][10], int a[10][10], int vertex);

void main() {
	int vertex, i, j;
	int weight[10][10];
	int a[10][10];
	clrscr();

	//enter weighted matrix
	//999 where no vertex exists
	printf("\nEnter the number of vertices :");
	scanf("%d",&vertex);
	printf("\nEnter the weighted matrix ");
	for(i = 1; i <= vertex; i++) {
		for(j = 1;j <= vertex; j++) {
			printf("\nEnter the value at position %d,%d :", i, j);
			scanf("%d", &weight[i][j]);
		}
	}

	//printing matrix
	printf("\nMatrix is \n");

	for(i = 1;i <= vertex; i++) {
		for(j = 1;j <= vertex; j++) {
			printf("%d", weight[i][j]);
			printf("	");
		}
		printf("\n");
	}

	for(i = 1; i <= vertex; i++) {
		for(j = 1; j <= vertex; j++) {
			a[i][j] = -1;
		}
	}
	floydWarshall(weight, a, vertex);
	getch();
}

void floydWarshall(int weight[10][10], int a[10][10], int vertex) {
	int i, j, k;
	for(k = 1; k <= vertex; k++) {
		for(i = 1; i <= vertex; i++) {
			for(j = 1;j <= vertex; j++) {
				if( weight[i][j] >  weight[i][k] +  weight[k][j]) {
					weight[i][j] = weight[i][k] + weight[k][j];
					a[i][j] = k;
				}
			}
		}
	}
	printf("\n");

	printf("\nCost matrix is \n");

	for(i = 1;i <= vertex; i++) {
		for(j = 1; j <= vertex; j++) {
			printf("%d", weight[i][j]);
			printf(" ");
		}
		printf("\n");
	}

	// Path print
	printf("\nShortest Path.\n");
	for(i = 1; i <= vertex; i++) {
		for(j = 1; j <= vertex; j++) {
			if(a[i][j] == -1) {
				printf("%d - %d: %d - %d\n",i, j, i, j);
			}
			else {
				printf("%d - %d: %d - %d - %d\n",i, j, i, a[i][j], j);
			}
		}
	}
}