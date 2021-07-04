//HowSum

class HowSum{
	
	//brute force
	
	private Map<Integer,int[]> memo = new HashMap<>();
	
	public int[] howSum(int targetSum,int[] arr){
		if(targetSum == 0) {
			return new int[]{};
		}
		if(targetSum < 0) {
			return null;
		}
		
		for(int i=0;i<arr.length;i++) {
			int remainder = targetSum-arr[i];
			int[] res = howSum(remainder,arr);
			if(res != null) {
				int[] tmp = Arrays.copyOf(res,res.length+1);
				tmp[tmp.length-1] = arr[i]; 
				return tmp;
			}
		}
		return null;
	}
	
	//memoized 

	public int[] howSumMemo(int targetSum,int[] arr){
		if(this.memo.containsKey(targetSum)) {
			return this.memo.get(targetSum);
		}
		if(targetSum == 0) {
			return new int[]{};
		}
		if(targetSum < 0) {
			return null;
		}
		
		for(int i=0;i<arr.length;i++) {
			int remainder = targetSum-arr[i];
			int[] res = howSumMemo(remainder,arr);
			if(res != null) {
				int[] tmp = Arrays.copyOf(res,res.length+1);
				tmp[tmp.length-1] = arr[i];
				this.memo.put(targetSum,tmp);
				return tmp;
			}
		}
		
		this.memo.put(targetSum,null);
		return null;
	}
	
}
class Main{
	public static void main(String args[]) {
		System.out.println(Arrays.toString((new HowSum()).howSum(300,new int[]{5,2,3,4})));
		
	}
}
