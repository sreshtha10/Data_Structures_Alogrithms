package com.company;

public class QuickFIndUF {
    private int id[];
    public QuickFIndUF(int N){
        id = new int[N];
        for(int i = 0;i<N;i++){
            id[i] = i;
        }
    }
    public boolean connected(int p,int q){
        return id[p] == id[q];
    }
    public void union(int p, int q){
        int pid = id[p];
        int qid = id[q];
        for(int i = 0;i<id.length;i++){
            if(id[i] == pid){
                id[i]= qid;
            }
        }
    }
    public static void main(String args[]){
        QuickFIndUF a = new QuickFIndUF(10);
        a.union(1,2);
        a.union(2,3);
        System.out.println(a.connected(1,3));
    }
}

//Quick Find defect - Union is too expensive ( quadratic time complexity)
