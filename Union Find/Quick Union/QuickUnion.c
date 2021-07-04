//Quick Find
#include<stdio.h>
#include<stdlib.h>
int *id = NULL;
int n = 0;
int root(int i){
    while(i != id[i]){
        i = id[i];
    }
    return i;
}
int connected(int p,int q){
    if(root(p) == root(q))
    {
        return 1;
    }
    return 0;
}

void Union(int p,int q){
    int i = root(p);
    int j = root(q);
    id[i] = j;
}



int main(){
    
    printf("Enter the value of n\n");
    scanf("%d",&n);
    id = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++){
        id[i] = i;
    }
    Union(1,2);
    Union(2,3);
    
    if(connected(1,4))
        printf("True");
    else
        printf("False");
    return 0;
}
