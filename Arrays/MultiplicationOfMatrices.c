// Matrix multiplication
#include<stdio.h>
#include<stdlib.h>
int *arr3;
void multiMatrix(int *arr1,int row1,int col1,int*arr2,int row2,int col2){
    int *arr3 = (int*)malloc(row1*col2*sizeof(int));
    for(int i = 0;i<row1;i++){
        for(int j =0;j<col2;j++){
            *(arr3+i*col2+j)= 0;
            for(int k = 0;k<col1;k++){
                *(arr3+i*col2+j) += *((arr1+i*col1+k))* (*(arr2+k*col2+j));
            }
            printf("%d ",*(arr3+i*col2+j) );
        }
        printf("\n");
    }
    
}
int main(){
    int row1,row2,col1,col2;
    printf("Enter the rows and cols of the Matrix:\n");
    scanf("%d",&row1); scanf("%d",&col1);
    int* arr1=(int*)malloc(row1*col1*sizeof(int));
    printf("Enter the first array\n");
    for(int i = 0;i<row1;i++){
        for(int j = 0;j<col1;j++){
            scanf("%d",arr1+i*col1+j);
        }
    }
    printf("Enter the rows and cols of array\n");
    scanf("%d",&row2); scanf("%d",&col2);
    if(col1 != row2){
        printf("multiplication not possible\n");
        return 0;
    }
    int* arr2=(int*)malloc(row2*col2*sizeof(int));
    printf("Enter the second array\n");
    for(int i = 0;i<row2;i++){
        for(int j = 0;j<col2;j++){
            scanf("%d",arr2+i*col2+j);
            }
        }
    printf("\n");
    multiMatrix(arr1,row1,col1,arr2,row2,col2);
    return 0;
    
}
