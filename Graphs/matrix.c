#include <stdio.h>
#include <stdlib.h>
#define n 6

int degree(int A[][],int v,int n){

    int result = 0,i;

    for(i=0;i<n;i++)

        result += A[v][i];

        return result;

}
void main(){
int i;
    int n = 6;

    int A[n][n]={{0,1,0,0,1,0},
    {1,0,1,1,0,0},
    {0,1,0,1,1,1},
    {0,1,1,0,1,0},
    {0,0,1,1,0,1},
    {0,0,1,0,1,0}
    };

    for(int i=0;i<6;i++){
        printf("\ndegree of vertex %d = %d ",i+1,degree(A,i,6));
    }
}
