#!/usr/bin/python
# Algorithms
# HW3
# Myanna Harris and Kristina Spring
# 2-4-17
# Knapsack problem
# To run: python knapsackProblem.py
#
# Referenced previous HW in Data Mining

import itertools

def main():
    # Get user input
    maxWeight = input("What is the maximum amount of weight that can be held? ")
    maxWeight = int(maxWeight)
    numItems = input("How many items are there to consider? ")
    numItems = int(numItems)
    itemWeights = []
    itemCosts = []

    # Get all weights and costs
    for i in range(0, numItems):
        itemWeights.append(int(input("Item " + str(i) + " weight? ")))
        itemCosts.append(int(input("Item " + str(i) + " cost? ")))

    # Create variables for tracking optimal packing
    largestCost = 0
    largestWeight = 0
    itemLst = []
    
    # List of indices to get combinations of
    idxs = [x for x in range(0, numItems)]
    
    # Loop through different lengths of combinations
    for i in range(1, numItems):
        # Loop through combinations for each length
        for lst in itertools.combinations(idxs,i):
            # Temp variables 
            currCost = 0
            currWeight = 0
            currItems = []
            k = 0
            # Check for best cost current combination can make
            while currWeight < maxWeight and k < len(lst):
                cost = itemCosts[lst[k]]
                weight = itemWeights[lst[k]]
                currCost += cost
                currWeight += weight
                
                currItems.append(lst[k])
                k += 1
                
            # Check if current combination has higher cost
            #   than previous largest
            if currWeight < maxWeight and currCost > largestCost:
                largestCost = currCost
                largestWeight = currWeight
                itemLst = currItems[:]

    # Print message and zeros if no items fit
    if largestWeight == 0:
        print ("")
        print ("No items can fit")
        print ("")
        print ("Weight: " + str(largestWeight))
        print ("")
        print ("Cost: " + str(largestCost))
        print ("")
    else:
        # Print weight, cost, and indices of optimal packing
        print ("")
        print ("Weight: " + str(largestWeight))
        print ("")
        print ("Cost: " + str(largestCost))
        print ("")
        for item in itemLst:
            print (item)
        print ("")

if __name__ == '__main__':
    main()
