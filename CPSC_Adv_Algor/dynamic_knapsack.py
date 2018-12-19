#!/usr/bin/python
# Algorithms
# HW6
# Myanna Harris and Kristina Spring
# 4-5-17
# Knapsack problem using dynamic programming and memoization
# To run: python3 dynamic_knapsack.py
#
# Answers:
#
# Both grow in O(n)
# Order of items changes chosen answer
# Number of items and max weight affect run time
# Memoization is about 1.5 times as fast
# Both dynamic and memoization output the same solution
#
##What is the maximum amount of weight that can be held? 5
##How many items are there to consider? 4
##Item 0 weight? 2
##Item 0 cost? 12
##Item 1 weight? 1
##Item 1 cost? 10
##Item 2 weight? 3
##Item 2 cost? 20
##Item 3 weight? 2
##Item 3 cost? 15
##
##Weight: 5
##
##Cost: 37
##
##0
##1
##3
##
##Memoization:
##    Time (sec): 9.608268737792969e-05
##    Percentage of table computed (includes zeros in calculation):
##    0.7
##
##Dynamic:
##    Time (sec): 0.00012803077697753906
##
##
##What is the maximum amount of weight that can be held? 10
##How many items are there to consider? 4
##Item 0 weight? 7
##Item 0 cost? 42
##Item 1 weight? 3
##Item 1 cost? 12
##Item 2 weight? 4
##Item 2 cost? 40
##Item 3 weight? 5
##Item 3 cost? 25
##
##Weight: 9
##
##Cost: 65
##
##2
##3
##
##Memoization:
##    Time (sec): 0.00010395050048828125
##    Percentage of table computed (includes zeros in calculation):
##    0.5272727272727272
##
##Dynamic:
##    Time (sec): 0.00019097328186035156
##
##
##What is the maximum amount of weight that can be held? 10
##How many items are there to consider? 4
##Item 0 weight? 4
##Item 0 cost? 40
##Item 1 weight? 7
##Item 1 cost? 42
##Item 2 weight? 5
##Item 2 cost? 25
##Item 3 weight? 3
##Item 3 cost? 12
##
##Weight: 9
##
##Cost: 65
##
##0
##2
##
##Memoization:
##    Time (sec): 0.00010085105895996094
##    Percentage of table computed (includes zeros in calculation):
##    0.4909090909090909
##
##Dynamic:
##    Time (sec): 0.0001800060272216797
##
##
##What is the maximum amount of weight that can be held? 20
##How many items are there to consider? 7
##Item 0 weight? 5
##Item 0 cost? 10
##Item 1 weight? 15
##Item 1 cost? 18
##Item 2 weight? 10
##Item 2 cost? 2
##Item 3 weight? 7
##Item 3 cost? 5
##Item 4 weight? 12
##Item 4 cost? 18
##Item 5 weight? 4
##Item 5 cost? 12
##Item 6 weight? 6
##Item 6 cost? 9
##
##Weight: 15
##
##Cost: 31
##
##0
##5
##6
##
##Memoization:
##    Time (sec): 0.0003170967102050781
##    Percentage of table computed (includes zeros in calculation):
##    0.48214285714285715
##
##Dynamic:
##    Time (sec): 0.0005218982696533203

import time

F = []

# Knapsack using dynamic programming
# F table
def dynamic(itemWeights, itemCosts, maxWeight, numItems):
    # Create variables for tracking optimal packing
    largestCost = 0
    largestWeight = 0
    itemLst = []

    for i in range(0, numItems + 1):
        F.append([])
        for j in range(0, maxWeight + 1):
            F[i].append([])
            
            if i == 0 or j == 0:
                # For putting 0's
                F[i][j].append(0)
            else:
                if j >= itemWeights[i - 1]:
                    # If this item can fit

                    # Without item
                    val1 = F[i-1][j][0]

                    # With item
                    val2 = itemCosts[i - 1] + F[i-1][j-itemWeights[i - 1]][0]

                    # Choose which makes larger value
                    if val1 > val2:
                        F[i][j].append(val1)
                        # Save indices of items used up to this point
                        for x in range(1, len(F[i-1][j])):
                            F[i][j].append(F[i-1][j][x])
                    else:
                        F[i][j].append(val2)
                        # Save indices of items used up to this point
                        for x in range(1, len(F[i-1][j-itemWeights[i - 1]])):
                            F[i][j].append(F[i-1][j-itemWeights[i - 1]][x])
                                
                        F[i][j].append(i - 1)
                else:
                    # Item does not fit
                    # Without item
                    F[i][j].append(F[i-1][j][0])
                    # Save indices of items used up to this point
                    for x in range(1, len(F[i-1][j])):
                            F[i][j].append(F[i-1][j][x])
                    

                # Save info for printing highest cost, weight, and indices
                if F[i][j][0] > largestCost:
                    largestCost = F[i][j][0]
                    largestWeight = j
                    if len(F[i][j]) > 1:
                        itemLst = F[i][j]
                    

    # gets rid of the first item because its is actually the largestCost
    del itemLst[0]
    return (largestCost, largestWeight, itemLst)

# Knapsack using memoization
# F table
def memoization(itemWeights, itemCosts, maxWeight, numItems):
    # Create variables for tracking optimal packing
    largestCost = 0
    largestWeight = 0
    itemLst = []

    # Originally fill matrix with 0's and -1's
    for i in range(0, (numItems + 1)):
        F.append([])
        for j in range(0, (maxWeight + 1)):
            if i == 0 or j == 0:
                F[i].append([0])
            else:
                F[i].append([-1])

    largestCost, largestWeight, itemLst = memoizationHelper(
        numItems, maxWeight, itemWeights, itemCosts)
    
    return (largestCost, largestWeight, itemLst)

# Recursive helper function for memoization
def memoizationHelper(i, j, itemWeights, itemCosts):
    val = 0
    weight = 0
    selected = []

    # Calculate if less than 0
    if F[i][j][0] < 0:
        if j < itemWeights[i - 1]:
            # Item does not fit
            # Without item
            val, weight, selected = memoizationHelper(
                i - 1, j, itemWeights, itemCosts)

        else:
            # Without item
            val1, weight1, selected1 = memoizationHelper(
                i - 1, j, itemWeights, itemCosts)

            # With item
            val2, weight2, selected2 = memoizationHelper(
                    i - 1, j - itemWeights[i - 1], itemWeights, itemCosts)
            
            val2 += itemCosts[i - 1]

            # Take one with largest value
            # Save weight and index info
            if val1 > val2:
                val = val1
                weight = weight1
                selected = selected1
            else:
                val = val2
                weight = weight2
                weight += itemWeights[i - 1]
                selected = selected2
                selected.append(i - 1)

        F[i][j].append(weight)
        F[i][j].extend(selected)

        F[i][j][0] = val

    elif F[i][j][0] > 0:
        # Get weight and indices from previously calculated spot

        # Does NOT change F[i][j]

        weight = F[i][j][1]
        for x in range(2, len(F[i][j])):
            selected.append(F[i][j][x])

    return (F[i][j][0], weight, selected)

def main():
    # Get user input
    algorithm = input("Algorithm? ")
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

    t1 = float(time.time())

    if algorithm == 'd':
        largestCost, largestWeight, itemLst = dynamic(
            itemWeights, itemCosts, maxWeight, numItems)
    else:
        largestCost, largestWeight, itemLst = memoization(
            itemWeights, itemCosts, maxWeight, numItems)

    # Print time
    t2 = float(time.time())
    print("")
    print("Time (sec): " + str(t2-t1))
    print("")

    # Print how much of table was calculated in memoization
    if algorithm != 'd':
        numCalc = 0
        for x in F:
            for y in x:
                if y[0] != -1:
                    numCalc += 1

        print("")
        print("Percentage of table computed (includes zeros in calculation):")
        print(numCalc / ((numItems + 1) * (maxWeight + 1)))
        print("")

    # Print message and zeros if no items fit
    if largestCost == 0:
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
