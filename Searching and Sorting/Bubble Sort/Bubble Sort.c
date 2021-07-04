#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int *arr,int n){
    int temp;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n-i-1;j++){
            if(*(arr+j) > *(arr+j+1)){
             temp = *(arr+j);
             *(arr+j) = *(arr+j+1);
             *(arr+j+1) = temp;
            }
        }
    }
}
int main(){
    int n;
    printf("Enter the length of the array\n");
    scanf("%d",&n);
    printf("Enter the array\n");
    int *arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++){
        scanf("%d",arr+i);
    }
    
    bubbleSort(arr,n);
    
    //Printing the sorted array
    for(int i = 0;i<n;i++){
        printf("%d ",*(arr+i));
    }
}
