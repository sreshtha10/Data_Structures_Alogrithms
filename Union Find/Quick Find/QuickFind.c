//Quick Find
#include<stdio.h>
#include<stdlib.h>
int *id = NULL;
int n = 0;
int connected(int p,int q){
    if(id[p] == id[q])
    {
        return 1;
    }
    return 0;
}

void Union(int p,int q){
    int pid,qid;
    pid = *(id+p);
    qid = *(id+q);
    for(int i= 0;i < n;i++){
        if(id[i] == pid)
            id[i] = qid;
    }
}

int main(){
    
    printf("Enter the value of n\n");
    scanf("%d",&n);
    id = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++){
        id[i] = i;
    }
    Union(1,2);
    
    if(connected(1,2))
        printf("True");
    else
        printf("False");
    return 0;
}
