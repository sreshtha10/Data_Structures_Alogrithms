package project0;

import java.util.LinkedList;
import java.util.ListIterator;

public class ChainedHashTable {

	private LinkedList<StoredEmployee> hashTable[];
	private int size;
	
	public ChainedHashTable() {
		this.hashTable = new LinkedList[10];
		for(int i=0;i<10;i++) {
			this.hashTable[i] = new LinkedList<StoredEmployee>();
		}
		this.size = 10;
	}
	
	public ChainedHashTable(int size) {
		this.size = size;
		this.hashTable = new LinkedList[size];
		for(int i=0;i<size;i++) {
			this.hashTable[i] = new LinkedList<StoredEmployee>();
		}
		
	}
	
	
	public int getHashTableSize() {
		return this.size;
	}
	
	public int getHashedKey(String key) {
		return Math.abs(key.hashCode()%(this.size-1));
	}
	
	
	public void put(String key,Employee employee) {
		int hashedIndex = getHashedKey(key);
		this.hashTable[hashedIndex].add(new StoredEmployee(key,employee));
		return;
	}
	
	public Employee get(String key) {
		int hashedIndex = getHashedKey(key);
		ListIterator<StoredEmployee> iterator = this.hashTable[hashedIndex].listIterator();
		StoredEmployee employee = null;
		while(iterator.hasNext()) {
			employee = iterator.next();
			if(employee.key.equals(key)) {
				break;
			}
		}
		return employee.employee;		
	}
	
	public Employee remove(String key) {
		int hashedIndex = getHashedKey(key);
		ListIterator<StoredEmployee> iterator = this.hashTable[hashedIndex].listIterator();
		StoredEmployee employee = null;
		while(iterator.hasNext()) {
			employee = iterator.next();
			if(employee.key.equals(key)) {
				break;
			}
		}
		
		if(employee == null || !employee.key.equals(key)) {
			return null;
		}
		else {
			this.hashTable[hashedIndex].remove(employee);
			return employee.employee;
		}
	}
	
	public void printHashTable() {
		for(int i=0;i<this.size;i++) {
			ListIterator<StoredEmployee> iterator = this.hashTable[i].listIterator();
			while(iterator.hasNext()) {
				System.out.print(iterator.next().employee.getFirstName()+" -> ");
			}
			System.out.println();
		}
		return;
	}
}
