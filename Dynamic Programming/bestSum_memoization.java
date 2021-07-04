

class BestSum{
	
	private Map<Integer,int[]> memo = new HashMap<>();
	//brute force
	
	public int[] bestSum(int targetSum,int[] arr) {
		if(targetSum == 0) {
			return new int[] {};
		}
		if(targetSum < 0) {
			return null;
		}
		
		int[] shortestSum = null;
		
		for(int i=0;i<arr.length;i++) {
			int remainder = targetSum -arr[i];
			int[] res = bestSum(remainder,arr);
			if(res != null) {
				int[] tmp = Arrays.copyOf(res, res.length+1);
				tmp[tmp.length-1] = arr[i];
				if( shortestSum == null|| shortestSum.length > tmp.length) {
					shortestSum = tmp;
				}
			}
		}
		return shortestSum;
	}
	
	
	//memoized 
	public int[] bestSumMemo(int targetSum,int[] arr) {
		if(this.memo.containsKey(targetSum)) {
			return this.memo.get(targetSum);
		}
		if(targetSum == 0) {
			return new int[] {};
		}
		if(targetSum < 0) {
			return null;
		}
		
		int[] shortestSum = null;
		
		for(int i=0;i<arr.length;i++) {
			int remainder = targetSum -arr[i];
			int[] res = bestSumMemo(remainder,arr);
			if(res != null) {
				int[] tmp = Arrays.copyOf(res, res.length+1);
				tmp[tmp.length-1] = arr[i];
				if( shortestSum == null|| shortestSum.length > tmp.length) {
					shortestSum = tmp;
				}
			}
		}
		this.memo.put(targetSum, shortestSum);
		return shortestSum;
	}
	
	
}
class Main{
	public static void main(String args[]) {
		System.out.println(Arrays.toString((new BestSum()).bestSumMemo(30,new int[]{5,2,3,4,7})));
		
	}
}
