#!/usr/bin/python
# Algorithms
# HW5
# Myanna Harris and Kristina Spring
# 3-5-17
# Comparing Heapsort
# To run: python compareHeapSort.py
# Compare HeapSort to MergeSort
#
# 1) Heap sort has more consistent performance.
# 2) When the size of the data is smaller, they perform similarly.
#       On larger sets of data, heap sort performs the fastest.
#       We think heap sort is faster because it has less overhead
#       since it uses iteration and not recursion. Heap sort does
#       not copy lists multiple times.Heap sort also
#       uses less memory which makes it more efficient overall.
# 3) Heap sort is about 13 times faster at 1,000,000. At 1,000,000,
#       heap sort averages 19 secs and merge sort averages 244 secs.
#       At 500,000 items, heap sort is about 7 times faster.
#       So when n is doubled, the amount of time that heap sort is
#       faster approximately doubles. Heap sort outperforms
#       merge sort by a factor of log(n).

import random
import time

# start merge sort
def mergeSort(arr):
    if len(arr) < 2:
        return arr

    lowLst = []
    hiLst = []
    
    if len(arr) > 2:
        mid = (len(arr) - 0) / 2
        lowLst = arr[:mid]
        hiLst = arr[mid:]

        lowLst = mergeSort(lowLst)
        hiLst = mergeSort(hiLst)
    else:
        lowLst = [arr[0]]
        hiLst = [arr[1]]
        
    return merge(lowLst, hiLst)

# merge sort merging helper
def merge(arr1, arr2):
    newArr = []
    while len(arr1) > 0 and len(arr2) > 0:
        if arr1[0] > arr2[0]:
            newArr.append(arr2[0])
            arr2.pop(0)
        else:
            newArr.append(arr1[0])
            arr1.pop(0)

    while len(arr1) > 0:
        newArr.append(arr1[0])
        arr1.pop(0)

    while len(arr2) > 0:
        newArr.append(arr2[0])
        arr2.pop(0)

    return newArr

# start heap sort
def heapSort(arr):
    heap = []
    for x in arr:
        addToHeap(heap, x)

    newArr = []
    for i in range(0, len(arr)):
        newArr.append(popFromHeap(heap))
    return newArr

# add item to heap
def addToHeap(heap, item):
    heap.append(item)

    if len(heap) > 1:
        child = len(heap) - 1
        if child % 2 != 0:
            parent = (child - 1) / 2
        else:
            parent = (child - 2) / 2

        moving = True
        while moving:
            moving = False
            if parent >= 0 and heap[child] < heap[parent]:
                temp = heap[child]
                heap[child] = heap[parent]
                heap[parent] = temp

                child = parent
                if child > 0:
                    if child % 2 != 0:
                        parent = (child - 1) / 2
                    else:
                        parent = (child - 2) / 2

                    moving = True
                else:
                    moving = False

# Pop smallest off of heap
def popFromHeap(heap):
    item = heap[0]

    curr = 0

    heap[0] = heap[len(heap) - 1]
    heap.pop(len(heap) - 1)

    moving = True
    while moving:
        left = curr * 2 + 1
        right = curr * 2 + 2
        if left >= len(heap) and right >= len(heap):
            moving = False
        elif right >= len(heap) and heap[left] < heap[curr]:
            temp = heap[curr]
            heap[curr] = heap[left]
            heap[left] = temp
            
            curr = left
        elif (right < len(heap) and heap[right] < heap[left]
              and heap[right] < heap[curr]):
            temp = heap[curr]
            heap[curr] = heap[right]
            heap[right] = temp
            
            curr = right
        elif ((right >= len(heap) or heap[left] <= heap[right])
              and heap[left] < heap[curr]):
            temp = heap[curr]
            heap[curr] = heap[left]
            heap[left] = temp
            
            curr = left
        else:
            moving = False

    
    return item

def main():
    # get size of array
    size = raw_input("Number of elements? ")
    print("")
    # loop try multiple times
    for x in range(0, 10):
        # make random array
        inArray = [int(random.random() * 100000) for _ in xrange(int(size))]
        print("")
        #print(inArray)

        t1 = float(time.time())

        h = heapSort(inArray)

        t2 = float(time.time())
        print("Heap sort Time (sec): " + str(t2-t1))
        print("")
        #print(h)

        t1 = float(time.time())

        m = mergeSort(inArray)

        t2 = float(time.time())
        print("Merge sort Time (sec): " + str(t2-t1))
        print("")
        #print(m)
    

if __name__ == '__main__':
    main()
