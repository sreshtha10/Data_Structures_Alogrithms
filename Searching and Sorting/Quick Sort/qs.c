#include<stdio.h>
#include<stdlib.h>

void swap(int* a,int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}


int partition(int arr[],int low,int high){
    int i = low;
    int j = high;
    int pivot = arr[low];
    while(i < j){
    do{
        i++;
    }while(arr[i] <= pivot);
    
    do{
        j--;
    }while(arr[j] > pivot);
    if(i < j){
        swap(&arr[i],&arr[j]);
    }
   }
   swap(&arr[low],&arr[j]);
   return j;
}

void quickSort(int arr[],int low, int high){
    if(low < high){
        int j = partition(arr,low,high);
        quickSort(arr,low,j);
        quickSort(arr,j+1,high);
        return;
    }
}


int main(void){
    printf("Enter the size of array\n");
    int n;
    scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(int)*n);
    printf("Enter the array\n");
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    quickSort(arr,0,n);
    printf("Sorted Array\n");
    for(int i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
    return 0;
}
