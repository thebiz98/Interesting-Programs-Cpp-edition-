# Interesting-Programs-C-edition-
This repository contains some interesting problems encountered while pursuing problem solving in C++

# closest.cpp - 
This problem accepts n coordinates in the 2-D plane and returns the distance between the pair of closest points among all the given points. The problem needed certain intuition and mathematical foundation, and i had to reference CLRS. Its a problem on Computational Geometry, and solving this was extremely fun and insightful.

# lcs3.cpp - 
This problem determines the length of the longest common subsequence between three given sequences. It implements this using dynamic programmming. The mapping from two subsequences to three subsequences needed a mapping of the logic from a 2-D matrix to a 3-D matrix, which was fun to implement.

# pc.cpp - 
This presents another interesting problem: given an integer and the operations of +1, \*2, and \*3, we need to find the minimum number of operations needed to get to the given integer. We also need to print the integer after every operation, i.e., show how the answer is obtained, in what sequence. This last bit was really challenging.

# partition3.cpp - 
This is by far one of the most challenging problems I have encountered. The problem is to divide the given array into three parts having the same sum, but not necessarily of the same size. The program says if it's possible to divide the array as such or not. The reference for this problem was obtained from the following link : https://youtu.be/qpgqhp_9d1s

# placing_parentheses.cpp - 
This program accepts an arithmetic expression, with only '+', '-' and '\*' operations, and tells you the maximum value that can be obtained by parenthesizing the expression optimally. It solves this problem by implementing a dynamic programming approach.

# check.cpp - 
This program implements checking of code brackets in a string. It checks if all the opening brackets match all the closing brackets. The brackets allowed are '()' , '{}' and '[]'. In case the brackets match up, the programs prints Success, else it prints the index of the last unmatched closing bracket, and if there are no such closing brackets, it prints the index of the first unmatched opening bracket. This is a simplistic feature used in text editors to check code. The solution uses the stack data structure, and uses the STL implementation of a stack in c++.

# check2.cpp - 
This problem also replicates the simplistic feature of bracket matching of text editors, but rather than using inbuilt STL of stack, it uses a custom implementation of a generic stack. Implementing the stack helped me better understand the features of C++ programming like class, structures and template class, and also shows the flexibility of structures. The stack is implemented using a linked list representation.
