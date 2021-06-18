// array implementation with chaining

package project0;
   

public class Main{
	public static void main(String args[]) {
	
		Employee janeJones = new Employee("Jane","Jones",1);
		Employee johnDoe = new Employee("John","Doe",2);
		Employee marySmith = new Employee("Mary","Smith",3);
		Employee billEnd = new Employee("Bill","End",4);
		
		ChainedHashTable hashTable = new ChainedHashTable();
		
		hashTable.put(janeJones.getLastName(),janeJones);
		hashTable.put(johnDoe.getLastName(), johnDoe);
		hashTable.put(marySmith.getLastName(), marySmith);
		hashTable.put(billEnd.getLastName(), billEnd);
		
		
		hashTable.printHashTable();
		
		System.out.println(hashTable.get("Smith"));
		System.out.println(hashTable.remove("Jones"));
			
	}
	
}
