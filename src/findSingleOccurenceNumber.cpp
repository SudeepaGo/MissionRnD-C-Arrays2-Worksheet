/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<stdlib.h>

int findSingleOccurenceNumber(int *A, int len) {
	int i,max,j,k;
	if (A == NULL) return -1; //Check for empty array

	max = A[0];

	for (i = 1; i < len; i++) //Find the maximum element in array A
	{ 
		if (A[i]>max)
			max = A[i];
	}

	int *count = (int *)malloc(sizeof(int)*max); //Take an array 'count' to keep track of the count of elements in array 'A'

	for (k = 0; k < max; k++) // Initialize the values of count array
		count[k] = 1;

	for (i = 0; i < len; i++)
	{
		if (count[A[i]-1]!=3)  //Check the count of each element in array A
		{
			for (j = i + 1; j < len; j++)
			{
				if (A[i] == A[j])
					count[A[i]-1]++;
			}
			if (count[A[i] - 1] == 1) //If the element is present only once, then return that element
			{
				return A[i];
				break;
			}
		}
	}

}