
//grid traveller problem

class Pair{
	Long start;
	Long end;
	Pair(Long start,Long end){
		this.start = start;
		this.end = end;
	}
}



class GridTraveller{
	private Map<Pair,Long> memo = new HashMap<>();
	
	public Long ways(Pair p) {
		if(p.start == 0 || p.end  ==0) {
			return (long)0;
		}
		if(p.start == 1&& p.end == 1) {
			return (long)1;
		}
		
		if(this.memo.containsKey(p)) {
			return this.memo.get(p);
		}
		
		if(this.memo.containsKey(new Pair(p.end,p.start))) {    //no of paths for (a,b) is same as (b,a)
			return this.memo.get(new Pair(p.end,p.start));
		}
		this.memo.put(p,ways(new Pair(p.start-1,p.end)) + ways(new Pair(p.start,p.end-1)));
		return this.memo.get(p);
	}
	
}
class Main{
	public static void main(String args[]) {
		GridTraveller gt = new GridTraveller();
		System.out.println(gt.ways(new Pair((long)2,(long)3)));
	}
}
