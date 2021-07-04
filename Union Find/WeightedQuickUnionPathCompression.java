package com.company;

public class WeightedQuickUnionPathCompression {


        private int id[],size[];
        public WeightedQuickUnionPathCompression(int n){
            id= new int[n];
            size = new int[n];
            for(int i= 0;i<n;i++) {
                id[i] = i; // Path Compression.
                size[i] = 1;
            }
        }
        public int root(int r){
            while(r != id[r]){
                id[r] = id[id[r]];
                r = id[r];
            }
            return r;
        }
        public boolean connected(int p,int q){
            return root(p) == root(q);
        }
        public void union(int p,int q) {
            int i = root(p);
            int j = root(q);
            if(size[i]> size[j]) { // The root of the smaller tree will be the child of larger tree.
                id[j] = i;
                size[i] += size[j];
            }
            else {
                id[i] = j;
                size[j] += size[i];
            }
        }
        public static void main(String args[]){
            QuickUnionUF a = new QuickUnionUF(5);
            a.union(1,2);
            a.union(1,4);
            a.union(4,3);
            a.union(3,2);
            System.out.println(a.connected(1,4));
        }

    }
//Smaller trees are connected to larger tree making the traversal much shorter and this makes the Weighted Quick Union faster than Quick Union. Time complexity is of order N+M*log*N. where log*N is iterated log function.


