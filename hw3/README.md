# hw3 Palindromes, Inversions, and Binary Reflected Gray Codes
Patrick Houlihan, Tim Goon, Adrian Curless

## palindromecheck.cpp

A C++ program that uses a recursive function to check if a given string is a palindrome. A palindrome is a string that reads the same forward and backwords. (e.g aabacabaa)

## easyinversioncount.cpp

A C++ program that uses a naive O(n^2) algorithm to count the number of inversions in an array of real numbers. An inversion given an array A, is when i < j but A[i] > A[j].
(e.g. [3, 2, 1], inversions: [3,2], [2,1], [3,1])

## fastinversioncount.cpp

A C++ program that has the same function as easyinversioncount.cpp but uses an algorithm that is O(nlog(n))

## graycodesarefun.cpp

A C++ program that finds the binary reflected grey codes of order n. A binary reflected gray code is a sequence of bits that can be used to represent integers. The gray code 
is changed such that to get the code for the next integer only one bit from the previous code needs to be changed. (e.g. 5 - 0111 - > 6 - 0101)

This is done to statisfy the senario where we want to take a picture of every combination of 4 children in the most efficient way possible.

## Part 3 Responses ##
The ABACABA pattern can be found in the action column of the table. The child put into
or taken out of the photo follows this pattern.

I extended part3 to generate the table for any n <= 26. If you set n=26 it will
take a couple minutes to run (about 10 on my machine).

More details on each program can be found in "PalindromesAndGrayCodeCS2223PA-Hint1.pdf".
