//column major system in 2-D array  
// This means that in the memory data is arranged column wise.
#include <stdio.h>

int main()
{
    int arr[3][4];
    
    // i denotes the column
    // j denotes the row
    for(int i = 0;i<4;i++){
        for(int j = 0;j<3;j++){
            scanf("%d",&arr[j][i]);
        }
    }
    for(int i = 0;i< 4;i++){
        for(int j= 0;j<3;j++){
            printf("%p ",&arr[j][i]);
        }
        printf("\n");
    }
    
    //Printing the addresses in row major system.
    

    return 0;
}
