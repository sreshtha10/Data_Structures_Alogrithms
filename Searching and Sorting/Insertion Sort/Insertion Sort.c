//Insertion Sort
#include<stdio.h>
#include<stdlib.h>
void insertionSort(int *arr,int n)
{
    int val,hole;
    for(int i =1;i<n;i++)
    {
        val = *(arr+i);
        hole = i;
        while(hole > 0 && val<*(arr+hole-1))
        {
            *(arr+hole) = *(arr+hole-1);
            hole = hole-1;
        }
        *(arr+hole) = val;
    }
    return;
}
int main(){
    int n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(int)*n);
    printf("Enter the array\n");
    for(int i= 0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    insertionSort(arr,n);
    for(int i = 0;i<n;i++)
    {
        printf("%d ",*(arr+i));
    }
    return 0;
}
