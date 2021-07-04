/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int prime = 1;
    for (int i = 2; i < n;i++)
    {
        if (n%i == 0)
        {
            prime = 0;
        }
    }
    
    if(prime == 1)
    {
        printf("True");
    }
    else{
        printf("False");
    }
    return 0;
    
    
}

