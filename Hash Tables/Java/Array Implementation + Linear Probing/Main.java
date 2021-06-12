// array implementation with linear probing



package project0;

class ArrayHashTable{
	private StoredEmployee[] hashTable;
	
	public ArrayHashTable() {
		//default 10 capacity
		hashTable = new StoredEmployee[10];
		
	}
	
	public ArrayHashTable(int capacity) {
		
		hashTable = new StoredEmployee[capacity];
	}
	
	private int hashKey(String key) {
		return key.length()%hashTable.length;
	}
	
	
	public void put(String key, Employee employee) {
		int hashedKey = hashKey(key);
		
		
		
		if(occupied(hashedKey)) {
			int stopIndex = hashedKey;
			
			if(hashedKey == hashTable.length -1) {
				hashedKey = 0;
			}
			else {
				hashedKey ++;
			}
			while(occupied(hashedKey) && hashedKey != stopIndex) {
				hashedKey = (hashedKey +1)% hashTable.length;
				
			}
		}
		
		
		if(occupied(hashedKey)) {
			System.out.println("Not enough space in Hash Table");
		}
		else {
			hashTable[hashedKey] = new StoredEmployee(key, employee);
		}
		
	}
	
	
	public Employee get(String key) {
		int hashedKey = findKey(key);
		if(hashedKey == -1) {
			return null;
		}
		else {
			return hashTable[hashedKey].employee;
		} 
		
	}
	
	
	private int findKey(String key) {
		int hashedKey = hashKey(key);
		
		if(hashTable[hashedKey] != null  && hashTable[hashedKey].key.equals(key)) {
			return hashedKey;
		}
		
		
		int stopIndex = hashedKey;
			
		if(hashedKey == hashTable.length -1) {
			hashedKey = 0;
		}
		else {
			hashedKey ++;
		}
		
		
		
		while(occupied(hashedKey) && hashedKey != stopIndex && !hashTable[hashedKey].key.equals(key)) {
			hashedKey = (hashedKey +1)% hashTable.length;
				
		}
		
		if(hashTable[hashedKey].key.equals(key)) {
			return hashedKey;
		}
		else {
			return -1;
		}
			
	}
	
	
	public void printHashTable() {
		for(int i=0;i<hashTable.length;i++) {
			if(hashTable[i] != null) {
				System.out.println(hashTable[i].employee.getFirstName()+" "+hashTable[i].employee.getLastName()+" "+hashTable[i].employee.getId());
			}
			else {
				System.out.println("empty");
			}
			
		}
	}
	
	
	private boolean occupied(int index) {
		return hashTable[index] != null;
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
		
		
		System.out.println(hashTable.get("Smith"));
		
		
	}
	
}
