// array implementation


package project0;

class ArrayHashTable{
	private Employee[] hashTable;
	
	public ArrayHashTable() {
		//default 10 capacity
		hashTable = new Employee[10];
		
	}
	
	public ArrayHashTable(int capacity) {
		
		hashTable = new Employee[capacity];
	}
	
	private int hashKey(String key) {
		return key.length()%hashTable.length;
	}
	
	
	public void put(String key, Employee employee) {
		int hashedKey = hashKey(key);
		
		if(hashTable[hashedKey] != null) {
			System.out.println("Data already present at " +hashedKey);
			
		}
		
		else {
			hashTable[hashedKey] = employee; 
		}
		
	}
	
	
	public Employee get(String key) {
		return hashTable[hashKey(key)];
	}
	
	
	public void printHashTable() {
		for(int i=0;i<hashTable.length;i++) {
			if(hashTable[i] != null) {
				System.out.println(hashTable[i].getFirstName()+" "+hashTable[i].getLastName()+" "+hashTable[i].getId());
			}
			
		}
	}
	
	
	
}




public class Main{
	public static void main(String args[]) {
	
		Employee janeJones = new Employee("Jane","Jones",1);
		Employee johnDoe = new Employee("John","Doe",2);
		Employee marySmith = new Employee("Mary","Smith",3);
		Employee billEnd = new Employee("Bill","End",4);
		
		
		
		ArrayHashTable hashTable = new ArrayHashTable();
		
		hashTable.put(janeJones.getLastName(),janeJones);
		hashTable.put(johnDoe.getLastName(), johnDoe);
		hashTable.put(marySmith.getLastName(), marySmith);
		hashTable.put(billEnd.getLastName(), billEnd);
		
		
		
		hashTable.printHashTable();
		
		
	}
	
}
