package project0;

import java.util.Map;
import java.util.TreeMap;

public class TreesInJDK {
	public static void main(String args[]) {
		
		// it is a red black tree (bst).
		TreeMap<Integer, String> tree = new TreeMap<>();
		
		tree.put(10, "Sreshtha");
		tree.put(3, "mehrotra");
		
		tree.containsValue("Sreshtha");
		
		for(Map.Entry<Integer, String> e : tree.entrySet()) {
			System.out.println(e.getKey() + " "+e.getValue());
		}
		
		
	}
}
