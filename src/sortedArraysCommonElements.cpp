/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

int areDatesEqual(char *, char *);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i, j;

	if (A == NULL || B == NULL) return NULL; //Return NULL for invalid inputs

	for (i = 0; i < ALen; i++)
	{
		for ( j = 0; j < BLen; j++)
		{
			if (areDatesEqual(A[i].date, B[j].date)) //Check for match in dates of A and B
			{
				return &A[i];  //Return the transaction where date match occurs
				break;
			}
		} 
	}
	return NULL; //Return NULL if no match occurs
}

int areDatesEqual(char *date1, char *date2) {

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
	if (y1 == y2 && m1 == m2 && d1 == d1)
		return 1;
	else return 0;
}