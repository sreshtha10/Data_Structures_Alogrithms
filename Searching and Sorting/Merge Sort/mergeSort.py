def merge(arr,l,r):
    i = j = k = 0
    while i<len(l) and j<len(r):
        if l[i] <= r[j]:
            arr[k] = l[i]
            i+=1 
        else:
            arr[k] = r[j]
            j += 1 
        k+= 1 
    while i<len(l):
        arr[k] = l[i]
        i += 1 
        k += 1 
    while j<len(r):
        arr[k] = r[j]
        j += 1 
        k += 1 
    return arr
    
def mergeSort(arr):
    if len(arr) > 1:
        mid = len(arr)//2
        l = arr[:mid]
        r = arr[mid:]
        mergeSort(l)
        mergeSort(r)
        merge(arr,l,r)
        return arr 
        
        
n = list(map(int,input().strip().split()))
n =mergeSort(n)
print(*n)
