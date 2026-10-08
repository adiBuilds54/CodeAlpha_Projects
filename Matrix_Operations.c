#include<stdio.h>

void insertion(int n ,int x[n][n] );

void addition(int n,int x[n][n], int y[n][n], int z[n][n]);

void multiplication(int n,int x[n][n], int y[n][n], int z[n][n] );

void display(int n, int z[n][n]);

void insertion(int n, int x[n][n]){
   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&x[i][j]);
        }  
    }
}

void addition(int n,int x[n][n], int y[n][n], int z[n][n] ){
   
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            z[i][j]=x[i][j]+y[i][j];
        }
    }
}

void multiplication(int n,int x[n][n], int y[n][n], int z[n][n] ){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            z[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                z[i][j] = z[i][j] + x[i][k] * y[k][j];
            }
        }
    }
}

void display(int n, int z[n][n]){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",z[i][j]);
        }
        printf("\n"); 
    }

}

void transpose(int n,int x[n][n], int z[n][n]){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            z[i][j]=x[j][i];
        }
    }

}

int main(){
    int n;
    printf("enter the size of martix : ");
    scanf("%d",&n);

    int a[n][n],b[n][n],c[n][n];

    // Matrix A 
    printf("enter the element of matrix A:\n ");
    insertion(n,a);

    // Matric B 
    printf("enter the element of matrix B:\n ");
    insertion(n,b);


    //addition
    addition(n,a,b,c);
    printf("\nAddition of A and B:\n");
    display(n, c);

    // Multiplication
    multiplication(n, a, b, c);
    printf("\nMultiplication of A and B:\n");
    display(n, c);

     // Transpose of A
     transpose(n,a,c);
     printf("Transpose of matrix A:\n");
     display(n, c);
    
     // Transpose of B
     transpose(n,b,c);
    printf("Transpose of matrix B:\n");
     display(n, c);

    return 0;
}
