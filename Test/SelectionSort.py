def selectionSort(arr,size):
    for index in range(size):
        min_index = index
        
        for j in range(index + 1, size):
            if(arr[min_index] > arr[j]):
                min_index = j
                
        arr[index], arr[min_index] = arr[min_index], arr[index]
    
    
    
    
    
    
arr = [2,6,1,7,34,6,13,74,73,23,55,14,5,5]
size = len(arr)

selectionSort(arr,size)
print("Sorted Array: "+str(arr))
