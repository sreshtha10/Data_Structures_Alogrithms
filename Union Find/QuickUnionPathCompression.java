package com.company;

public class QuickUnionPathCompression {
        private int id[];
        public QuickUnionPathCompression(int n){
            id= new int[n];
            for(int i= 0;i<n;i++){
                id[i] = i;
            }
        }
        public int root(int r){
            while(r != id[r]) {
                id[r] = id[id[r]]; // Making a direct connection to the node so that traversal which be much faster.
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
            com.company.QuickUnionUF a = new com.company.QuickUnionUF(5);
            a.union(1,2);
            a.union(4,3);
            a.union(3,2);
            System.out.println(a.connected(1,4));
        }
    }

    //Time complexity of Quick Union with Path compression is N + M*logN


