package com.company;

public class QuickUnionUF {
    private int id[];
    public QuickUnionUF(int n){
        id= new int[n];
        for(int i= 0;i<n;i++){
            id[i] = i;
        }
    }
    public int root(int r){
        while(r != id[r]){
            r = id[r];
        }
        return r;
    }
    public boolean connected(int p,int q){
        return root(p) == root(q);
    }
    public void union(int p,int q){
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }
    public static void main(String args[]){
        QuickUnionUF a = new QuickUnionUF(5);
        a.union(1,2);
        a.union(4,3);
        a.union(3,2);
        System.out.println(a.connected(1,4));
    }
}
//Defects of Quick Union is Trees can get to tall, therefore find operation will consume more time.
             
