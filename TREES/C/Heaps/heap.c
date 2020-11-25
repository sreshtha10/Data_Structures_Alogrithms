#include<stdio.h>
#include<stdlib.h>
#define MAX_VAL 9999  /* this value is stored at the 0th position of the array and all the values in the heap are less than this value.*/

void display(int arr[],int hsize){
    if(hsize == 0){
        printf("Heap is empty\n");
        return;
    }
    int i=1;
    while(i <= hsize){
        printf("%d ",arr[i]);
        i++;
    }
    printf("\n");
    printf("Number of elements in the heap = %d",hsize);
    printf("\n");
    return;
}











int main(void){
    int arr[100];
    int hsize = 0;
    arr[0] = MAX_VAL;
    return 0;
}
