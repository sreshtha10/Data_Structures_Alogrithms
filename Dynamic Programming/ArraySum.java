
class ArraySum{
	
	Map<Integer,Boolean> memo = new HashMap<Integer, Boolean>();
	//brute force
	public boolean checkSum(int totalSum, int[] arr) {
		if(totalSum == 0) {   //if sum = 0, then combination exists
			return true;
		}
		
		if(totalSum < 0) {   //if sum < 0, then it is not possible to calculate the sum
			return false;
		}
		for(int i=0;i<arr.length;i++) {
			if(checkSum(totalSum-arr[i], arr) == true) {
				return true;    // if at least one combination exists our function should return true
			}
		}
		return false;
	}
	
	// memoized function
	public boolean checkSumMemo(int totalSum, int[] arr) {
		if(this.memo.containsKey(totalSum)) {
			return this.memo.get(totalSum);
		}
		
		if(totalSum == 0) {   //if sum = 0, then combination exists
			return true;
		}
		
		if(totalSum < 0) {   //if sum < 0, then it is not possible to calculate the sum
			return false;
		}
		
		for(int i=0;i<arr.length;i++) {
			if(checkSumMemo(totalSum-arr[i], arr) == true) {
				this.memo.put(totalSum-arr[i],true);
				return true;    // if at least one combination exists our function should return true
			}
		}
		this.memo.put(totalSum,false);
		return false;
	}
	
	
	
	
}
class Main{
	public static void main(String args[]) {
		System.out.println((new ArraySum()).checkSumMemo(300, new int[] {7,14}));
	}
}
