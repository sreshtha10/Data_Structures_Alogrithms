#include<stdio.h>
#include<stdlib.h>
int main(){
    int* arr,row,col;
    printf("Enter the number of rows and columns: \t");
    scanf("%d",&row);scanf("%d",&col);
    arr =(int*)malloc(sizeof(int)*row*col);
    printf("Enter the array\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",(arr+(i*col)+j));
        }
    }
    int max = *(arr+0+0),min = *(arr+0+0);
    for(int i=0;i<row;i++){
        for(int j =0;j<col;j++){
            if(*(arr+i*col+j)>max){
                max = *(arr+i*col+j);
            }
            if(*(arr+i*col+j)<min){
                min = *(arr+i*col+j);
            }
        }
    }
    free(arr);
    printf("Maximum element is: %d\n",max);
    printf("Minimum element is: %d",min);
}
