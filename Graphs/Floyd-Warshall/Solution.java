class Solution {
    public void shortestDistance(int[][] mat) {
        
        //floyd warshall
        //given a0, total [V] iters.
        // at each iteration relax if mat[i,iter]+a[iter,j] < mat[i,j]
        // time - n^3
        //-1 represents infinity
        int start = 0;
        while(start<mat.length){
            
            //iterate over all the edges except start
            for(int i=0;i<mat.length;i++){
                for(int j=0;j<mat[0].length;j++){
                    if(i!=start && j!=start && mat[i][start]!=-1 && mat[start][j]!=-1){
                        //check if relaxation is possible or not
                        if(mat[i][start]+mat[start][j]< mat[i][j] || mat[i][j]==-1){
                            mat[i][j]=mat[i][start]+mat[start][j]; //re;ax
                        }
                    }
                }
                
            }
            start++;
        }
    }
}
