#peak finding algorithm using 1-D array - Time Complexity O(log(n))

array = list(map(int,input().strip().split()))

def peakfinder(array,low,high):
        mid = (low+high)//2
        if mid >0 and array[mid] < array[mid-1]:
            return peakfinder(array,low,mid-1)
        elif mid < len(array)-1 and array[mid] < array[mid+1] :
            return peakfinder(array,mid+1,high)
        else:
            return mid
            
            
print(peakfinder(array,0,len(array)-1))
