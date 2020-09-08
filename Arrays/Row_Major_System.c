//Row major system in 2-D array  
// This means that in the memory data is arranged row wise.
#include <stdio.h>

int main()
{
    int arr[3][4];
    
    // i denotes the row
    // j denotes the column
    for(int i = 0;i<3;i++){
        for(int j = 0;j<4;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i = 0;i< 3;i++){
        for(int j= 0;j<4;j++){
            printf("%p ",&arr[i][j]);
        }
        printf("\n");
    }
    
    //Printing the addresses in row major system.
    

    return 0;
}
