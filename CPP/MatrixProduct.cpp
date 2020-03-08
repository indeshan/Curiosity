
 /*

  A C++ Program to computes the product of two matrices of size 4x4 using
  Strassen's Algorithm (Improved Divide and Conquer Strategy).

 */

# include<iostream.h>
# include<conio.h>
# include<stdio.h>

int matrix_A[4][4]={0};
int matrix_B[4][4]={0};
int matrix_C[4][4]={0};

void input_matrix_A( );
void input_matrix_B( );
void multiply_matrices( );
void show_matrix_C( );

void add_2x2_matrices(const int [2][2],const int [2][2],int [2][2]);
void subtract_2x2_matrices(const int [2][2],const int [2][2],int [2][2]);
void multiply_2x2_matrices(const int [2][2],const int [2][2],int [2][2]);

int main( ) {
	clrscr( );

	input_matrix_A( );
	input_matrix_B( );
	multiply_matrices( );
	show_matrix_C( );

	getch( );
	return 0;
}

void input_matrix_A( ) {
	cout<<" Enter the values of Matrix-A "<<endl;

	for(int i=0;i<4;i++) {
		cout<<"\n[";
		for(int j=0;j<4;j++) {
			cin>>matrix_A[i][j];
		}
		cout<<"]";
	}
}

void input_matrix_B( ) {
	cout<<" Enter the values of Matrix-B"<<endl;

	for(int i=0;i<4;i++) {
		cout<<"\n[";
		for(int j=0;j<4;j++) {
			cin>>matrix_B[i][j];
		}
		cout<<"]";
	}
}


void add_2x2_matrices(const int a[2][2],const int b[2][2],int c[2][2]) {
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++)
			c[i][j]=(a[i][j]+b[i][j]);
	}
}

void subtract_2x2_matrices(const int a[2][2],const int b[2][2],int c[2][2]) {
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++)
			c[i][j]=(a[i][j]-b[i][j]);
	}
}

void multiply_2x2_matrices(const int a[2][2],const int b[2][2],int c[2][2]) {
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			c[i][j]=0;

			for(int k=0;k<2;k++)
				c[i][j]+=(a[i][k]*b[k][j]);
		}
	}
}

void multiply_matrices( ) {
	int A11[2][2]={0};
	int A12[2][2]={0};
	int A21[2][2]={0};
	int A22[2][2]={0};

	int B11[2][2]={0};
	int B12[2][2]={0};
	int B21[2][2]={0};
	int B22[2][2]={0};

	int C11[2][2]={0};
	int C12[2][2]={0};
	int C21[2][2]={0};
	int C22[2][2]={0};

	int i;
	int j;

	for(i=0;i<2;i++) {
		for(j=0;j<2;j++) {
			A11[i][j]=matrix_A[i][j];
			B11[i][j]=matrix_B[i][j];
		}
	}

	for(i=0;i<2;i++) {
		for(j=2;j<4;j++) {
			A12[i][(j-2)]=matrix_A[i][j];
			B12[i][(j-2)]=matrix_B[i][j];
		}
	}

	for(i=2;i<4;i++) {
		for(j=0;j<2;j++) {
			A21[(i-2)][j]=matrix_A[i][j];
			B21[(i-2)][j]=matrix_B[i][j];
		}
	}

	for(i=2;i<4;i++) {
		for(j=2;j<4;j++) {
			A22[(i-2)][(j-2)]=matrix_A[i][j];
			B22[(i-2)][(j-2)]=matrix_B[i][j];
		}
	}

	int M1[2][2]={0};
	int M2[2][2]={0};
	int M3[2][2]={0};
	int M4[2][2]={0};
	int M5[2][2]={0};
	int M6[2][2]={0};
	int M7[2][2]={0};

	int Temp1[2][2]={0};
	int Temp2[2][2]={0};

	add_2x2_matrices(A11,A22,Temp1);
	add_2x2_matrices(B11,B22,Temp2);
	multiply_2x2_matrices(Temp1,Temp2,M1);


	subtract_2x2_matrices(A12,A22,Temp1);
	add_2x2_matrices(B21,B22,Temp2);
	multiply_2x2_matrices(Temp1,Temp2,M7);


	subtract_2x2_matrices(A21,A11,Temp1);
	add_2x2_matrices(B11,B12,Temp2);
	multiply_2x2_matrices(Temp1,Temp2,M6);

	add_2x2_matrices(A11,A12,Temp1);
	multiply_2x2_matrices(Temp1,B22,M5);

	subtract_2x2_matrices(B12,B22,Temp1);
	multiply_2x2_matrices(A11,Temp1,M3);

	subtract_2x2_matrices(B21,B11,Temp1);
	multiply_2x2_matrices(A22,Temp1,M4);

	add_2x2_matrices(A21,A22,Temp1);
	multiply_2x2_matrices(Temp1,B11,M2);

	add_2x2_matrices(M1,M4,Temp1);
	subtract_2x2_matrices(Temp1,M5,Temp2);
	add_2x2_matrices(Temp2,M7,C11);

	add_2x2_matrices(M3,M5,C12);

	add_2x2_matrices(M2,M4,C21);

	add_2x2_matrices(M1,M3,Temp1);
	add_2x2_matrices(M2,M6,Temp2);
	subtract_2x2_matrices(Temp1,Temp2,C22);


	for(i=0;i<2;i++) {
		for(j=0;j<2;j++)
			matrix_C[i][j]=C11[i][j];
	}

	for(i=0;i<2;i++) {
		for(j=2;j<4;j++)
			matrix_C[i][j]=C12[i][(j-2)];
	}

	for(i=2;i<4;i++) {
		for(j=0;j<2;j++)
			matrix_C[i][j]=C21[(i-2)][j];
	}

	for(i=2;i<4;i++) {
		for(j=2;j<4;j++)
			matrix_C[i][j]=C22[(i-2)][(j-2)];
	}
}

void show_matrix_C() {

	cout<<" Values of Matrix-C"<<endl;

	for(int i=0;i<4;i++) {
		cout<<"\n[";
		for(int j=0;j<4;j++) {
			cout<<matrix_C[i][j];
			cout<<" ";
		}
		cout<<"]";
	}
}