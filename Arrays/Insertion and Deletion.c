#include<stdio.h>
#include<stdlib.h>
void Insertion(int *arr,int index,int element,int n){
    int temp =  *(arr+index);
    int a;
    realloc(arr,sizeof(int)*(n+1));
    for(int i= index+1;i<n+1;i++)
    {
        a = *(arr+i);
        *(arr+i) = temp;
        temp = a;
    }
    *(arr+index)= element;
    for(int i = 0;i<n+1;i++)
    {
        printf("%d ",*(arr+i));
    }
    free(arr);
}
void Deletion(int *arr,int index,int n)
{
    for(int i = index +1;i<n;i++)
    {
        *(arr+i-1)= *(arr+i);
    }
    realloc(arr,sizeof(int)*(n-1));
    for(int i = 0;i<n-1;i++)
    {
        printf("%d ",*(arr+i));
    }
    free(arr);
}
int main()
{
    //Insertion and Deletion program
    int n;
    printf("Enter the initial size of the array\n");
    scanf("%d",&n);
    int *arr =(int*)malloc(sizeof(int)*n);
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    printf("Enter 1 for Insertion and 2 for Deletion\n");
    int opt;
    scanf("%d",&opt);
    if(opt == 1)
    {
        int index,element;
        printf("Enter the element and index\n");
        scanf("%d %d",&element,&index);
        Insertion(arr,index,element,n);
    }
    else if(opt ==2){
        int index;
        printf("Enter the index\n");
        scanf("%d",&index);
        Deletion(arr,index,n);
    }
    return 0;
    
}
