//Selection Sort
#include<stdio.h>
#include<stdlib.h>
//Find the minimum element of the array and swap it with the starting index 0. Then find the minimum element in range 1-n and swap the minimum element at 1. In this pattern repeat the process till n-1.
void selectionSort(int *arr,int n){
    int min;
    int tmp;
    for(int i = 0;i<n-1;i++)
    {
        min = i;
        for(int j = i+1;j<n;j++)
        {
            if(*(arr+min) > *(arr+j))
            {
                min = j;
            }
        }
        tmp = *(arr+min);
        *(arr+min) = *(arr+i);
        *(arr+i) = tmp;
    }
}
int main()
{
    int n;
    printf("Enter the size of the array \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array\n");
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,n);
    for(int i = 0;i<n;i++)
    {
        printf("%d ",*(arr+i));
    }
    return 0;
}
