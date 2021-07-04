#include<stdio.h>
int binarySearch(int n,int *arr,int low,int high)
{
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(n < arr[mid])
        {
            high = mid -1;
        }
        else if( n > arr[mid])
        {
            low = mid +1;
        }
        else if( n == arr[mid])
        {
            return -1;
        }
    }
    return 1;
}
int main(){
    int n = 301;
    int arr[] = {11,12,33,45,55,110,201,300,400};
    int low = 0,high = 8;
    int result = binarySearch(n,arr,low,high);
    (result == -1)?printf("Found"):printf("Not Found");
}
