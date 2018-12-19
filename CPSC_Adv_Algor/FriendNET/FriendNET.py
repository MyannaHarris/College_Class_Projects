#!/usr/bin/python3
# Algorithms
# Projects
# Myanna Harris and Kristina Spring
# 5-4-17
# FriendNET project
# New social network with friendship ratings
# To run: python FriendNET.py
#
# Answers:
# Features:
#   "Best Friend Chain"
#       Algorithm: Dijkstra's
#   Most popular person
#       Algorithm: Linear traversal that fills a list of lists for each user
#           with the scores other users have given their relationship. Returns
#           the user with the most friends who meets the requirements:
#           more than 3 friends and a median score from other people that
#           is greater than 7.
#   The inputted person's best friends
#       Algorithm: "Depth first" like traversal to check each relationship
#           that the provided user rated higher than a 7. If the other user also
#           rated their relationship with the provided user higher than a 7, the
#           other user is added to the best friends list. Then the next
#           relationship is evaluated.
#
# Names:
##  Aragon
##  Bethel
##  Clerty
##  Dearat
##  Esther
##  Farha
##  Gret
##  Herty
##  Inertia
##  Jess
##  Katy
##  Larry
##  Marty
##  Nora
##  Ophelia
##  Perry
##  Quarty
##  Raster
##  Sreethe
##  Tuler

import sys

# Dictionary from user name to index in graph
userToIdx = {}
# Dictionary from index in graph to user name
idxToUser = {}
# List of lists
# Adjacency matrix representation of graph,
# where p is an index of another person and s is the friendship score
# [ [p, s, p, s],
#   [21, 3, 9, 5],
#   [8, 2, 1, 9]   ]
userGraph = []

# Read file and set up graph adjacency matrix and dictionaries
def readDatabase(argv):
    # File to read
    file = "friendDB.txt"
    
    # Check if a file was given
    if len(argv) > 0:
        file = argv[0]

    try:
        # Read in friendDB.txt
        with open(file, "r") as database:
            for record in database:
                # 0 = Person A
                # 1 = Person B
                # 2 = Strength of relationship from A to B
                relationship = record.split()
                
                # Add Person A to graph and dictionaries if they are new
                if relationship[0] not in userToIdx.keys():
                    userToIdx[relationship[0]] = len(userGraph)
                    idxToUser[len(userGraph)] = relationship[0]
                    userGraph.append([])

                # Add Person B to graph and dictionaries if they are new
                if relationship[1] not in userToIdx.keys():
                    userToIdx[relationship[1]] = len(userGraph)
                    idxToUser[len(userGraph)] = relationship[1]
                    userGraph.append([])

                # Add relationship from Person A to Person B
                # First add Person B, then add the score
                userGraph[userToIdx[relationship[0]]].append(userToIdx[relationship[1]])
                userGraph[userToIdx[relationship[0]]].append(int(relationship[2]))
    except IOError as e:
        print("Error: Social network file not found")
        print("")
        print("Goodbye")
        sys.exit()

# Print options to user and get input
def uiMenu():
    print("")
    print("What do you want to do?")
    print("1 - Check if user exists")
    print("2 - Check connection between users")
    print("3 - Check the most popular user")
    print("4 - Check user's best friends")
    print("5 - Check friendliest chain between two users")
    print("6 - Quit")
    userInput = raw_input("")
    print("")
    return userInput

# Get people on shortest path of dislike so (10 - score)
# Use Dijkstra's
def getFriendliestChain(A, B):
    # vertices left to visit
    vertices = set([i for i in range(len(userGraph))])
    # distance from vertices to source
    dist = [float('inf') for _ in range(len(userGraph))]
    # previous vertex that brought shortest distance from source to vertex
    prev = [None for _ in range(len(userGraph))]
    # id of source, distance from source to source set to 0
    idxA = userToIdx[A]
    dist[idxA] = 0
    # id of destination, where we're trying to get to
    idxB = userToIdx[B]

    #while we have vertices left to visit, get to work
    while len(vertices) > 0:
        
        # Get vertex with the smallest distance in Q
        currVertex = -1
        minDistance = float('inf')
        for i in vertices:
            if dist[i] < minDistance:
                currVertex = i

        # if we've reached the end, get out of here
        if (currVertex == idxB or currVertex == -1):
            vertices.clear()
            

        # otherwise, calculate distances for adjacent vertices
        else:
            for nextVertex in range(0,len(userGraph[currVertex]),2):
                maybeShorter = (10-userGraph[currVertex][nextVertex+1]) + dist[currVertex]
                nextVertexValue = userGraph[currVertex][nextVertex]
                if maybeShorter < dist[nextVertexValue]:
                    dist[nextVertexValue] = maybeShorter
                    prev[nextVertexValue] = currVertex
            #remove currVertex from vertices
            vertices.remove(currVertex)
    
    #if current Vertex is -1, return empty list
    if currVertex == -1:
        return []
    
    #list of vertices on the path
    path = []
    # get path going backwards from B to A
    while prev[currVertex] is not None:
        path.append(currVertex) # add the vertex we're currently on in the path
        currVertex = prev[currVertex]
    path.append(currVertex) # add a, where we started

        
    return path

# Most popular person is based on the user with the highest
#   number of friends who meets the requirements below
#
# Requirements:
#   More than 3 friends
#   Median score is greater than 7
#
# The median score is from the scores from other people
#   rating their relationship with the user
#
# Traverse the entire graph linearly
def getMostPopularUser():
    # setting up ways to keep track of people who consider each user to be a friend
    #     and friend scores for each user
    friendCount = [0 for _ in range(len(userGraph))]
    friendScores = [[] for _ in range(len(userGraph))]

    # Mak reverse adjacency list that shows what other people
    #   gave as a score for the user whose index we are at
    for user in range(len(userGraph)):
        for i in range(0,len(userGraph[user]),2):
            friendIdx = userGraph[user][i]
            friendValue = userGraph[user][i+1]
            friendCount[friendIdx] += 1
            if friendScores[friendIdx] == []:
                friendScores[friendIdx].append(friendValue)
            else:
                j = 0
                while (j<len(friendScores[friendIdx]) and
                            friendScores[friendIdx][j] < friendValue):
                    j += 1
                friendScores[friendIdx].insert(j, friendValue)

    # Find the most popular user
    highestMedian = 0
    highestUser = -1
    for user in range(len(userGraph)):
        if (friendCount[user] > 3):
            numFriends = len(friendScores[user])
            # Make sure median score is above 7 and user has at least 3 friends
            if (numFriends % 2 == 0):
                medianScore = friendScores[user][numFriends/2]
            else:
                medianScore = (friendScores[user][numFriends/2]
                        + friendScores[user][numFriends/2 + 1]) / 2.0
            if medianScore > highestMedian:
                highestMedian = medianScore
                highestUser = user

    # Return the string output
    if (highestUser == -1):
        return "None"
    else:
        return idxToUser[highestUser] + " with median friend score of " + str(highestMedian)

# A user's best friends have to meet 2 requirements:
#   The user rates their relationship higher than a 7
#   The other person also rates their relationship
#       with the user higher than a 7
#
# "Depth first" like traversal
def getUsersBestFriends(userName):
    bestFriends = []
    userIdx = userToIdx[userName]
    
    # Checks each friend of given user
    for possibleFriend in range(0,len(userGraph[userIdx]),2):
        
        #if that friend has a high enough rating, keep checking
        if (userGraph[userIdx][possibleFriend+1] > 7):
            friend = userGraph[userIdx][possibleFriend]
            
            # try to find user in the user's friend's list of friends
            for i in range(0,len(userGraph[friend]),2):
                
                # if the user is there and has a high enough score,
                #     add friend to list of best friends
                if (userIdx == userGraph[friend][i] and userGraph[friend][i+1] > 7):
                    bestFriends.append(friend)
    return bestFriends

# Calculate weight between two users if they are connected
#   else return 0
def getWeight(A, B):
    idxA = userToIdx[A]
    idxB = userToIdx[B]

    for i in range(0, len(userGraph[idxA]), 2):
        if userGraph[idxA][i] == idxB:
            return userGraph[idxA][i + 1]

    return 0

# Run user interface
def ui():
    # Get user input
    userInput = uiMenu()

    while userInput != "6":
        if userInput == "1":
            # Check if user exists
            # Get user
            userName = raw_input("What user? ")
            if userName in userToIdx.keys():
                print(userName + " does exist.")
            else:
                print(userName + " does not exist.")
                
        elif userInput == "2":
            # Check connection between users
            # Get user names
            userNames = raw_input("What users (separated by a space)? ")
            userNames = userNames.split()
            if len(userNames) < 2:
                print("Error: Too few names")
            elif userNames[0] not in userToIdx.keys():
                print("Error: " + userNames[0] + " does not exist")
            elif userNames[1] not in userToIdx.keys():
                print("Error: " + userNames[1] + " does not exist")
            else:
                weight = getWeight(userNames[0], userNames[1])

                if weight == 0:
                    print("There is no connection from " + userNames[0]
                          + " to " + userNames[1])
                else:
                	print("The connection from " + userNames[0] + " to " + 
                		  userNames[1] + " has weight " + str(weight))
            
        elif userInput == "3":
            # Check the most popular user
            userName = getMostPopularUser()
            print("The most popular user is " + userName)
            
        elif userInput == "4":
            # Check user's best friends
            # Get user
            userName = raw_input("What user? ")
            if userName not in userToIdx.keys():
                print(userName + " does not exist.")
            else:
                bestFriends = getUsersBestFriends(userName)
                print("The users best friends are ")
                outputNames = ""
                for i in range(0, len(bestFriends)):
                    if i == len(bestFriends) - 1:
                        outputNames += idxToUser[bestFriends[i]]
                    else:
                        outputNames += idxToUser[bestFriends[i]] + ", "

                print(outputNames)
                
        elif userInput == "5":
            # Check friendliest chain between two users
            # Get user names
            userNames = raw_input("What users (separated by a space)? ")
            userNames = userNames.split()
            if len(userNames) < 2:
                print("Error: Too few names")
            elif userNames[0] not in userToIdx.keys():
                print("Error: " + userNames[0] + " does not exist")
            elif userNames[1] not in userToIdx.keys():
                print("Error: " + userNames[1] + " does not exist")
            else:
                output = getFriendliestChain(userNames[0], userNames[1])

                if len(output) < 1:
                    print("No connection from " + userNames[0] +
                          " to " + userNames[1])
                else:
                    print("The friendliest connection from " + userNames[0] +
                          " to " + userNames[1] + " contains: ")
                    for i in range(len(output)-1, -1, -1):
                        print(idxToUser[output[i]])
                
        else:
            print("")
            print("Unrecognized input")
            print("")

        userInput = uiMenu()

    print("")
    print("Goodbye")

def main(argv):
    # Read in graph from file
    readDatabase(argv)

    # Start user interface
    ui()

if __name__ == '__main__':
    main(sys.argv[1:])
