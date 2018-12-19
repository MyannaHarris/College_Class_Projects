#!/usr/bin/python
# Algorithms
# HW4
# Myanna Harris and Kristina Spring
# 2-21-17
# Johnson-Trotter
# To run: python johnsonTrotter.py n
# Make permutations from the set of numbers 1 to n
#
# Runtimes:
#   n       Time (sec)
#   1       1.69277191162e-05
#   2       1.8835067749e-05
#   3       3.88622283936e-05
#   4       0.000144004821777
#   5       0.000622987747192
#   6       0.00328183174133
#   7       0.0310311317444
#   8       0.226949930191
#   9       2.12172579765
#   10      24.4009001255
#
# Analysis:
#   The runtime grows at about the rate of n!

import sys
import time

def largestMobile(nums, dirs):
    largestNum = 0
    largestIdx = -1
    for i in range(0, len(nums)):
        if dirs[i] == 0:
            if i > 0 and nums[i] > nums[i-1]:
                if nums[i] > largestNum:
                    largestNum = nums[i]
                    largestIdx = i
        else:
            if i < len(nums) - 1 and nums[i] > nums[i+1]:
                if nums[i] > largestNum:
                    largestNum = nums[i]
                    largestIdx = i
                       
    return largestIdx

def main(argv):
    nums = [i for i in range(1,int(argv[0])+1)]
    # 0 is left
    # 1 is right
    dirs = [0 for i in range(1,int(argv[0])+1)]
    
    permutations = []

    t1 = float(time.time())
    
    if len(nums) < 2:
        permutations.append(nums[:])
    else:
        permutations.append(nums[:])
        k = -1
        k = largestMobile(nums, dirs)
        while k > -1:
            if dirs[k] == 0:
                # swap number values
                temp = nums[k]
                nums[k] = nums[k-1]
                nums[k-1] = temp

                # swap direction values
                temp = dirs[k]
                dirs[k] = dirs[k-1]
                dirs[k-1] = temp

                k -= 1
            else:
                # swap number values
                temp = nums[k]
                nums[k] = nums[k+1]
                nums[k+1] = temp

                # swap direction values
                temp = dirs[k]
                dirs[k] = dirs[k+1]
                dirs[k+1] = temp

                k += 1

            for i in range(0, len(nums)):
                if nums[i] > nums[k]:
                    if dirs[i] == 0:
                        dirs[i] = 1
                    else:
                        dirs[i] = 0
                            
            permutations.append(nums[:])

            k = largestMobile(nums, dirs)
            

    t2 = float(time.time())
    print("Time (sec): " + str(t2-t1))
    print(len(permutations))
    #print(permutations)
        
if __name__ == '__main__':
    main(sys.argv[1:])
