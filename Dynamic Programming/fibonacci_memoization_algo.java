package project0;

import java.util.HashMap;
import java.util.Map;

//memoization in java

class FibonacciMemoization{
	private Map<Integer,Long> memo = new HashMap<>();
	
	public Long fibMemo(int n) {
		if(n<=2) {
			return (long)1;
		}
		if(this.memo.containsKey(n)) {
			return this.memo.get(n);
		}
		
		this.memo.put(n, fibMemo(n-1)+fibMemo(n-2));
		return this.memo.get(n);
	}
}

class Main{
	public static void main(String args[]) {
		FibonacciMemoization fib = new FibonacciMemoization();
		System.out.println(fib.fibMemo(50));
	}
}
