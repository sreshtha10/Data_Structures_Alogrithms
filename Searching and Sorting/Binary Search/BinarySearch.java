
public class Main{
    public static int binarySearch(int[] a, int key){
        int low = 0;int high = a.length-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if (key < a[mid]) high = mid-1;
            else if(key > a[mid]) low = mid+1;
            else return mid;
        }
        return -1;
    }
    public static void main(String args[]){
        int a[] = {1,2,4,7,8,9,11,23,55,67,88};
        System.out.println(binarySearch(a,23));
    }
}
