#include <stdio.h>
#include <stdlib.h>

void add(int n,int A[n][n],int B[n][n],int C[n][n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j]=A[i][j]+B[i][j];
}

void sub(int n,int A[n][n],int B[n][n],int C[n][n]){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j]=A[i][j]-B[i][j];
}

void strassen(int n,int A[n][n],int B[n][n],int C[n][n]){
    if(n==1){
        C[0][0]=A[0][0]*B[0][0];
        return;
    }

    int m=n/2;
    int A11[m][m],A12[m][m],A21[m][m],A22[m][m];
    int B11[m][m],B12[m][m],B21[m][m],B22[m][m];
    int P1[m][m],P2[m][m],P3[m][m],P4[m][m];
    int P5[m][m],P6[m][m],P7[m][m];
    int X[m][m],Y[m][m];
    int C11[m][m],C12[m][m],C21[m][m],C22[m][m];

    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++){
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+m];
            A21[i][j]=A[i+m][j];
            A22[i][j]=A[i+m][j+m];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+m];
            B21[i][j]=B[i+m][j];
            B22[i][j]=B[i+m][j+m];
        }

    sub(m,B12,B22,Y);
    strassen(m,A11,Y,P1);

    add(m,A11,A12,X);
    strassen(m,X,B22,P2);

    add(m,A21,A22,X);
    strassen(m,X,B11,P3);

    sub(m,B21,B11,Y);
    strassen(m,A22,Y,P4);

    add(m,A11,A22,X);
    add(m,B11,B22,Y);
    strassen(m,X,Y,P5);

    sub(m,A12,A22,X);
    add(m,B21,B22,Y);
    strassen(m,X,Y,P6);

    sub(m,A11,A21,X);
    add(m,B11,B12,Y);
    strassen(m,X,Y,P7);

    add(m,P5,P4,X);
    sub(m,X,P2,Y);
    add(m,Y,P6,C11);

    add(m,P1,P2,C12);
    add(m,P3,P4,C21);

    add(m,P5,P1,X);
    sub(m,X,P3,Y);
    sub(m,Y,P7,C22);

    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++){
            C[i][j]=C11[i][j];
            C[i][j+m]=C12[i][j];
            C[i+m][j]=C21[i][j];
            C[i+m][j+m]=C22[i][j];
        }
}

int main(){
    int n;

    printf("Enter the size of the square matrix(power of 2): ");
    scanf("%d",&n);

    int A[n][n],B[n][n],C[n][n];

    printf("Enter Matrix A:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&A[i][j]);

    printf("Enter Matrix B:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&B[i][j]);

    strassen(n,A,B,C);

    printf("Result Matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }

    return 0;
}