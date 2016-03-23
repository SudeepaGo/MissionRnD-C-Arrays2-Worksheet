/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

int isLessThan(char *, char *);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i=0, j=0,k=0;

	if (A==NULL || B==NULL)
	return NULL;

	struct transaction *C = (struct transaction*)malloc(sizeof(struct transaction)*(ALen + BLen));
	
	while (i<ALen && j<BLen) //Comparing the dates in arrays A and B
	{
		if (isLessThan(A[i].date, B[j].date)) //If transaction in A comes first, then place it in array C first
		{
			C[k] = A[i];
			i++;
		}
		else{
			C[k] = B[j]; ////If transaction in B comes first, then place it in array C first
			j++;
		}
		k++;
	}

	if (i >= ALen) //If all the transactions in A are placed already, 
		            //then start placing the transactions of B in C 
	{
		while (j < BLen)
		{
			C[k] = B[j];
			j++; k++;
		}
	}

	if (j >= BLen) //If all the transactions in B are placed already, 
		            //then start placing the transactions of A in C
	{
		while (i < ALen)
		{
			C[k] = A[i];
			i++; k++;
		}
	}

	return C;
}

int isLessThan(char *date1, char *date2) {

	int d1 = 0, d2 = 0, m1 = 0, m2 = 0, y1 = 0, y2 = 0, t, u, i;

	for (i = 0; i < 2; i++) //Finding the day values in dob1 and dob2
	{
		t = date1[i] - '0';
		d1 = t + d1 * 10;
		u = date2[i] - '0';
		d2 = u + d2 * 10;
	}
	for (i = 3; i < 5; i++) // Finding the month values in dob1 and dob2
	{
		t = date1[i] - '0';
		m1 = t + m1 * 10;
		u = date2[i] - '0';
		m2 = u + m2 * 10;
	}
	for (i = 6; i < 10; i++) // Finding the year values in dob1 and dob2
	{
		t = date1[i] - '0';
		y1 = t + y1 * 10;
		u = date2[i] - '0';
		y2 = u + y2 * 10;
	}
	if (y1 <y2) //Comparing the year, month and day values of both dates
		return 1;
	else if (y1 == y2)
	{
		if (m1 < m2) return 1; //Return 1 if date1 comes before date2 or date1 is equal to date2
		else if (m1 == m2)
		{
			if (d1 <= d2) return 1;
			else return 0; //Return 0 if date1 comes after date2
		}
		else return 0;
	}
	else return 0;
}