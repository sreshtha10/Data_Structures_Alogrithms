#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int prime = 1;
    if (n <= 1){
        printf("False");
        return 0;
    }
    else if( n<= 3)
    {
        printf("True");
        return 0;
    }
    if (n%2 == 0 || n%3 == 0){
        prime  = 0;
    }
    for (int i = 5;i<pow(n,0.5);i+=6)
    {
        if(n%i == 0 || n%(i+2) == 0)
        {
            prime  = 0;
        }
    }
    if( prime == 1)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
}
