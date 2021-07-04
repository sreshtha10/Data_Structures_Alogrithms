package project0;

import java.util.HashMap;
import java.util.Map;

class WordConstructor{
	
	private Map<String,Boolean> memo = new HashMap<>();
	//brute force 
	public  boolean canConstruct(String target,String[] arr) {
		if(target.equals("")) {
			return true;
		}
		for(int i=0;i<arr.length;i++) {
			if(target.indexOf(arr[i]) == 0) {  //to check if the substring is a prefix.
				String suffix = target.substring(arr[i].length());
				if(canConstruct(suffix, arr) == true) {
					return true;
				}
			}
		}
		return false;
	}
	
	//memoized
	public  boolean canConstructMemo(String target,String[] arr) {
		if(this.memo.containsKey(target)) {
			return this.memo.get(target);
		}
		if(target.equals("")) {
			return true;
		}
		for(int i=0;i<arr.length;i++) {
			if(target.indexOf(arr[i]) == 0) {  //to check if the substring is a prefix.
				String suffix = target.substring(arr[i].length());
				
				if(canConstructMemo(suffix, arr) == true) {
					
					this.memo.put(target,true);
					return true;
				}
			}
		}
		
		this.memo.put(target, false);
		return false;
	}
}
class Main{
	public static void main(String args[]) {
		System.out.println((new WordConstructor()).canConstruct("abcdefabababababaabababaabababababababababaabababbabababaababababababa", new String[] {"a","b","ab","cde","f"}));
 	}
}
