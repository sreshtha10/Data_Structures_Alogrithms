	public static void insertionSort(int[] arr) {
		for(int i = 1;i<arr.length;i++) {   // i = first unsorted index
			int newElement = arr[i];
			int j;
			for(j =i;j>0 && arr[j-1] > newElement;j--) {
				arr[j] = arr[j-1];
			} 
			arr[j] = newElement;			
		}
	}
