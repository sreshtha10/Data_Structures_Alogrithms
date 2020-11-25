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

void restoreUp(int arr[],int i){
    int k = arr[i];
    int par = i/2;
    while(k > arr[par]){
        arr[i] = arr[par];
        i = par;
        par = i/2;
    }
    arr[i] = k;
    return;
}

void insert(int arr[],int key,int* p_hsize){
    *(p_hsize) += 1;
    arr[*(p_hsize)] = key;
    restoreUp(arr,*p_hsize);
    return;
}

void restoreDown(int arr[], int i);

void delete(int arr[],int* p_hsize);

int main(void){
    int arr[100];
    int hsize = 0;
    arr[0] = MAX_VAL;
    insert(arr,25,&hsize);
    insert(arr,35,&hsize);
    display(arr,hsize);
    return 0;
}
