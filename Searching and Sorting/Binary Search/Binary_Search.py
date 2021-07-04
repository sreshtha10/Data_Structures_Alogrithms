n = 23
arr = [98,99,100,110,150,200,210,280]
low = 0
high = len(arr)-1
def binary_search(n,arr,low,high):
    mid = int((low+high)//2)
    if(n == arr[mid]):
        print('Found')
        return 0
    if(mid == low and mid == high and mid != n):
        print('Not Found')
    elif(n > arr[mid]):
        low = mid+1
        binary_search(n,arr,low,high)
    elif(n <arr[mid]):
        high = mid-1
        binary_search(n,arr,low,high)
    
binary_search(n,arr,low,high)
